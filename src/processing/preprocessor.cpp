#include "preprocessor.hpp"

#include <opencv2/opencv.hpp>

cv::Mat Preprocessor::make_gray(const cv::Mat& input_frame) {
    cv::Mat gray;
    cv::cvtColor(input_frame, gray, cv::COLOR_BGR2GRAY);

    return gray;

}

