#include "Camera.hpp"

#include <stdexcept>

constexpr int ASCII_ESCAPE = 27;
constexpr int ASCII_UPPERCASE_Q = 81;
constexpr int ASCII_LOWERCASE_Q = 113;
constexpr int DELAY = 5;

Camera::Camera(int device)
{
    mCapture.open(device);
    if (!mCapture.isOpened())
    {
        throw std::runtime_error("Camera cannot be opened");
    }
}

void Camera::showFrames()
{
    while (true)
    {
        mCapture.read(mFrame);
        if (mFrame.empty())
            throw std::runtime_error("No frames available");

        cv::imshow("Camera", mFrame);

        int key = cv::waitKey(DELAY);
        if (key == ASCII_ESCAPE || key == ASCII_UPPERCASE_Q || key == ASCII_LOWERCASE_Q)
            break;
    }
}
