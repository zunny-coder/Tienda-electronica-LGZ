#ifndef CONCABLE_H
#define CONCABLE_H

#include "Audifonos.h"

class ConCable : public Audifonos {
private:
    double longitudCable;
    bool microfono;

public:
    ConCable(string con, double cons, int nv, double lc, bool mic);

    void conectar();
    void usarMicrofono();
};

#endif