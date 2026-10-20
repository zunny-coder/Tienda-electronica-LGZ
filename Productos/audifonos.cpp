#include <iostream>
#include "Audifonos.h"
using namespace std;

Audifonos::Audifonos(string con, double cons, int nv)
    : Periferico(con, cons) {
    nivelVolumen = nv;
}

void Audifonos::subirVolumen() {
    if (nivelVolumen < 100) {
        nivelVolumen = nivelVolumen + 10;
    }
    cout << "Volumen: " << nivelVolumen << endl;
}

void Audifonos::bajarVolumen() {
    if (nivelVolumen > 0) {
        nivelVolumen = nivelVolumen - 10;
    }
    cout << "Volumen: " << nivelVolumen << endl;
}

void Audifonos::cambiarMusica() {
    cout << "Cambiando a la siguiente cancion..." << endl;
}