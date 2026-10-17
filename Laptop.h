#ifndef LAPTOP_H
#define LAPTOP_H

#include "Computadora.h"

class Laptop : public Computadora {
private:
    string procesador;
    int memoriaRAM;

public:
    Laptop(int codigo, string nombre, double precio, int stock,
           string procesador, int memoriaRAM);

    string getTipo() const override;
    string getProcesador() const;
    int getMemoriaRAM() const;
};

#endif