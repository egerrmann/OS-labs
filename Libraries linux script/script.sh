#!/bin/bash

cd Number
g++ -c library.cpp -o libNumber.o
ar rcs libNumber.a libNumber.o
cp libNumber.a ../Vector
cp libNumber.a ../Test

cd ../Vector
g++ -c library.cpp -o libVector.o
g++ libVector.o libNumber.a -shared -o libVector.so
cp libVector.so ../Test

cd ../Test
g++ -c main.cpp
g++ -o main main.o libNumber.a libVector.so
sudo mv libVector.so /usr/lib/
sudo ldconfig
./main
