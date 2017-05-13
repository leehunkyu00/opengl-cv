#!/bin/bash

filename=$1

g++ $filename -framework OpenGL -o app `pkg-config --cflags glfw3`  `pkg-config --static --libs glfw3` `pkg-config --cflags glew`
