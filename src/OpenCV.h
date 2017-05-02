#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
using namespace std;

class OpenCV {
private:
    cv::VideoCapture m_capture;
public:
    static const int WEB_CAM = 0; // format mac os

    static const int IMAGE_BASIC = 0;
    static const int IMAGE_DETECT_FACE = 1;
    OpenCV();
    ~OpenCV();

    int init(int type);
    void showImage(string windowName, int type);
    cv::Mat getImage();
    cv::Mat detectFace(cv::Mat frame_original);
};
