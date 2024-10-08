
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using namespace cv;

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

int main() {
    // Folder path for images
    string folderPath = "Inputs/Training_Segmented/"; // Replace with your folder path
    vector<string> imageNames;
    glob(folderPath + "*.png", imageNames, true);

    if (imageNames.empty()) {
        cerr << "Error: No images found in the directory: " << folderPath << endl;
        return -1;
    }

    // Open CSV file for writing
    ofstream csvFile("HOGFeatures.csv");
    if (!csvFile.is_open()) {
        cerr << "Error: Could not open CSV file for writing." << endl;
        return -1;
    }

    // Extract features for the first image to determine the number of features
    Mat firstImage = imread(imageNames[0]);
    if (firstImage.empty()) {
        cerr << "Error: Could not open or find the first image " << imageNames[0] << endl;
        return -1;
    }

    vector<float> sampleFeatures;
    extractHOGFeatures(firstImage, sampleFeatures);

    // Write CSV header dynamically based on the number of features
    csvFile << "filename,label";
    for (int i = 0; i < sampleFeatures.size(); ++i) {
        csvFile << ",feature_" << i;
    }
    csvFile << endl;

    // Process all images in the directory
    for (const string& imagePath : imageNames) {
        Mat image = imread(imagePath);
        if (image.empty()) {
            cerr << "Error: Could not open or find the image " << imagePath << endl;
            continue;
        }

        vector<float> features;
        extractHOGFeatures(image, features);

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
    cout << "Feature extraction complete and saved to HOGFeatures.csv" << endl;

    return 0;
}
