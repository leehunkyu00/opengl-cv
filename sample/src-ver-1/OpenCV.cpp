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

void OpenCV::showImage(string windowName, int type) {
    cv::Mat image;
    cv::namedWindow(windowName, 1);
    while (m_capture.isOpened()) {
        image = getImage();
        switch (type) {
            case IMAGE_BASIC:
                break;
            case IMAGE_DETECT_FACE:
                image = detectFace(image);
                break;
        }
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

cv::Mat OpenCV::detectFace(cv::Mat frame_original) {

    bool frame_valid = true;
    cv::CascadeClassifier face_classifier;
    face_classifier.load("/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml");
    cv::Mat result_frame;
    try {
        cv::resize(frame_original, result_frame, cv::Size(frame_original.cols/2,
                    frame_original.rows/2), 0, 0, CV_INTER_NN);
    } catch(cv::Exception e) {
        cerr << "Exception occurred. Ignoring frame..." << e.err << endl;
        frame_valid = false;
    }

    if (frame_valid) {
        try {
            // convert captured frame to gray scale & equlize
            cv::Mat grayFrame;
            cv::cvtColor(result_frame, grayFrame, CV_BGR2GRAY);
            cv::equalizeHist(grayFrame, grayFrame);

            // face detection routine
            vector<cv::Rect> faces;
            face_classifier.detectMultiScale(grayFrame, faces,
                    1.1,    // increase search scale by 10% each pass
                    3,      // merge groups of three detections
                    CV_HAAR_FIND_BIGGEST_OBJECT | CV_HAAR_SCALE_IMAGE,
                    cv::Size(30, 30));

            // draw the result
            for (int i=0; i<faces.size(); i++) {
                cv::Point lb(faces[i].x + faces[i].width,
                        faces[i].y + faces[i].height);
                cv::Point tr(faces[i].x, faces[i].y);

                cv::rectangle(result_frame, lb, tr, cv::Scalar(0, 255, 0), 3, 4, 0);
            }
        } catch(cv::Exception e) {
            cerr << "Exception occurred. Ignoring frame..." << e.err << endl;
        }

    }
    return result_frame;
}
