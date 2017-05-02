#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {


    cout << "OpenCV Version : " << CV_VERSION << endl;

    cv::Mat image;
    cv::namedWindow("Example_Cam", 1);
    cv::VideoCapture cap;

    cap.open(0);
    // notebook cam index : 1 or -1
    // usb cam index : 0
    // mac index 0

    while (cap.isOpened()) {
        cap >> image;
        cv::imshow("Example_Cam", image);
        if (cv::waitKey(30) == 27) {
            // esc
            break;
        }
    }

    cv::destroyWindow("Example_Cam");
    return 0;
}
