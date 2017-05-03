#include "Graphic.h"

Graphic::Graphic(int argc, char *argv[]) : m_argc(argc), m_argv(argv) {
        /*Empty*/
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

void Graphic::testOpengl() {
    HKOpenGL *opengl = new HKOpenGL(m_argc, m_argv);
    opengl->draw(HKOpenGL::TRIANGLE);

    delete opengl;
}
