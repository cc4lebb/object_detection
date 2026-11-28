#include "preprocessor.hpp"

#include <opencv2/opencv.hpp>

cv::Mat Preprocessor::make_gray(const cv::Mat& input_frame) {
    if (input_frame.empty()) {
        return cv::Mat();
    } 

    cv::Mat gray;
    cv::cvtColor(input_frame, gray, cv::COLOR_BGR2GRAY);

    return gray;

}

cv::Mat Preprocessor::make_blur(const cv::Mat& input_frame, cv::Size object_size){
     if (input_frame.empty()) {
        return cv::Mat();
    }

    cv::Mat blur;

    int width = std::max(1, object_size.width);
    int height = std::max(1, object_size.height);

    if (width % 2 == 0) width += 1;
    if (height % 2 == 0) height += 1;

    cv::GaussianBlur(input_frame, blur, object_size, 0);
    return blur;

}

