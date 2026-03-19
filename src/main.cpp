#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

int main()
{
    std::cout << "OpenCV version: " <<  CV_VERSION << std::endl;

    cv::Mat frame;
    cv::VideoCapture cap;

    int device = 0;

    cap.open(device);

    if (!cap.isOpened())
    {
        std::cout << "Failed to open camera" << std::endl;
        return -1;
    }

    while (true)
    {
        cap.read(frame);
        if (frame.empty())
        {
            std::cout << "Failed to read frame" << std::endl;
            break;
        }
        cv::imshow("Camera", frame);

        if (cv::waitKey(1) >= 0)
            break;
    }

    return 0;
}