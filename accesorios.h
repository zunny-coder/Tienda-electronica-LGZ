#ifndef ACCESORIO_H
#define ACCESORIO_H

#include <string>
#include "Producto.h"
using namespace std;

class Accesorio : public Producto {
private:
    string tamano;
    int cantidad;
    string categoria;
    string color;
    string calidad;
    string forma;

public:
    Accesorio(string t, int c, string cat, string col, string cal, string f);

    virtual void Mostrar() const;
    void Buscar();
    void Vender();
};

#endif