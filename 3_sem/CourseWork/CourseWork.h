#ifndef COURSEWORK_H
#define COURSEWORK_H

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include <conio.h>

using namespace std;

class Matrix {
    int n;
    int* matrix;

public:
    Matrix(int n);
    void setEl(int i, int j);
    int getEl(int i, int j);
    void inPut();
    void outPut();
    Matrix difF(Matrix A, Matrix B);
    void simI(Matrix A, Matrix B);
    void writeFile(string s);
    void readFile(string filename);
    void assignment(Matrix B);

    void setN(int N);
    int sizeMat(int n);
    int index(int i, int j);
    int sizeDoubleMat(int n);
    int getSize();
};

#endif