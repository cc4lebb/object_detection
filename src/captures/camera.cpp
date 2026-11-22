#include "camera.hpp"
#include <iostream>

   
bool Camera::open_camera(Cams cam_id){

    cap.open(static_cast<int>(cam_id));

    if (!cap.isOpened()) {
        std::cerr << "Could not open camera" << '\n';
        return false;
    };

    return true;
};

bool Camera::read(cv::Mat& frame){
    cap >> frame;
    if (frame.empty()){
        std::cerr << "blank frame grabbed" << '\n';
        return false;
    }

    return true;
}

void Camera::close(){
    cap.release();

}

