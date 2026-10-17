#include <iostream>
#include "TapeteMouse.h"
using namespace std;

TapeteMouse::TapeteMouse(string t, int c, string col, string cal, string f)
    : Accesorio(t, c, "TapeteMouse", col, cal, f) {}

void TapeteMouse::Mostrar() const {
    cout << "=== TAPETE PARA MOUSE ===" << endl;
    Accesorio::Mostrar();
}