//Kamil Kryjak, nr indeksu 275738
#include <iostream>
#include "matrix.h"

using namespace std;

int main(int argc, char *argv[])
{

    //Matrix x1("[4 5; 5 1]");
    //Matrix x2("[3 5; -2 6]");
    Matrix m1(argv[1]);
    Matrix m2(argv[2]);
    Complex x(2,0);

    cout << "Macierz pierwsza" << endl;
    m1.wypisz();
    cout << "Macierz druga" << endl;
    m2.wypisz();
    cout << "Dodawanie" << endl;
    m1.add(m2).wypisz();
    cout << "Odejmowanie" << endl;
    m1.sub(m2).wypisz();
    cout << "Mnozenie(skalar)" << endl;
    m1.mul(x).wypisz();
    cout << "Mnozenie" << endl;
    m1.mul(m2).wypisz();
    cout << "Dzielenie(skalar)" << endl;
    m1.div(x).wypisz();
    cout << "Potegowanie" << endl;
    m1.pow(2).wypisz();
    cout << "Dzielenie" << endl;
    m1.div(m2).wypisz();


    return 0;
}
