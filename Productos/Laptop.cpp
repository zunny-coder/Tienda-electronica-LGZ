#include "Laptop.h"

Laptop::Laptop(int codigo, string nombre, double precio, int stock,
               string procesador, int memoriaRAM)
     : Computadora(codigo, nombre, precio, stock, "", 0, 0, "", "", "", ""), procesador(procesador), 
        memoriaRAM(memoriaRAM) { }

string Laptop::getTipo() const {
    return "Laptop";
}

string Laptop::getProcesador() const {
    return procesador;
}

int Laptop::getMemoriaRAM() const {
    return memoriaRAM;
}