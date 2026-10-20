#ifndef TECLADO_H
#define TECLADO_H

#include "Periferico.h"

class Teclado : public Periferico {
private:
    string tipo;

public:
    Teclado(string con, double cons, string t);

    void escribir();
    void presionarTecla();
};

#endif