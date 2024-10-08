
#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <numeric>

using namespace std;
using namespace cv;
using namespace cv::ml;

// Function to load features and labels from CSV
void loadCSV(const string& filename, Mat& features, Mat& labels) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;

    // Skip header line
    getline(file, line);

    vector<float> rowFeatures;
    vector<int> rowLabels;

    while (getline(file, line)) {
        stringstream ss(line);
        string item;

        // Read filename (skip it)
        getline(ss, item, ',');

        // Read label
        int label;
        if (!(getline(ss, item, ',') && istringstream(item) >> label)) {
            cerr << "Error: Could not parse label from line: " << line << endl;
            continue; // Skip this line if label parsing fails
        }
        rowLabels.push_back(label);

        // Read features
        rowFeatures.clear();
        while (getline(ss, item, ',')) {
            try {
                float feature = stof(item);
                rowFeatures.push_back(feature);
            }
            catch (const invalid_argument& e) {
                cerr << "Error: Could not parse feature from line: " << line << endl;
                rowFeatures.clear();
                break; // Skip this line if feature parsing fails
            }
        }

        // Convert rowFeatures to a Mat if it is not empty
        if (!rowFeatures.empty()) {
            Mat row(rowFeatures);
            features.push_back(row.t());
        }
    }

    // Convert labels vector to Mat
    labels = Mat(rowLabels, true).reshape(1, rowLabels.size());
    labels.convertTo(labels, CV_32S); // Ensure labels are in correct format
    features.convertTo(features, CV_32F); // Ensure features are in correct format

    // Debug: Print the size of the features and labels
    cout << "Loaded features: " << features.rows << "x" << features.cols << endl;
    cout << "Loaded labels: " << labels.rows << "x" << labels.cols << endl;
}

// Function to shuffle and split data
void shuffleAndSplit(const Mat& features, const Mat& labels, Mat& trainFeatures, Mat& trainLabels, Mat& testFeatures, Mat& testLabels, float trainRatio) {
    // Create an index vector
    vector<int> indices(features.rows);
    iota(indices.begin(), indices.end(), 0); // Fill with 0, 1, ..., features.rows-1

    // Shuffle indices
    random_device rd;
    mt19937 g(rd());
    shuffle(indices.begin(), indices.end(), g);

    // Split indices
    int trainSize = static_cast<int>(trainRatio * features.rows);

    // Split data
    trainFeatures.create(trainSize, features.cols, features.type());
    trainLabels.create(trainSize, labels.cols, labels.type());
    testFeatures.create(features.rows - trainSize, features.cols, features.type());
    testLabels.create(features.rows - trainSize, labels.cols, labels.type());

    for (int i = 0; i < features.rows; ++i) {
        if (i < trainSize) {
            features.row(indices[i]).copyTo(trainFeatures.row(i));
            labels.row(indices[i]).copyTo(trainLabels.row(i));
        }
        else {
            features.row(indices[i]).copyTo(testFeatures.row(i - trainSize));
            labels.row(indices[i]).copyTo(testLabels.row(i - trainSize));
        }
    }
}


// Function to compute confusion matrix
Mat computeConfusionMatrix(const Mat& y_true, const Mat& y_pred, int num_classes) {
    // Ensure that num_classes is positive and matches the maximum label value
    if (num_classes <= 0) {
        cerr << "Error: Number of classes must be positive." << endl;
        return Mat();
    }

    // Create a confusion matrix initialized to zeros
    Mat confusionMatrix = Mat::zeros(num_classes, num_classes, CV_32S);

    for (int i = 0; i < y_true.rows; ++i) {
        int actual = y_true.at<int>(i, 0);
        int predicted = static_cast<int>(y_pred.at<float>(i, 0));

        // Check if actual and predicted labels are within the range of num_classes
        if (actual >= 0 && actual < num_classes && predicted >= 0 && predicted < num_classes) {
            confusionMatrix.at<int>(actual, predicted)++;
        }
        else {
            cerr << "Warning: Label value out of bounds. Actual: " << actual << ", Predicted: " << predicted << endl;
        }
    }

    return confusionMatrix;
}

void printClassificationReport(const Mat& y_true, const Mat& y_pred, int num_classes) {
    // Compute confusion matrix
    Mat confusionMatrix = computeConfusionMatrix(y_true, y_pred, num_classes);

    // Print confusion matrix
    cout << "Confusion Matrix:" << endl;
    for (int i = 0; i < confusionMatrix.rows; ++i) {
        for (int j = 0; j < confusionMatrix.cols; ++j) {
            cout << confusionMatrix.at<int>(i, j) << " ";
        }
        cout << endl;
    }

    // Compute and print classification report (precision, recall, F1-score)
    vector<double> precision(num_classes, 0.0);
    vector<double> recall(num_classes, 0.0);
    vector<double> f1_score(num_classes, 0.0);
    vector<double> fpr; // False Positive Rate
    vector<double> tpr; // True Positive Rate

    vector<pair<double, int>> scoreLabelPairs;
    for (int i = 0; i < y_true.rows; ++i) {
        scoreLabelPairs.push_back(make_pair(y_pred.at<float>(i, 0), y_true.at<int>(i, 0)));
    }
    sort(scoreLabelPairs.begin(), scoreLabelPairs.end(), [](const pair<double, int>& a, const pair<double, int>& b) {
        return a.first > b.first;
        });
    double prev_fpr = 0.0;
    double prev_tpr = 0.0;
    double auc = 0.0;

    // Collect true positive and false positive counts
    int pos_count = count_if(y_true.begin<int>(), y_true.end<int>(), [](int val) { return val == 1; });
    int neg_count = y_true.rows - pos_count;

    for (int i = 0; i < num_classes; ++i) {
        int tp = confusionMatrix.at<int>(i, i);
        int fp = 0;
        int fn = 0;

        double current_fpr = static_cast<double>(fp) / neg_count;
        double current_tpr = static_cast<double>(tp) / pos_count;

        fpr.push_back(current_fpr); // False Positive Rate
        tpr.push_back(current_tpr); // True Positive Rate

        // Compute area using the trapezoidal rule
        auc += (current_fpr - prev_fpr) * (current_tpr + prev_tpr) / 2.0;

        prev_fpr = current_fpr;
        prev_tpr = current_tpr;

        // Calculate false positives (FP) and false negatives (FN)
        for (int j = 0; j < num_classes; ++j) {
            if (i != j) {
                fp += confusionMatrix.at<int>(j, i);
                fn += confusionMatrix.at<int>(i, j);
            }
        }

        precision[i] = (tp + fp) > 0 ? static_cast<double>(tp) / (tp + fp) : 0.0;
        recall[i] = (tp + fn) > 0 ? static_cast<double>(tp) / (tp + fn) : 0.0;
        f1_score[i] = (precision[i] + recall[i]) > 0 ? 2 * (precision[i] * recall[i]) / (precision[i] + recall[i]) : 0.0;

        // Print classification metrics for each class
        cout << "Class " << i << ":" << endl;
        cout << "  Precision: " << precision[i] << endl;
        cout << "  Recall: " << recall[i] << endl;
        cout << "  F1-score: " << f1_score[i] << endl;
    }
    auc += (1.0 - prev_fpr) * (1.0 + prev_tpr) / 2.0;
    // Print macro-average metrics
    double avg_precision = accumulate(precision.begin(), precision.end(), 0.0) / num_classes;
    double avg_recall = accumulate(recall.begin(), recall.end(), 0.0) / num_classes;
    double avg_f1_score = accumulate(f1_score.begin(), f1_score.end(), 0.0) / num_classes;

    cout << "Macro-Average:" << endl;
    cout << "  Precision: " << avg_precision << endl;
    cout << "  Recall: " << avg_recall << endl;
    cout << "  F1-score: " << avg_f1_score << endl;

    cout << "ROC Curve:" << endl;
    for (size_t i = 0; i < fpr.size(); ++i) {
        cout << "FPR: " << fpr[i] << ", TPR: " << tpr[i] << endl;
    }

    cout << "AUC: " << auc << endl;
}

// Function to print ROC curve
void printROC(const vector<double>& fpr, const vector<double>& tpr) {
    cout << "ROC Curve:" << endl;
    for (size_t i = 0; i < fpr.size(); ++i) {
        cout << "FPR: " << fpr[i] << ", TPR: " << tpr[i] << endl;
    }
}

int main() {
    // Load all data
    Mat allFeatures, allLabels;
    loadCSV("HOGFeatures.csv", allFeatures, allLabels);

    // Shuffle and split data
    Mat trainFeatures, trainLabels, testFeatures, testLabels;
    shuffleAndSplit(allFeatures, allLabels, trainFeatures, trainLabels, testFeatures, testLabels, 0.80f);

    // Define Random Forest parameters
    Ptr<RTrees> randomForest = RTrees::create();
    randomForest->setMaxDepth(10); // Maximum depth of the tree
    randomForest->setMinSampleCount(2); // Minimum number of samples required at a leaf node
    randomForest->setRegressionAccuracy(0); // Regression accuracy: N/A here
    randomForest->setUseSurrogates(false); // Use surrogate splits
    randomForest->setMaxCategories(10); // Maximum number of categories (useful for categorical data)
    randomForest->setPriors(Mat()); // The prior probabilities of the classes
    randomForest->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6)); // Termination criteria

    // Train Random Forest
    randomForest->train(trainFeatures, ROW_SAMPLE, trainLabels);
    randomForest->save("randomForest_modelHOG.yml");

    cout << "Random Forest model trained and saved to randomForest_modelHOG.yml" << endl;

    // Predict and evaluate
    Mat predictions;
    Ptr<RTrees> loadedRandomForest = RTrees::load("randomForest_modelHOG.yml");
    if (loadedRandomForest.empty()) {
        cerr << "Error: Could not load the Random Forest model." << endl;
        return -1;
    }

    loadedRandomForest->predict(testFeatures, predictions);



    // Print classification report
    int num_classes = 58; // Adjust based on your number of classes
    printClassificationReport(testLabels, predictions, num_classes);

    // Calculate accuracy
    int correct = 0;
    for (int i = 0; i < testLabels.rows; ++i) {
        //cout << "Test Label: " << testLabels.at<int>(i, 0) << "   Prediction Label: " << static_cast<int>(predictions.at<float>(i, 0));
        if (testLabels.at<int>(i, 0) == static_cast<int>(predictions.at<float>(i, 0))) {
            ++correct;
        }
    }

    float accuracy = static_cast<float>(correct) / testLabels.rows;
    cout << "Accuracy: " << accuracy * 100 << "%" << endl;

    return 0;
}
