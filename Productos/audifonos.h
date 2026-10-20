#ifndef AUDIFONOS_H
#define AUDIFONOS_H

#include "Periferico.h"

class Audifonos : public Periferico {
private:
    int nivelVolumen;

public:
    Audifonos(string con, double cons, int nv);

    void subirVolumen();
    void bajarVolumen();
    void cambiarMusica();
};

#endif