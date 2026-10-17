#ifndef MOUSE_H
#define MOUSE_H

#include "Periferico.h"

class Mouse : public Periferico {
private:
    int dpi;

public:
    Mouse(string con, double cons, int d);

    void mover();
    void hacerClick();
};

#endif