#include "Graphic.h"

int main(int argc, char *argv[]) {
    Graphic *graphic = new Graphic();
    graphic->testCam();
    delete graphic;

    return 0;
}
