#ifndef PERIFERICO_H
#define PERIFERICO_H

#include <string>
#include "ProductosElectronicos.h"
using namespace std;

class Periferico : public ProductosElectronicos {
private:
    string conexion;
    double consumoEnergia;

public:
    Periferico(string con, double cons);

    void verificarConexion();
    virtual void mostrar() const;
};

#endif