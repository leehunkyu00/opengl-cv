#include "OpenCV.h"
#include "HKOpenGL.h"

class Graphic {
private:
    int m_argc;
    char **m_argv;
public:
    Graphic(int argc, char *argv[]);
    ~Graphic();
    // for test
    void testCam();
    void testOpengl();
};
