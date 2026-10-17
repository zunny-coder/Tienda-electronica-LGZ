#ifndef PERIFERICO_H
#define PERIFERICO_H

#include <string>
#include "ProductoElectronico.h"
using namespace std;

class Periferico : public ProductoElectronico {
private:
    string conexion;
    double consumoEnergia;

public:
    Periferico(string con, double cons);

    void verificarConexion();
    virtual void mostrar() const;
};

#endif