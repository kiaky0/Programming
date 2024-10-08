
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
#include "Supp.h"

using namespace cv;
using namespace std;
using namespace cv::ml;
//Global Variable
string windowName;
Mat srcI, redMask, lowerRed, upperRed, blueMask, yellowMask, canvasColor, canvasGray;
Mat blueChannel, greenChannel, redChannel;
char str[256];
Point2i center;
vector<Scalar> colors;
int const MAXfPt = 200;
int t1, t2, t3, t4;
RNG rng(0);
vector<string> imageNames;
String imgPattern("Inputs/Traffic signs/All Signs/*.png");
Ptr<SVM> svmModel = SVM::load("svm_modelHOG.yml");


std::map<int, std::string> labelDescriptions = {
    {0, "Speed limit (5km/h)"},
    {1, "Speed limit (15km/h)"},
    {2, "Speed limit (30km/h)"},
    {3, "Speed limit (40km/h)"},
    {4, "Speed limit (50km/h)"},
    {5, "Speed limit (60km/h)"},
    {6, "Speed limit (70km/h)"},
    {7, "Speed limit (80km/h)"},
    {8, "No go straight or turn left"},
    {9, "No go straight or turn right"},
    {10, "No go straight"},
    {11, "No turn left"},
    {12, "No turn left and right"},
    {13, "No turn right"},
    {14, "No overtaking"},
    {15, "No U-turn"},
    {16, "No vehicle allowed"},
    {17, "No horn allowed"},
    {18, "Speed limit (40km/h)"},
    {19, "Speed limit (50km/h)"},
    {20, "Go straight or turn right"},
    {21, "Go straight"},
    {22, "Turn left ahead"},
    {23, "Turn left and right ahead"},
    {24, "Turn right ahead"},
    {25, "Keep left"},
    {26, "Keep right"},
    {27, "Roundabout"},
    {28, "Only car allowed"},
    {29, "Sound horn sign"},
    {30, "Bicycle lane"},
    {31, "U-turn sign"},
    {32, "Road divides"},
    {33, "Traffic light sign"},
    {34, "Warning sign"},
    {35, "Pedestrian crossing symbol"},
    {36, "Bicycle traffic warning"},
    {37, "School crossing sign"},
    {38, "Sharp bend right"},
    {39, "Sharp bend left"},
    {40, "Steep hill ahead"},
    {41, "Up hill ahead"},
    {42, "Slowing sign"},
    {43, "Right T-junction"},
    {44, "Left T-junction"},
    {45, "Village sign"},
    {46, "Sharp Right Left"},
    {47, "Railway crossing"},
    {48, "Construction ahead"},
    {49, "Multiple turn"},
    {50, "Fence gate"},
    {51, "Car Trolley"},
    {52, "Stop Sign"},
    {53, "No vehicles"},
    {54, "No parking"},
    {55, "No entry"},
    {56, "Give away sign"},
    {57, "Stop for inspection"}
};

void extractHOGFeatures(const Mat& image, vector<float>& features) {
    // Resize the image to save the computing power
    Mat resizedImage;
    Size resizeSize(64, 64); // or whatever size you decide
    resize(image, resizedImage, resizeSize);

    // Convert the resized image to grayscale
    Mat grayImage;
    cvtColor(resizedImage, grayImage, COLOR_BGR2GRAY);

    // Initialize the HOG descriptor
    HOGDescriptor hog(
        Size(64, 64), // Window size should match the resized image size
        Size(16, 16),   // Block size
        Size(8, 8),     // Block stride
        Size(8, 8),     // Cell size
        9               // Number of bins
    );

    // Compute the HOG descriptor for the image
    hog.compute(grayImage, features);
}

//Function identify shape
string identifyingShape(const vector<Point>& contour) {
    double peri = arcLength(contour, true);
    vector<Point> approx;
    approxPolyDP(contour, approx, 0.04 * peri, true); // to approximate the shape of a contour
    if (approx.size() == 3) {
        return "Triangle";
    }
    else if (approx.size() == 4) {
        Rect rect = boundingRect(approx);
        float aspectRatio = (float)rect.width / (float)rect.height;
        return (aspectRatio >= 0.95 && aspectRatio <= 1.05) ? "Square" : "Rectangle";
    }
    else if (approx.size() > 6) {
        return "Circle";
    }
    else {
        return "Unknown";
    }
}

// Function to segment red signs
void segmentRed(const Mat& srcI, const string& imageName, Ptr<SVM>& svmModel) {  // Pass image name to use within the function
    cout << "Performing Red Segmentation..." << endl;

    // Define parameters for visualization
    int const noOfImagePerCol = 2, noOfImagePerRow = 3;
    Mat detailResultWin, win[noOfImagePerRow * noOfImagePerCol], legend[noOfImagePerRow * noOfImagePerCol];
    createWindowPartition(srcI, detailResultWin, win, legend, noOfImagePerCol, noOfImagePerRow);

     //Label legends for visualization
    putText(legend[0], "Original Sign", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[1], "redMask", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[2], "Contours", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[3], "Longest contour", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[4], "Mask", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[5], "Red Sign segmented", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);

    int const noOfImagePerCol2 = 1, noOfImagePerRow2 = 2;
    Mat resultWin, win2[noOfImagePerRow2 * noOfImagePerCol2], legend2[noOfImagePerRow2 * noOfImagePerCol2];
    createWindowPartition(srcI, resultWin, win2, legend2, noOfImagePerCol2, noOfImagePerRow2);

    putText(legend2[0], "Original Sign", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);

    // Copy source image to window slots
    srcI.copyTo(win[0]);
    srcI.copyTo(win2[0]);

    // Preprocess the image
    Mat blurredImage;
    GaussianBlur(srcI, blurredImage, Size(5, 5), 0);

    // Convert to HSV
    Mat hsvImage;
    cvtColor(blurredImage, hsvImage, COLOR_BGR2HSV);

    // Define red color range in HSV
    inRange(hsvImage, Scalar(0, 70, 70), Scalar(10, 255, 255), lowerRed);   // Lower red range
    inRange(hsvImage, Scalar(170, 70, 70), Scalar(180, 255, 255), upperRed); // Upper red range

    // Combine the two red masks
    redMask = lowerRed | upperRed;

    // Apply morphological operations
    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
    morphologyEx(redMask, redMask, MORPH_CLOSE, kernel);
    morphologyEx(redMask, redMask, MORPH_OPEN, kernel);

    // Show result of red color
    cvtColor(redMask, win[1], COLOR_GRAY2BGR);

    // Prepare canvases for drawing
    Mat canvasColor(srcI.size(), CV_8UC3, Scalar(0, 0, 0));
    Mat canvasGray(srcI.size(), CV_8U, Scalar(0));

    // Create canvases for drawing
    canvasColor.create(srcI.rows, srcI.cols, CV_8UC3);
    canvasGray.create(srcI.rows, srcI.cols, CV_8U);
    canvasColor = Scalar(0, 0, 0);

    // Get contours of the red regions
    vector<vector<Point>> contours;
    findContours(redMask, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

    int index = -1, max = 0;

    // Iterate through contours to find the largest one
    for (int j = 0; j < contours.size(); j++) {
        canvasGray = 0;
        if (max < contours[j].size()) {
            max = contours[j].size();
            index = j;
        }
        drawContours(canvasColor, contours, j, colors[j % MAXfPt]);
        drawContours(canvasGray, contours, j, 255);

        Moments M = moments(canvasGray);
        center.x = M.m10 / M.m00;
        center.y = M.m01 / M.m00;

        floodFill(canvasGray, center, 255);
        if (countNonZero(canvasGray) > 20) {
            sprintf_s(str, "Mask %d (area > 20)", j);
            imshow(str, canvasGray);
        }
    }

    // Display the results
    canvasColor.copyTo(win[2]);
    if (index < 0) {
        cout << "No significant contours detected." << endl;
        waitKey(0);
        return;
    }

    canvasGray = 0;
    drawContours(canvasGray, contours, index, 255);
    cvtColor(canvasGray, win[3], COLOR_GRAY2BGR);

    Moments M = moments(canvasGray);
    center.x = M.m10 / M.m00;
    center.y = M.m01 / M.m00;

    floodFill(canvasGray, center, 255);
    cvtColor(canvasGray, canvasGray, COLOR_GRAY2BGR);
    canvasGray.copyTo(win[4]);

    canvasColor = canvasGray & srcI;
    canvasColor.copyTo(win[5]);
    canvasColor.copyTo(win2[1]);

    // Extract features from the segmented red sign 
    Mat features; // Extract your features into this Mat
    vector<float> featureVector;
    extractHOGFeatures(canvasColor, featureVector);

    // Predict the label using the SVM model
    int predictedLabel = svmModel->predict(featureVector);

    // Get the sign description from the map
    std::string labelText = "";
    if (labelDescriptions.find(predictedLabel) != labelDescriptions.end()) {
        labelText += labelDescriptions[predictedLabel];
    }
    else {
        labelText += "Unknown";
    }

    // Display the segmentation results
    string windowName = "Segmentation of " + imageName + " (detail)";
    putText(legend2[1], labelText, Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    imshow(windowName, detailResultWin);
    imshow("Red Traffic Sign", resultWin);

    waitKey(0);
    destroyAllWindows();
}

// Function to segment blue signs
void segmentBlue(const Mat& srcI, const string& imageName, Ptr<SVM>& svmModel) {
    cout << "Performing Yellow Segmentation..." << endl;

    // Define parameters for visualization
    int const noOfImagePerCol = 2, noOfImagePerRow = 3;
    Mat detailResultWin, win[noOfImagePerRow * noOfImagePerCol], legend[noOfImagePerRow * noOfImagePerCol];
    createWindowPartition(srcI, detailResultWin, win, legend, noOfImagePerCol, noOfImagePerRow);

    // Label legends for visualization
    putText(legend[0], "Original Sign", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[1], "blueMask", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[2], "Contours", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[3], "Longest contour", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[4], "Mask", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[5], "Blue Sign segmented", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);

    int const noOfImagePerCol2 = 1, noOfImagePerRow2 = 2;
    Mat resultWin, win2[noOfImagePerRow2 * noOfImagePerCol2], legend2[noOfImagePerRow2 * noOfImagePerCol2];
    createWindowPartition(srcI, resultWin, win2, legend2, noOfImagePerCol2, noOfImagePerRow2);

    putText(legend2[0], "Original Sign", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);

    // Copy source image to window slots
    srcI.copyTo(win[0]);
    srcI.copyTo(win2[0]);

    // Preprocess the image
    Mat blurredImage;
    GaussianBlur(srcI, blurredImage, Size(5, 5), 0);

    // Convert to HSV and use a range of blue colors
    Mat hsvImage;
    cvtColor(srcI, hsvImage, COLOR_BGR2HSV);

    // Define blue color range in HSV
    Scalar lowerBlue(96, 70, 70); // Adjust values as needed
    Scalar upperBlue(130, 255, 255);

    // Create a mask for the blue color range
    Mat blueMask;
    inRange(hsvImage, lowerBlue, upperBlue, blueMask);

    // Show result of blue color
    cvtColor(blueMask, win[1], COLOR_GRAY2BGR);

    // Create canvases for drawing
    canvasColor.create(srcI.rows, srcI.cols, CV_8UC3);
    canvasGray.create(srcI.rows, srcI.cols, CV_8U);
    canvasColor = Scalar(0, 0, 0);

    // Get contours of the blue regions
    vector<vector<Point>> contours;
    findContours(blueMask, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

    int index = -1, max = 0;

    // Iterate through contours to find the largest one

    for (int j = 0; j < contours.size(); j++) {
        canvasGray = 0;
        if (max < contours[j].size()) {
            max = contours[j].size();
            index = j;
        }
        drawContours(canvasColor, contours, j, colors[j % MAXfPt]);
        drawContours(canvasGray, contours, j, 255);

        Moments M = moments(canvasGray);
        center.x = M.m10 / M.m00;
        center.y = M.m01 / M.m00;

        floodFill(canvasGray, center, 255);
        if (countNonZero(canvasGray) > 20) {
            sprintf_s(str, "Mask %d (area > 20)", j);
            imshow(str, canvasGray);
        }
    }


    // Display the results
    canvasColor.copyTo(win[2]);
    if (index < 0) {
        cout << "No significant contours detected." << endl;
        waitKey(0);
        return;
    }

    canvasGray = 0;
    drawContours(canvasGray, contours, index, 255);
    cvtColor(canvasGray, win[3], COLOR_GRAY2BGR);

    Moments M = moments(canvasGray);
    center.x = M.m10 / M.m00;
    center.y = M.m01 / M.m00;

    floodFill(canvasGray, center, 255);
    cvtColor(canvasGray, canvasGray, COLOR_GRAY2BGR);
    canvasGray.copyTo(win[4]);

    canvasColor = canvasGray & srcI;
    canvasColor.copyTo(win[5]);
    canvasColor.copyTo(win2[1]);

    // Extract features from the segmented blue sign 
    Mat features; // Extract your features into this Mat
    vector<float> featureVector;
    extractHOGFeatures(canvasColor, featureVector); 

    // Predict the label using the SVM model
    int predictedLabel = svmModel->predict(featureVector);

    // Get the sign description from the map
    std::string labelText = "";
    if (labelDescriptions.find(predictedLabel) != labelDescriptions.end()) {
        labelText += labelDescriptions[predictedLabel];
    }
    else {
        labelText += "Unknown";
    }

    // Display the segmentation results
    string windowName = "Segmentation of " + imageName + " (detail)";
    putText(legend2[1], labelText, Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    imshow(windowName, detailResultWin);
    imshow("Blue Traffic Sign", resultWin);

    waitKey(0);
    destroyAllWindows();
}


// Function to segment yellow signs
void segmentYellow(const Mat& srcI, const string& imageName, Ptr<SVM>& svmModel) {
    cout << "Performing Yellow Segmentation..." << endl;

    // Define parameters for visualization
    int const noOfImagePerCol = 2, noOfImagePerRow = 3;
    Mat detailResultWin, win[noOfImagePerRow * noOfImagePerCol], legend[noOfImagePerRow * noOfImagePerCol];
    createWindowPartition(srcI, detailResultWin, win, legend, noOfImagePerCol, noOfImagePerRow);

    // Label legends for visualization
    putText(legend[0], "Original Sign", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[1], "yellowMask", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[2], "Contours", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[3], "Longest contour", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[4], "Mask", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[5], "Yellow Sign segmented", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);

    int const noOfImagePerCol2 = 1, noOfImagePerRow2 = 2;
    Mat resultWin, win2[noOfImagePerRow2 * noOfImagePerCol2], legend2[noOfImagePerRow2 * noOfImagePerCol2];
    createWindowPartition(srcI, resultWin, win2, legend2, noOfImagePerCol2, noOfImagePerRow2);

    putText(legend2[0], "Original Sign", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);

    // Copy source image to window slots
    srcI.copyTo(win[0]);
    srcI.copyTo(win2[0]);

    // Preprocess the image
    Mat blurredImage;
    GaussianBlur(srcI, blurredImage, Size(5, 5), 0);

    // Convert to HSV
    Mat hsvImage;
    cvtColor(blurredImage, hsvImage, COLOR_BGR2HSV);

    // Define yellow color range in HSV
    Scalar lowerYellow(10, 40, 40);  // Adjust these values if needed
    Scalar upperYellow(35, 255, 255);

    // Create a mask for the yellow color range
    Mat yellowMask;
    inRange(hsvImage, lowerYellow, upperYellow, yellowMask);

    // Apply morphological operations to clean up the mask
    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
    morphologyEx(yellowMask, yellowMask, MORPH_CLOSE, kernel);
    morphologyEx(yellowMask, yellowMask, MORPH_OPEN, kernel);

    // Check if any yellow area is detected
    if (countNonZero(yellowMask) == 0) {
        cout << "No yellow areas detected in image: " << imageName << endl;
        return; // Exit function if no yellow is detected
    }

    // Show result of yellow color segmentation
    cvtColor(yellowMask, win[1], COLOR_GRAY2BGR);

    // Prepare canvases for drawing
    Mat canvasColor(srcI.size(), CV_8UC3, Scalar(0, 0, 0));
    Mat canvasGray(srcI.size(), CV_8U, Scalar(0));

    // Find contours of the yellow regions
    vector<vector<Point>> contours;
    findContours(yellowMask, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

    int index = -1, max = 0;

    // Iterate through contours to find the largest one
    for (int j = 0; j < contours.size(); j++) {
        canvasGray = Scalar(0);  // Reset canvasGray
        if (max < contours[j].size()) {
            max = contours[j].size();
            index = j;
        }

        drawContours(canvasColor, contours, j, colors[j % MAXfPt]);
        drawContours(canvasGray, contours, j, 255);

        Moments M = moments(canvasGray);
        Point2f center(M.m10 / M.m00, M.m01 / M.m00);

        floodFill(canvasGray, center, 255);
        if (countNonZero(canvasGray) > 20) {
            sprintf_s(str, "Mask %d (area > 20)", j);
            imshow(str, canvasGray);
        }
    }


    // Display the results
    canvasColor.copyTo(win[2]);
    if (index < 0) {
        cout << "No significant contours detected." << endl;
        waitKey(0);
        return;
    }

    canvasGray = Scalar(0);
    drawContours(canvasGray, contours, index, 255);
    cvtColor(canvasGray, win[3], COLOR_GRAY2BGR);

    Moments M = moments(canvasGray);
    Point2f center(M.m10 / M.m00, M.m01 / M.m00);

    floodFill(canvasGray, center, 255);
    cvtColor(canvasGray, canvasGray, COLOR_GRAY2BGR);
    canvasGray.copyTo(win[4]);

    canvasColor = canvasGray & srcI;
    canvasColor.copyTo(win[5]);
    canvasColor.copyTo(win2[1]);

    // Extract features from the segmented yellow sign
    Mat features; // Extract your features into this Mat
    vector<float> featureVector;
    extractHOGFeatures(canvasColor, featureVector);

    // Predict the label using the SVM model
    int predictedLabel = svmModel->predict(featureVector);

    // Get the sign description from the map
    std::string labelText = "";
    if (labelDescriptions.find(predictedLabel) != labelDescriptions.end()) {
        labelText += labelDescriptions[predictedLabel];
    }
    else {
        labelText += "Unknown";
    }

    // Display the segmentation results
    string windowName = "Segmentation of " + imageName + " (detail)";
    putText(legend2[1], labelText, Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    imshow(windowName, detailResultWin);
    imshow("Yellow Traffic Sign", resultWin);

    waitKey(0);
    destroyAllWindows();
}


// Function for shape segmentation
void detectShape(const Mat& srcI, const string& imageName , Ptr<SVM>& svmModel) {
    cout << "Performing Shape Segmentation for " << imageName << "..." << endl;

    Mat clone, grayImage, blurredImage, cannyImage;
    int const noOfImagePerCol = 2, noOfImagePerRow = 4;
    Mat largeWin, win[noOfImagePerRow * noOfImagePerCol], legend[noOfImagePerRow * noOfImagePerCol];
    string shape;

    // Initialize and create windows
    createWindowPartition(srcI, largeWin, win, legend, noOfImagePerCol, noOfImagePerRow);
    srcI.copyTo(win[0]);
    srcI.copyTo(clone); // Properly clone the image

    // Annotate windows
    putText(legend[0], "Original", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[1], "GrayScale", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[2], "BlurredImage", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[3], "CannyImage", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
    putText(legend[5], "Mask", Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);

    // Convert to grayscale and blur
    cvtColor(srcI, grayImage, COLOR_BGR2GRAY);
    GaussianBlur(grayImage, blurredImage, Size(5, 5), 0);
    cvtColor(grayImage, win[1], COLOR_GRAY2BGR);
    cvtColor(blurredImage, win[2], COLOR_GRAY2BGR);

    // Edge detection
    Canny(blurredImage, cannyImage, 60, 150);
    cvtColor(cannyImage, win[3], COLOR_GRAY2BGR);

    // Find contours
    vector<vector<Point>> contours;
    findContours(cannyImage, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // Find the largest contour by area
    double maxArea = 0.0;
    int index = -1; // Initialize if no contour found
    for (int i = 0; i < contours.size(); i++) {
        double area = contourArea(contours[i]);
        if (area > maxArea) {
            maxArea = area;
            index = i;
        }
    }

    // Shape classification
    if (index != -1) {
        const vector<Point>& largestContour = contours[index];
        shape = identifyingShape(largestContour);
        putText(legend[4], "Shape: " + shape, Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);

        // Draw the largest contour and label the shape
        drawContours(srcI, contours, index, Scalar(0, 255, 0), 2);
        srcI.copyTo(win[4]);

        // Mask for the largest contour
        Mat mask = Mat::zeros(clone.size(), CV_8U);
        drawContours(mask, contours, index, Scalar(255), FILLED);
        cvtColor(mask, mask, COLOR_GRAY2BGR);
        mask.copyTo(win[5]);

        // Perform segmentation by applying the mask to the original image
        Mat segmented;
        segmented = mask & clone;

        // Extract features from the segmented yellow sign
        Mat features; // Extract your features into this Mat
        vector<float> featureVector;
        extractHOGFeatures(segmented, featureVector);

        // Predict the label using the SVM model
        int predictedLabel = svmModel->predict(featureVector);

        // Get the sign description from the map
        std::string labelText = "";
        if (labelDescriptions.find(predictedLabel) != labelDescriptions.end()) {
            labelText += labelDescriptions[predictedLabel];
        }
        else {
            labelText += "Unknown";
        }

        // Display the segmented shape
        segmented.copyTo(win[6]);
        putText(legend[6], labelText, Point(5, 11), 1, 1, Scalar(250, 250, 250), 1);
        imshow("Window", largeWin);
        waitKey(0);
    }
    else {
        cout << "No contours found in image: " << imageName << "!" << endl;
    }
}

// Function to find the dominant color in the image
string findDominantColor(const Mat& srcI) {
    Mat hsvImage, equalizedHSVImage;

    // Preprocess the image
    Mat blurredImage;
    GaussianBlur(srcI, blurredImage, Size(5, 5), 0);

    // Convert to HSV
    cvtColor(blurredImage, hsvImage, COLOR_BGR2HSV);

    // Perform histogram equalization on the V channel
    vector<Mat> hsvChannels;
    split(hsvImage, hsvChannels);

    Mat V = hsvChannels[2]; // V channel
    Mat equalizedV;

    // Apply histogram equalization to the V channel
    equalizeHist(V, equalizedV);

    // Merge back the H, S, and equalized V channels
    hsvChannels[2] = equalizedV;
    merge(hsvChannels, equalizedHSVImage);

    // Masks for each color
    Mat redMask, blueMask, yellowMask;
    inRange(equalizedHSVImage, Scalar(0, 70, 70), Scalar(10, 255, 255), redMask);   // Lower red
    inRange(equalizedHSVImage, Scalar(170, 70, 70), Scalar(180, 255, 255), redMask |= redMask); // Upper red

    inRange(equalizedHSVImage, Scalar(100, 150, 0), Scalar(140, 255, 255), blueMask); // Blue range

    inRange(equalizedHSVImage, Scalar(15, 100, 100), Scalar(35, 255, 255), yellowMask); // Yellow range

    // Calculate the number of non-zero pixels for each mask
    int redCount = countNonZero(redMask);
    int blueCount = countNonZero(blueMask);
    int yellowCount = countNonZero(yellowMask);

    // Determine the dominant color
    if (redCount > blueCount && redCount > yellowCount) return "red";
    if (blueCount > redCount && blueCount > yellowCount) return "blue";
    if (yellowCount > redCount && yellowCount > blueCount) return "yellow";

    return "none"; // No dominant color
}

int main(int argc, char** argv) {
    cv::glob(imgPattern, imageNames, true);

    for (int i = 0; i < MAXfPt; i++) {
        for (;;) {
            t1 = rng.uniform(0, 255); // blue
            t2 = rng.uniform(0, 255); // green
            t3 = rng.uniform(0, 255); // red
            t4 = t1 + t2 + t3;
            if (t4 > 255) break;
        }
        colors.push_back(Scalar(t1, t2, t3));
    }

    for (size_t i = 0; i < imageNames.size(); ++i) {
        Mat srcI = imread(imageNames[i]);
        if (srcI.empty()) {
            cout << "Cannot open image for reading" << endl;
            return -1;
        }

        // Resize the image for better visualization
        resize(srcI, srcI, Size(200, 200));

        // Find the dominant color in the image
        string dominantColor = findDominantColor(srcI);

        // Call the appropriate segmentation function based on the dominant color
        if (dominantColor == "red") {
            segmentRed(srcI, imageNames[i], svmModel); // Call with SVM model
        }
        else if (dominantColor == "blue") {
            segmentBlue(srcI, imageNames[i], svmModel); // Call with SVM model
        }
        else if (dominantColor == "yellow") {
            segmentYellow(srcI, imageNames[i], svmModel); // Call with SVM model
        }
        else {
            detectShape(srcI, imageNames[i], svmModel); // If no dominant color, use shape detection
        }


        waitKey(0);
        destroyAllWindows();
    }

    return 0;
}
