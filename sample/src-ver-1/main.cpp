#include "Graphic.h"

int main(int argc, char *argv[]) {
    Graphic *graphic = new Graphic(argc, argv);
    graphic->testCam();   // for test1
    //graphic->testOpengl();   // for test2
    delete graphic;
    return 0;
}
