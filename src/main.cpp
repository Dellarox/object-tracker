#include <iostream>

#include "Camera.hpp"

constexpr int CAMERA_DEVICE_NUMBER = 0;

int main()
{
    try
    {
        Camera camera(CAMERA_DEVICE_NUMBER);
        camera.showFrames();
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Caught runtime error: " << e.what() << std::endl;
    }

    return 0;
}
