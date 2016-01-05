#include <iostream>
#include <string.h>

using namespace std;

class Complex
{
    double x,y;
public:
    Complex();
    Complex(double x1, double y1);
    ~Complex();
    double getx();
    double gety();
    Complex add(Complex a);
    Complex sub(Complex a);
    Complex mul(Complex a);
    Complex div(Complex a);
    Complex pow(int a);
    friend void print(Complex a);
    friend class Matrix;


};

class Matrix
{
    Complex **tab;
    int a,b;
public:
    Matrix();
    Matrix(int x, int y);
    Matrix(string mac);
    Matrix(Matrix &wzor);
    Complex get(int x1, int y1);
    void sett(int x1, int y1, double re, double im);
    void wypisz();
    Matrix add(Matrix mac1);
    Matrix sub(Matrix mac1);
    Matrix mul(Matrix mac1);
    Matrix mul(Complex k);
    Matrix div(Complex k);
    Matrix pow(int x);
    Matrix div(Matrix mac1);
};


