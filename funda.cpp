#include <iostream>
#include "funda.h"
using namespace std;

Funda::Funda(string t, int c, string col, string cal, string f)
    : Accesorio(t, c, "Funda", col, cal, f) {}

void Funda::Mostrar() const {
    cout << "=== FUNDA ===" << endl;
    Accesorio::Mostrar();
}
