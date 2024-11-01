import cv2
import pickle
import cvzone
import numpy as np

#video feed
cap = cv2.VideoCapture('carPark.mp4')

width, height = 107, 48

def checkParakingSpace(imgProcess):
    spaceCounter = 0
    for pos in posList:
        # crop the image of parking space
        x,y = pos
        imgCrop = imgProcess[y:y+height,x:x+width]
        #cv2.imshow(str(x*y),imgCrop)

        # count pixel
        count = cv2.countNonZero(imgCrop)
        cvzone.putTextRect(img,str(count),(x,y+height-3), scale=1.5, thickness=2,offset=0,colorR=(0,0,255))

        if count < 900:
            # change the color to green
            spaceCounter +=1
            color = (0,255,0)
            thickness = 5
        else:
            color=(0,0,255)
            thickness = 2
        cv2.rectangle(img, pos, (pos[0] + width, pos[1] + height), color, thickness)

    #output count
    cvzone.putTextRect(img, f'Free: {spaceCounter}/{len(posList)}', (100,50), scale=3, thickness=5, offset=0, colorR=(0, 200, 0))

with open('carParkPos', 'rb') as f:
    posList = pickle.load(f)

while True:
    #loop the video
    if cap.get(cv2.CAP_PROP_POS_FRAMES) == cap.get(cv2.CAP_PROP_FRAME_COUNT):
        cap.set(cv2.CAP_PROP_POS_FRAMES,0)
    success, img = cap.read()

    #convert image into gray scale
    imgGray = cv2.cvtColor(img,cv2.COLOR_BGRA2GRAY)
    # image blur
    imgBlur = cv2.GaussianBlur(imgGray,(3,3),1)
    # convert into binary image
    imgThreshold = cv2.adaptiveThreshold(imgBlur,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C
                                         ,cv2.THRESH_BINARY_INV,25,16)
    # median blur to remove some noice
    imgMedian = cv2.medianBlur(imgThreshold,5)
    # image dilation
    kernel = np.ones((3,3), np.uint8)
    imgDilate = cv2.dilate(imgMedian,kernel, iterations=1)

    checkParakingSpace(imgDilate)

    cv2.imshow("Image",img)
    cv2.waitKey(10)