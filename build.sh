#!/bin/bash

mkdir -p build && cd build
cmake ..
cmake --build .
cd ..
mpirun -np 2 ./build/main
