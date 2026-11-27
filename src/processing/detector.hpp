#pragma once
#include "../captures/camera.hpp"

class Detector {
public:

    void draw_box(cv::Mat& frame, const cv::Rect& box);

};
