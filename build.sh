#!/bin/bash

option=$1
filename=$2

if [ $option = 'cv' ]; then
    echo 'cv'
    g++ $filename -o app `pkg-config --cflags --libs opencv`;
elif [ $option = 'gl' ]; then
    echo 'gl'
    g++ -framework OpenGL -framework GLUT $filename -o app;
elif [ $option = 'glcv' ]; then
    echo 'glcv'
    g++ -framework OpenGL -framework GLUT $filename -o app `pkg-config --cflags --libs opencv`;
fi
