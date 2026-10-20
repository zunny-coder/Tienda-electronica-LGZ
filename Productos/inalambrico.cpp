#include <iostream>
#include "Inalambrico.h"
using namespace std;

Inalambrico::Inalambrico(string con, double cons, int nv, bool bt, string sen)
    : Audifonos(con, cons, nv) {
    bluetooth = bt;
    sensores = sen;
}

void Inalambrico::conectarBluetooth() {
    if (bluetooth) {
        cout << "Conectado por Bluetooth." << endl;
    } else {
        cout << "Estos audifonos no tienen Bluetooth." << endl;
    }
}

void Inalambrico::controlarTactil() {
    cout << "Control tactil con sensores: " << sensores << endl;
}