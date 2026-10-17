#ifndef PRODUCTOSELECTRONICOS_H
#define PRODUCTOSELECTRONICOS_H

#include "Productos.h"
#include <iostream>
#include <string>
using namespace std;

class ProductosElectronicos : public Productos {
private:
    double precio;
    string codigo;
    string marca;
    string nombre;

    public:
    ProductosElectronicos(double precio, string codigo, string marca, string nombre);

    string getEncender() const;
    string getApagar() const;
    string getReiniciar() const;
    int getBateria() const;
    void getConectar() const;
    void getDesconectar() const;

    virtual string getTipo() const;
};

#endif