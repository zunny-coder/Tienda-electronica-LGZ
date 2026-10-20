#include <iostream>
#include "Soporte.h"
using namespace std;

Soporte::Soporte(string t, int c, string col, string cal, string f)
    : Accesorio(t, c, "Soporte", col, cal, f) {}

void Soporte::Mostrar() const {
    cout << "=== SOPORTE ===" << endl;
    Accesorio::Mostrar();
}
