#include "Graphic.h"
Graphic::Graphic() {
}

Graphic::~Graphic() {
}
// for test
void Graphic::testCam() {
    OpenCV opencv;
    opencv.init(OpenCV::WEB_CAM);
    opencv.showImage("helloworld!", OpenCV::IMAGE_DETECT_FACE);
    //opencv.showImage("helloworld!", OpenCV::IMAGE_BASIC);

}
