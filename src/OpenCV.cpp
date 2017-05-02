#include "OpenCV.h"
OpenCV::OpenCV() {
}
int OpenCV::init(int type) {

    m_capture.open(type);
    if (!m_capture.isOpened()) {
        cerr << "Cloud not open camera" << endl;
        return -1;
    }

    return 0;
}

OpenCV::~OpenCV() {
}

void OpenCV::showImage(string windowName) {
    cv::Mat image;
    cv::namedWindow(windowName, 1);
    while (m_capture.isOpened()) {
        image = getImage();
        cv::imshow(windowName, image);
        if (cv::waitKey(30) == 27) {
            // esc
            break;
        }
    }

    cv::destroyWindow(windowName);
}

cv::Mat OpenCV::getImage() {
    cv::Mat img;
    if (m_capture.isOpened()) {
        m_capture >> img;
    }

    return img;
}
