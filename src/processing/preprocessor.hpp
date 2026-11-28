#pragma once

#include <opencv2/opencv.hpp>

class Preprocessor {
public:
    cv::Mat make_gray(const cv::Mat& input_frame);
    cv::Mat make_blur(const cv::Mat& input_frame, cv::Size object_size);
};
