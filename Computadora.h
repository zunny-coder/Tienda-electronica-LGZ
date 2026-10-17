#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include "ProductosElectronicos.h"

class Computadora : public ProductosElectronicos {
private:
    string procesador;
    int memoriaRAM;
    int almacenamiento;
    string puerto;
    string pantalla;
    string tarjetaGrafica;
    string sistemaOperativo;

public:
    Computadora(int codigo, string nombre, double precio, int stock,
                string procesador, int memoriaRAM, int almacenamiento, string puerto,
                string pantalla, string tarjetaGrafica, string sistemaOperativo);

    string getTipo() const override;
    string getProcesador() const;
    int getMemoriaRAM() const;
    int getAlmacenamiento() const;
    string getPuerto() const;
    string getPantalla() const;
    string getTarjetaGrafica() const;
    string getSistemaOperativo() const;

    void mostrarCaracteristicas() const;
    void mostrarCompatibilidad() const;
    void getActualizar() const;
};

#endif