#ifndef PROTECTOR_H
#define PROTECTOR_H

#include "accesorios.h"

class Protector : public Accesorio {
public:
    Protector(string t, int c, string col, string cal, string f);

    void Mostrar() const override;
};

#endif