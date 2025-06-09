import cv2
import numpy as np
import pandas as pd
from ultralytics import YOLO
from tracker import *
import cvzone
import torch
import tkinter as tk
from PIL import Image, ImageTk
import threading
import time
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from datetime import datetime

# Add variables to track time and FPS
frame_count = 0
start_time = time.time()
fps = 0.0  # Initialize fps to 0.0

# Dictionary to store entry time for each person
entry_times = {}
# Dictionary to store dwell time for each person
dwell_times = {}

# Load YOLO model
model = YOLO('yolov8x.pt').to('cuda')

# Load COCO class names
with open("coco.txt", "r") as f:
    class_list = f.read().split("\n")

# Video capture setup
cap = cv2.VideoCapture('videoStream.mp4')

# Tracking setup
tracker = Tracker()
cy1, cy2, offset = 62, 78, 6
roi_points = []  # Stores clicked points for ROI selection
selecting_roi = False  # Tracks if user is selecting ROI
area1 = None  # Will store ROI area dynamically

# Detection counters
personIn, personOut = {}, {}
counterIn, counterOut = [], []
roi_tracker = {}
current_roi_count = set()

# Data storage for visualization
data_storage = {
    'frame_count': [],
    'in_count': [],
    'out_count': [],
    'roi_count': [],
    'timestamp': []  # Add timestamp key here
}

running = False
frame_skip = 10  # Skip every 3rd frame for smoother processing
roi_threshold = 8  # Threshold for warning about crowd density

# Tkinter GUI setup
root = tk.Tk()
root.title("Crowd Monitoring System")
root.geometry("1550x800")
root.resizable(False, False)

# Video display label
video_frame = tk.Frame(root)
video_frame.pack(side="left", padx=10, pady=10)
label = tk.Label(video_frame)
label.pack()

# Frame for stats display
stats_frame = tk.Frame(root)
stats_frame.pack(pady=10)

in_label = tk.Label(stats_frame, text="In: 0", font=("Arial", 14))
in_label.grid(row=0, column=0, padx=20)

out_label = tk.Label(stats_frame, text="Out: 0", font=("Arial", 14))
out_label.grid(row=0, column=1, padx=20)

roi_label = tk.Label(stats_frame, text="In ROI: 0", font=("Arial", 14))
roi_label.grid(row=0, column=2, padx=20)

# Warning label for crowd density
warning_label = tk.Label(root, text="", font=("Arial", 14), fg="red")
warning_label.pack()

normal_label = tk.Label(root, text="", font=("Arial", 14), fg="black")
normal_label.pack()

# Status label
status_label = tk.Label(root, text="Press 'Define ROI' before starting detection", font=("Arial", 12))
status_label.pack()

# total label count
total_label = tk.Label(stats_frame, text="Total: 0", font=("Arial", 14))
total_label.grid(row=1, column=0, columnspan=4, pady=10)

fps_label = tk.Label(stats_frame, text="FPS: 0", font=("Arial", 14))
fps_label.grid(row=2, column=0, columnspan=4, pady=10)

# Frame for Matplotlib Graph
graph_frame = tk.Frame(root)
graph_frame.pack(side="right", padx=10, pady=10)

roi_preview_frame = None

# ---------------------- ROI SELECTION ----------------------
def select_roi(event, x, y, flags, param):
    global roi_points, selecting_roi, roi_preview_frame
    if event == cv2.EVENT_LBUTTONDOWN and selecting_roi:
        if len(roi_points) < 4:
            roi_points.append((x, y))
            print(f"Point {len(roi_points)} selected: {x}, {y}")

            # Redraw the frame with lines
            temp_frame = roi_preview_frame.copy()
            for i in range(len(roi_points) - 1):
                cv2.line(temp_frame, roi_points[i], roi_points[i + 1], (0, 255, 0), 2)

            # Optionally draw a line from last to first if 4 points selected
            if len(roi_points) == 4:
                cv2.line(temp_frame, roi_points[3], roi_points[0], (0, 255, 0), 2)
                selecting_roi = False
                print("ROI selection complete!")
                status_label.config(text="ROI selection complete! You can start detection now.")
                cv2.setMouseCallback("Select ROI", lambda *args: None)  # Disable callback
                define_roi_button.destroy()

            cv2.imshow("Select ROI", temp_frame)

def start_roi_selection():
    global roi_points, selecting_roi, roi_preview_frame
    cap.set(cv2.CAP_PROP_POS_FRAMES, 0)  # Reset video to the first frame
    ret, frame = cap.read()
    if not ret:
        status_label.config(text="Error: Could not load video frame")
        return

    frame = cv2.resize(frame, (900, 500))  # Resize for better visibility
    roi_preview_frame = frame.copy()  # Save copy for drawing
    roi_points = []  # Reset previous ROI points
    selecting_roi = True
    cv2.imshow("Select ROI", roi_preview_frame)
    cv2.setMouseCallback("Select ROI", select_roi)
    status_label.config(text="Click on four points to define the ROI.")

# ---------------------- VideoCaptureThread ----------------------
class VideoCaptureThread(threading.Thread):
    def __init__(self, video_source):
        threading.Thread.__init__(self)
        self.cap = cv2.VideoCapture(video_source)
        self.ret, self.frame = self.cap.read()
        self.running = True

    def run(self):
        """Continuously read frames from the video source."""
        while self.running:
            ret, frame = self.cap.read()
            if ret:
                self.frame = frame  # Store the latest frame
            time.sleep(0.01)  # Sleep to reduce CPU load

    def get_frame(self):
        """Return the current frame."""
        return self.frame

    def stop(self):
        """Stop the video capture thread."""
        self.running = False
        self.cap.release()

# ---------------------- DETECTION ----------------------
def check_threshold(count):
    """Check if ROI count exceeds threshold and update warning label."""
    if count > roi_threshold:
        normal_label.config(text="")
        warning_label.config(text=f"Warning: High crowd density in ROI ({count} people)!")
    else:
        warning_label.config(text="")
        normal_label.config(text=f"Normal crowd density in ROI ({count} people)!")

def start_detection():
    """Start the detection process in a separate thread."""
    global running, area1
    if len(roi_points) != 4:
        status_label.config(text="Please define ROI first!")
        return

    area1 = roi_points  # Store selected ROI
    running = True
    status_label.config(text="Detection Running...")
    thread = threading.Thread(target=detect_objects)
    thread.daemon = True
    thread.start()

def stop_detection():
    """Stop detection."""
    global running
    running = False
    capture_thread.stop()  # Stop the video capture thread
    status_label.config(text="Detection Stopped")

def detect_objects():
    """Perform object detection."""
    global running, frame_count, start_time, fps
    count = 0

    while running:
        frame = capture_thread.get_frame()
        if frame is None:
            continue  # Skip if no frame is available

        count += 1
        if count % frame_skip != 0:
            continue  # Skip frames to optimize performance

        # Calculate FPS every 10 frames
        frame_count += 1
        if frame_count % 10 == 0:  # Calculate FPS every 10 frames
            end_time = time.time()
            fps = frame_count / (end_time - start_time)
            start_time = time.time()  # Reset the start time for the next FPS calculation
            frame_count = 0

        frame = cv2.resize(frame, (900, 500))
        results = model.predict(frame, device='cuda')
        px = pd.DataFrame(results[0].boxes.data.cpu().numpy()).astype("float")
        list_bbox, new_roi_count = [], set()

        total_people = 0  # New line before the loop

        for _, row in px.iterrows():
            x1, y1, x2, y2 = map(int, row[:4])
            d = int(row[5])
            if class_list[d] == "person":
                list_bbox.append([x1, y1, x2, y2])
                total_people += 1  # Increment count for person

        bbox_id = tracker.update(list_bbox)

        current_roi_count = set()  # Ensure the set is initialized before use

        for x3, y3, x4, y4, id in bbox_id:
            cx, cy = (x3 + x4) // 2, (y3 + y4) // 2
            cv2.circle(frame, (cx, cy), 4, (255, 0, 255), -1)
            cv2.rectangle(frame, (x3, y3), (x4, y4), (0, 0, 255), 2)
            cvzone.putTextRect(frame, f'{id}', (x3, y3), 1, 2)

            # Calculate dwell time
            if cv2.pointPolygonTest(np.array(area1, np.int32), (cx, cy), False) >= 0:
                if id not in entry_times:
                    # Record the entry time when the person enters the ROI
                    entry_times[id] = time.time()  # Store the entry timestamp

                dwell_time = time.time() - entry_times[id]
                cvzone.putTextRect(frame, f'{dwell_time:.2f}s', (x3, y3), 1, 2)
            else:
                if id in entry_times:
                    # Calculate dwell time when the person exits the ROI
                    exit_time = time.time()
                    dwell_time = exit_time - entry_times[id]  # Time spent in the ROI
                    dwell_times[id] = dwell_time  # Store the dwell time for the person

                    # Remove entry time once the person exits
                    del entry_times[id]

            if cv2.pointPolygonTest(np.array(area1, np.int32), (cx, cy), False) >= 0:
                new_roi_count.add(id)

            if cy1 < (cy + offset) and cy1 > (cy - offset):
                personIn[id] = (cx, cy)
            if id in personIn and cy2 < (cy + offset) and cy2 > (cy - offset):
                if counterIn.count(id) == 0:
                    counterIn.append(id)

            if cy2 < (cy + offset) and cy2 > (cy - offset):
                personOut[id] = (cx, cy)
            if id in personOut and cy1 < (cy + offset) and cy1 > (cy - offset):
                if counterOut.count(id) == 0:
                    counterOut.append(id)

        current_roi_count = new_roi_count
        roiPersonCount = len(current_roi_count)

        # Draw region lines
        cv2.polylines(frame, [np.array(area1, np.int32)], True, (255, 0, 255), 2)
        cv2.line(frame, (0, cy1), (900, cy1), (0, 255, 255), 2)
        cv2.line(frame, (0, cy2), (900, cy2), (0, 255, 255), 2)

        data_storage['frame_count'].append(count)
        data_storage['in_count'].append(len(counterIn))
        data_storage['out_count'].append(len(counterOut))
        data_storage['roi_count'].append(roiPersonCount)
        data_storage['timestamp'].append(start_time)  # Store the timestamp for each frame

        check_threshold(roiPersonCount)

        img = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        img = Image.fromarray(img)

        # Convert FPS to string and overlay on the frame
        fps_text = f"FPS: {fps:.2f}"
        cv2.putText(frame, fps_text, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2, cv2.LINE_AA)

        # Update FPS in status bar
        fps_label.config(text=f"FPS: {fps:.2f}")

        imgtk = ImageTk.PhotoImage(image=img)
        # Update the Tkinter window with the frame and FPS
        root.after(0, lambda: label.config(image=imgtk))
        label.imgtk = imgtk  # Keep a reference to avoid garbage collection
        label.update_idletasks()

        root.after(0, lambda: in_label.config(text=f"In: {len(counterIn)}"))
        root.after(0, lambda: out_label.config(text=f"Out: {len(counterOut)}"))
        root.after(0, lambda: roi_label.config(text=f"In ROI: {roiPersonCount}"))
        root.after(0, lambda: total_label.config(text=f"Total: {total_people}"))

        # Real-time graph update
        root.after(100, lambda: visualize_data(data_storage))  # Update graph every 100ms

    status_label.config(text="Detection Ended.")
    startDetection_button.destroy()
    stopDetection_button.destroy()
    root.after(0, lambda: visualize_data(data_storage))  # Final call to visualize data once detection ends

# ---------------------- Visualization ----------------------
def visualize_data(data_storage):
    """ Embed the visualization graph into Tkinter """
    for widget in graph_frame.winfo_children():
        widget.destroy()

    # Convert data storage to DataFrame
    df = pd.DataFrame(data_storage)

    # Normalize the timestamp to start from 0 (relative time)
    df['timestamp'] = df['timestamp'] - df['timestamp'].iloc[0]  # Subtract first timestamp to make the start time 0 seconds

    # Plot the data
    fig, axs = plt.subplots(2, 1, figsize=(5, 6), dpi=100)

    # Plot People In and People Out over time
    axs[0].plot(df['timestamp'], df['in_count'], label='People In', color='green')
    axs[0].plot(df['timestamp'], df['out_count'], label='People Out', color='red')
    axs[0].set_title('People In/Out Over Time')
    axs[0].legend()
    axs[0].set_xlabel('Time (seconds)')  # Label the x-axis as seconds

    # Plot People in ROI over time
    axs[1].plot(df['timestamp'], df['roi_count'], label='People in ROI', color='blue')
    axs[1].set_title('People in ROI Over Time')
    axs[1].legend()
    axs[1].set_xlabel('Time (seconds)')  # Label the x-axis as seconds

    plt.tight_layout()
    canvas = FigureCanvasTkAgg(fig, master=graph_frame)
    canvas.get_tk_widget().pack()
    canvas.draw()

# ---------------------- GUI Controls ----------------------
root.protocol("WM_DELETE_WINDOW", root.quit)
define_roi_button = tk.Button(root, text="Define ROI", command=start_roi_selection, width=20, height=2)
define_roi_button.pack(pady=5)
startDetection_button = tk.Button(root, text="Start Detect", command=start_detection, width=20, height=2)
startDetection_button.pack(pady=5)
stopDetection_button = tk.Button(root, text="Stop Detect", command=stop_detection, width=20, height=2)
stopDetection_button.pack(pady=5)

# Start video capture thread
capture_thread = VideoCaptureThread('vidp3.MOV')  # Replace with your video file path
capture_thread.start()

root.mainloop()

