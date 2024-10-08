#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
using namespace cv;
using namespace cv::ml;

// Function to extract color histogram features from an image
void extractColorHistogram(const Mat& image, vector<float>& features) {
    // Convert image to HSV color space
    Mat hsvImage;
    cvtColor(image, hsvImage, COLOR_BGR2HSV);

    // Define histogram parameters
    int histSize[] = { 5, 5, 5 }; // Number of bins for each channel (Hue, Saturation, Value)
    float hRange[] = { 0, 180 };  // Range for Hue
    float sRange[] = { 0, 256 };  // Range for Saturation
    float vRange[] = { 0, 256 };  // Range for Value
    const float* hRangeList[] = { hRange, sRange, vRange }; // Range for each channel

    // Compute histograms for HSV channels
    Mat hist;
    int channels[] = { 0, 1, 2 }; // Channels for Hue, Saturation, Value
    calcHist(&hsvImage, 1, channels, Mat(), hist, 3, histSize, hRangeList, true, false);

    // Normalize the histogram
    hist.convertTo(hist, CV_32F); // Ensure histogram is in float format
    normalize(hist, hist, 0, 1, NORM_MINMAX, -1, Mat());

    // Flatten the histogram to a vector of features
    features.clear();
    int binCount = histSize[0] * histSize[1] * histSize[2];
    features.resize(binCount);

    // Access histogram data correctly
    for (int i = 0; i < histSize[0]; ++i) {
        for (int j = 0; j < histSize[1]; ++j) {
            for (int k = 0; k < histSize[2]; ++k) {
                int idx = i + histSize[0] * (j + k * histSize[1]);
                features[idx] = hist.at<float>(i, j, k);
            }
        }
    }
}

// Function to extract HOG features from an image
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

// Function to extract label from image filename
int extractLabelFromFilename(const string& filepath) {
    // Get the filename from the full path
    size_t lastSlash = filepath.find_last_of("/\\");
    string filename = filepath.substr(lastSlash + 1);

    // Ensure filename has enough characters for label extraction
    if (filename.size() < 3) {
        cerr << "Error: Filename too short to extract label: " << filename << endl;
        return -1; // Return an invalid label or handle appropriately
    }

    // Extract the first three digits as the label
    return stoi(filename.substr(0, 3)); // Adjust based on your naming convention
}

// Function to load images from a directory and extract features
void loadTestImages(const string& folderPath, vector<string>& filenames, Mat& features, Mat& labels) {
    vector<String> imagePaths;
    glob(folderPath + "*.png", imagePaths, false); // Load all .png files in the folder

    if (imagePaths.empty()) {
        cerr << "Error: No images found in the directory: " << folderPath << endl;
        return;
    }

    for (const auto& imagePath : imagePaths) {
        Mat image = imread(imagePath);
        if (image.empty()) {
            cerr << "Error: Could not load image " << imagePath << endl;
            continue;
        }

        vector<float> featureVector;
        extractHOGFeatures(image, featureVector);
        //extractColorHistogram(image, featureVector);

        // Convert vector to a Mat row and add to features matrix
        Mat featureMat(1, static_cast<int>(featureVector.size()), CV_32F, featureVector.data());
        features.push_back(featureMat);
        filenames.push_back(imagePath);

        // Extract the label from the filename
        int label = extractLabelFromFilename(imagePath);
        if (label != -1) { // Check if label extraction was successful
            labels.push_back(label);
        }
    }
}

int main() {
    // Load the trained SVM model
    Ptr<SVM> loadedSVM = SVM::load("svm_modelHOG.yml");

    // Load test images and extract features
    Mat testFeatures, testLabels;
    vector<string> filenames;
    loadTestImages("Inputs/Segmented/", filenames, testFeatures, testLabels);

    // Ensure test features are of type CV_32F
    testFeatures.convertTo(testFeatures, CV_32F);

    // Predict the labels for each test image
    Mat predictions;
    loadedSVM->predict(testFeatures, predictions);

    // Evaluate and display the results
    int correct = 0;
    for (int i = 0; i < testLabels.rows; ++i) {
        int trueLabel = testLabels.at<int>(i, 0);
        int predictedLabel = static_cast<int>(predictions.at<float>(i, 0));
        cout << "Image: " << filenames[i] << " | True Label: " << trueLabel
            << " | Predicted Label: " << predictedLabel << endl;

        if (trueLabel == predictedLabel) {
            correct = correct +1;
        }
    }

    float accuracy = static_cast<float>(correct) / testLabels.rows;
    cout << "\nTotal Segmented Images :  " << testLabels.rows << "    Corrected Classification : " << correct << endl;
    cout << "Accuracy: " << accuracy * 100 << "%" << endl << endl;

    float Raccuracy = static_cast<float>(correct) / 84;
    cout << "Total Images failed for segmentation:  " << 84 - testLabels.rows << endl;
    cout << "Total Images : 84 " << "    Corrected Classification : " << correct << endl;
    cout << "The Real Accuracy: " << Raccuracy * 100 << "%" << endl;

    return 0;
}
