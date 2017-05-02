#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    cv::VideoCapture capture;

    capture.open(0);
    if (!capture.isOpened()) {
        cerr << "Cloud not open camera" << endl;
        return -1;
    }

    // create a window
    cv::namedWindow("webcam", 1);

    // face detection configuration
    cv::CascadeClassifier face_classifier;
    face_classifier.load("/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml");

    while (true) {
        bool frame_valid = true;
        cv::Mat frame_original;
        cv::Mat frame;

        try {
            capture >> frame_original;
            cv::resize(frame_original, frame, cv::Size(frame_original.cols/2,
                        frame_original.rows/2), 0, 0, CV_INTER_NN);
        } catch(cv::Exception e) {
            cerr << "Exception occurred. Ignoring frame..." << e.err << endl;
            frame_valid = false;
        }

        if (frame_valid) {
            try {
                // convert captured frame to gray scale & equlize
                cv::Mat grayFrame;
                cv::cvtColor(frame, grayFrame, CV_BGR2GRAY);
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

                    cv::rectangle(frame, lb, tr, cv::Scalar(0, 255, 0), 3, 4, 0);
                }
                cv::imshow("webcam", frame);
            } catch(cv::Exception e) {
                cerr << "Exception occurred. Ignoring frame..." << e.err << endl;
            }

        }
        if (cv::waitKey(30) >= 0) break;
    }

    // VideoCapture automatically deallocate camera object
    return 0;
}
