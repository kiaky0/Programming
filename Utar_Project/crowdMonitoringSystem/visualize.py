import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

from main import graph_frame


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
