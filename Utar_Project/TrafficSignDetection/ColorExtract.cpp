
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using namespace cv;

// Function to extract color histogram features from an image
void extractColorHistogram(const Mat& image, vector<float>& features) {
    // Convert image to HSV color space
    Mat hsvImage;
    cvtColor(image, hsvImage, COLOR_BGR2HSV);

    // Define histogram parameters
    int histSize[] = { 5, 5, 5 }; // Number of bins for each channel (Hue, Saturation, Value)
    float hRange[] = { 0, 256 }; // Range of values for each channel
    const float* hRangeList[] = { hRange, hRange, hRange }; // Range for each channel

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

int main() {
    // Folder path for images
    string folderPath = "Inputs/Training_Segmented/"; // Replace with your folder path
    vector<string> imageNames;
    glob(folderPath + "*.png", imageNames, true);

    // Open CSV file for writing
    ofstream csvFile("ColorHistogramFeatures.csv");
    if (!csvFile.is_open()) {
        cerr << "Error: Could not open CSV file for writing." << endl;
        return -1;
    }

    // Write CSV header
    csvFile << "filename,label,feature_0,feature_1,...,feature_N" << endl;

    for (const string& imagePath : imageNames) {
        Mat image = imread(imagePath);
        if (image.empty()) {
            cerr << "Error: Could not open or find the image " << imagePath << endl;
            continue;
        }

        vector<float> features;
        extractColorHistogram(image, features);

        // Extract filename from path
        string filename = imagePath.substr(imagePath.find_last_of("/\\") + 1);

        // Extract label from the first 3 digits of the filename
        string labelStr = filename.substr(0, 3); // Extract first 3 characters
        int label = stoi(labelStr); // Convert to integer

        // Write features to CSV
        csvFile << filename << "," << label;
        for (float feature : features) {
            csvFile << "," << feature;
        }
        csvFile << endl;
    }

    csvFile.close();
    cout << "Feature extraction complete and saved to ColorHistogramFeatures.csv" << endl;

    return 0;
}
