#include "detector.hpp"

void Detector::draw_box(cv::Mat& frame, const cv::Rect& box){
    cv::rectangle(frame, box, cv::Scalar(0, 255, 0), 2);
}

cv::Point Detector::locate_point(cv::Mat& frame) {
    double minVal{}, maxVal{};
    cv::Point minLoc{}, maxLoc{};

    cv::minMaxLoc(frame, &minVal, &maxVal, &minLoc, &maxLoc);

    return minLoc;
}
