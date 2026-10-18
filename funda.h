#ifndef FUNDA_H
#define FUNDA_H

#include "accesorios.h"

class Funda : public Accesorio {
public:
    Funda(string t, int c, string col, string cal, string f);

    void Mostrar() const override;
};

#endif