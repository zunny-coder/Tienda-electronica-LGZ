#ifndef SOPORTE_H
#define SOPORTE_H

#include "accesorios.h"

class Soporte : public Accesorio {
public:
    Soporte(string t, int c, string col, string cal, string f);

    void Mostrar() const override;
};

#endif