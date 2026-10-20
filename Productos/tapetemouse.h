#ifndef TAPETEMOUSE_H
#define TAPETEMOUSE_H

#include "accesorios.h"

class TapeteMouse : public Accesorio {
public:
    TapeteMouse(string t, int c, string col, string cal, string f);

    void Mostrar() const override;
};

#endif