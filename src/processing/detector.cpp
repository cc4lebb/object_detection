
#include "detector.hpp"


void Detector::draw_box(cv::Mat& frame, const cv::Rect& box){
    cv::rectangle(frame, box, cv::Scalar(0, 255, 0), 2);
}
