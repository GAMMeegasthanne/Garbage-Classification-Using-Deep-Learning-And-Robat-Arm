import os
import time
import cvzone
from cvzone.ClassificationModule import Classifier
import cv2
import  serial



Capturing = True
cap = cv2.VideoCapture(1)
classifier = Classifier('keras_model.h5', 'labels.txt')

# Import bin photos
imgBinsList = []
pathFolderBins = "Bins"
pathList = os.listdir(pathFolderBins)
for path in pathList:
    imgBinsList.append(cv2.imread(os.path.join(pathFolderBins, path), cv2.IMREAD_UNCHANGED))

# Raw class to bin mapping
classDic = {0: None, 1: 1, 2: 2, 3: 3, 4: 0}
# Configure the serial connection
ser = serial.Serial('COM3', 9600)  # Replace 'COM3' with the appropriate serial port
ser.timeout = 1

while True:

    ret, img = cap.read()

    if not ret:
        print("Error: Failed to capture frame from the camera.")
        break

    # Resize the image
    imgResize = cv2.resize(img, (650, 720))

    # Load the background image
    imgBackground = cv2.imread('background.png')

    if imgBackground is None:
        print("Error: Failed to load the background image.")
        break

    predection = classifier.getPrediction(img)
    classID = predection[1]
    print(classID)
    if classID != 0:
        classIDBin = classDic[classID]
        # Print the bin ID
        print(classIDBin)

        if(Capturing == True):
            if classIDBin == 0:
                print("Metal")
                ser.write(b'A')
                time.sleep(0.5)

            elif classIDBin == 1:
                print("Plastic")
                ser.write(b'B')
                time.sleep(0.5)

            elif classIDBin == 2:
                print("Mix")
                ser.write(b'C')
                time.sleep(0.5)

            elif classIDBin == 3:
                print("Organic")
                ser.write(b'D')
                time.sleep(0.5)

        # Print the bin image
        imgBackground = cvzone.overlayPNG(imgBackground, imgBinsList[classIDBin - 1], (895, 374))
        line = ser.readline().decode().strip()
        if line:
            bulbOn = bool(int(line))
            if bulbOn:
                print("Bulb is ON")
            else:
                print("Bulb is OFF")

    time.sleep(3)

    # Add resized image to the background
    imgBackground[0:0 + 720, 0:0 + 650] = imgResize

    # Display the result
    cv2.imshow("Output", imgBackground)
    cv2.waitKey(1)