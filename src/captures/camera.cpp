#include "camera.hpp"
#include <iostream>

   
bool Camera::open_camera(Cams cam_id){

    cap.open(static_cast<int>(cam_id));

    if (!cap.isOpened()) {
        std::cerr << "Could not open camera" << '\n';
        return false;
    };

    is_running = true;

    while(is_running) {
        cap >> frame;

        if (frame.empty()){
            std::cerr << "blank frame grabbed" << '\n';
            break;
        }

        cv::imshow("camera", frame);

        if (cv::waitKey(10) == 27) { break; }
    }

    is_running = false;
    cap.release();
    cv::destroyAllWindows();

    return true;
};
