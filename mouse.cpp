#include <iostream>
#include "Mouse.h"
using namespace std;

Mouse::Mouse(string con, double cons, int d)
    : Periferico(con, cons) {
    dpi = d;
}

void Mouse::mover() {
    cout << "Moviendo el mouse a " << dpi << " dpi..." << endl;
}

void Mouse::hacerClick() {
    cout << "Click realizado." << endl;
}