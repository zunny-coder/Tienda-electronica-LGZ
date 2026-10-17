#include <iostream>
#include "Protector.h"
using namespace std;

Protector::Protector(string t, int c, string col, string cal, string f)
    : Accesorio(t, c, "Protector", col, cal, f) {}

void Protector::Mostrar() const {
    cout << "=== PROTECTOR ===" << endl;
    Accesorio::Mostrar();
}