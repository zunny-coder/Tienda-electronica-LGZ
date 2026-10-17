#include <iostream>
#include "ConCable.h"
using namespace std;

ConCable::ConCable(string con, double cons, int nv, double lc, bool mic)
    : Audifonos(con, cons, nv) {
    longitudCable = lc;
    microfono = mic;
}

void ConCable::conectar() {
    cout << "Audifonos conectados por cable de " << longitudCable << " m." << endl;
}

void ConCable::usarMicrofono() {
    if (microfono) {
        cout << "Microfono activado." << endl;
    } else {
        cout << "Estos audifonos no tienen microfono." << endl;
    }
}