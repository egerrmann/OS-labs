cd Number
g++ -c library.cpp -o libNumber.o
ar rcs libNumber.lib libNumber.o
cp libNumber.lib ../Vector
cp libNumber.lib ../Test

cd ../Vector
g++ -c library.cpp -o libVector.o
g++ libVector.o libNumber.lib -shared -o libVector.dll
cp libVector.dll ../Test
cd ../Test

g++ -c main.cpp
g++ -o main main.o libVector.dll
./main
