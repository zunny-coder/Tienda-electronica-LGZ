#ifndef FUNDA_H
#define FUNDA_H

#include "Accesorio.h"

class Funda : public Accesorio {
public:
    Funda(string t, int c, string col, string cal, string f);

    void Mostrar() const override;
};

#endif