# OpenGL, OpenCV tutorial(sample code)
tutorial OpenGL and OpenCV

#build sample
file : build.sh
./build.sh gl filename.cpp
ex) ./build.sh gl sample/opengl_test.cpp && ./app

#Makefile
source dir : src
output file : app

ex)
$ make all
$ ./app
$ make clean

DOTO List
1. Basic output image is openGL. OpenCV is supported for image to openGL.
