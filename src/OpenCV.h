#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
using namespace std;

class OpenCV {
private:
    cv::VideoCapture m_capture;
public:
    static const int WEB_CAM = 0; // format mac os
    OpenCV();
    ~OpenCV();

    int init(int type);
    void showImage(string windowName);
    cv::Mat getImage();
};
