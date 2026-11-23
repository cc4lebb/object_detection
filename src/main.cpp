#include "app.hpp"

int main() {
    App app;

    try {
        std::cout << "app is running" << '\n';
        app.run();
    } catch (...){
        std::cerr << "an error occured" << '\n';
    }


    return 0;
}
