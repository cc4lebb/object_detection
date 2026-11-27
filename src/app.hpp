#pragma once

#include "captures/camera.hpp"
#include "processing/preprocessor.hpp"
#include "processing/detector.hpp"

class App {
    Camera cam;
    Preprocessor preprocessor;
    Detector detector;
public:
    bool run();
};
