#include <opencv2/opencv.hpp>

#include "app.hpp"

bool App::run() {
    
    cv::Mat frame;
    cv::Rect target_box(50, 50, 200, 150);

    if (!cam.open_camera()) { return false; }

    while (cam.read(frame)) {

        detector.draw_box(frame, target_box);
        cv::Mat gray = preprocessor.make_gray(frame);

        cv::imshow("camera", frame);
        cv::imshow("gray", gray);
        if (cv::waitKey(10) == 27) { break; }
        
    }

    cam.close();
    cv::destroyAllWindows();

    return true;
}
