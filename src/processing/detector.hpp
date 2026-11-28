#pragma once

#include <opencv2/opencv.hpp>
#include "../captures/camera.hpp"

class Detector {
public:

    void draw_box(cv::Mat& frame, const cv::Rect& box);
    cv::Point locate_point(cv::Mat& frame);

};
