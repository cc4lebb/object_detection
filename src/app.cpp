#include <opencv2/opencv.hpp>

#include "app.hpp"
#include "captures/camera.hpp"

bool App::run() {
    Camera cam;
    
    cv::Mat frame;

    if (!cam.open_camera()) { return false; }

    while (cam.read(frame)) {
        cv::imshow("camera", frame);
        if (cv::waitKey(10) == 27) { break; }
        
    }

    cam.close();
    cv::destroyAllWindows();

    return true;
}
