#include <opencv2/opencv.hpp>

#include "app.hpp"

bool App::run() {

    const cv::Size object_size(15, 15);
    
    cv::Mat frame;
    cv::Rect target_box(50, 50, 200, 150);

    if (!cam.open_camera()) { return false; }

    while (cam.read(frame)) {

        detector.draw_box(frame, target_box);
        cv::Mat gray = preprocessor.make_gray(frame);
        cv::Mat blur = preprocessor.make_blur(gray, object_size);

        cv::imshow("camera", frame);
        cv::imshow("gray", gray);
        cv::imshow("blur", blur);
        if (cv::waitKey(10) == 27) { break; }
        
    }

    cam.close();
    cv::destroyAllWindows();

    return true;
}
