#include "HKOpenGL.h"

void HKOpenGL::draw(int type) {
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL example");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(Triangle);
    glutMainLoop();
}

void HKOpenGL::Triangle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 0.1);
    glVertex2f(-0.1, -0.1);
    glVertex2f(0.1, -0.1);
    glEnd();
    glFlush();
}
