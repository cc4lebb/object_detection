#pragma once

#include "captures/camera.hpp"
#include "processing/preprocessor.hpp"

class App {
    Camera cam;
    Preprocessor preprocessor;
public:
    bool run();
};
