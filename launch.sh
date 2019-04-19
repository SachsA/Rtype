#!/usr/bin/env bash

rm -rf build &&
mkdir build &&
cd build &&
conan install -s compiler.libcxx=libstdc++11 --build sfml .. --build=missing &&
cmake .. -G "Unix Makefiles" &&
cmake -build . &&
make