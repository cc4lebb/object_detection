#include <opencv2/opencv.hpp>

#include "app.hpp"

bool App::run() {

    const cv::Size object_size(15, 15);
    
    cv::Mat frame;
    
    int x{}, y{};

    cv::Rect target_box(x, y, 200, 150);

    if (!cam.open_camera()) { return false; }

    while (cam.read(frame)) {

        cv::Mat gray = preprocessor.make_gray(frame);
        cv::Mat blur = preprocessor.make_blur(gray, object_size);

        cv::Point point = detector.locate_point(blur);
        target_box.x = point.x - (target_box.width / 2);
        target_box.y = point.y - (target_box.height / 2);

        detector.draw_box(frame, target_box);

        cv::imshow("camera", frame);
        cv::imshow("gray", gray);
        cv::imshow("blur", blur);
        if (cv::waitKey(10) == 27) { break; }
        
    }

    cam.close();
    cv::destroyAllWindows();

    return true;
}
