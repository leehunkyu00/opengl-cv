#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <iostream>
using namespace std;

class HKOpenGL {
private:
    int m_argc;
    char **m_argv;
public:
    HKOpenGL(int argc, char *argv[]) : m_argc(argc), m_argv(argv) {
        glutInit(&m_argc, m_argv);
    };
    ~HKOpenGL() {
        /*Empty*/
    };
    static const int TRIANGLE = 0;

    void draw(int type);
    static void Triangle();
};
