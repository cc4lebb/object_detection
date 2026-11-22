#pragma once

#include <opencv2/opencv.hpp>

enum class Cams {
    default_cam = 0,
    external_cam = 1
};

class Camera {
    cv::VideoCapture cap;

public:
    bool open_camera(Cams cam_id = Cams::default_cam);
    bool read(cv::Mat& frame);
    void close();

};
