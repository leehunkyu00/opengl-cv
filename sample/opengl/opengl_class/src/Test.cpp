#include "Test.h"

void Test::MyDisplay(){
    glClear(GL_COLOR_BUFFER_BIT); // GL상태변수 설정, 프레임 버퍼를 초기화
    // 초기화 될 색은 glutClearColor에서 사용된 색
    glViewport(0, 0, 300, 300);
    glColor3f(1.0, 1.0, 1.0); //
    glBegin(GL_POLYGON); // 입력요소 기본정의
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glEnd();
    glFlush();
}

int Test::run(int argc, char** argv){
    glutInit(&argc, argv); // GLUT 윈도우 함수
    glutInitDisplayMode(GLUT_RGB); // 윈도우 의 기본컬러모드를 RGB모드로 설정
    glutInitWindowSize(300, 300); // 윈도우 사이즈 설정
    glutInitWindowPosition(0, 0); // 윈도우 창 위치 설정
    glutCreateWindow("OpenGL example");
    glClearColor(0.0, 0.0, 0.0, 1.0); // GL 상태변수 설정, 마지막 알파값은 1이면 불투명 0이면 투명
    glMatrixMode(GL_PROJECTION); //
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay); // GLUT 콜백함수 등록
    glutMainLoop(); // 이벤트 루프 진입
    return 0;
}
