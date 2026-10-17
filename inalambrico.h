#ifndef INALAMBRICO_H
#define INALAMBRICO_H

#include "Audifonos.h"

class Inalambrico : public Audifonos {
private:
    bool bluetooth;
    string sensores;

public:
    Inalambrico(string con, double cons, int nv, bool bt, string sen);

    void conectarBluetooth();
    void controlarTactil();
};

#endif