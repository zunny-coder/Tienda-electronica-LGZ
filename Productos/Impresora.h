#ifndef IMPRESORA_H
#define IMPRESORA_H

#include "ProductosElectronicos.h"

class Impresora : public ProductosElectronicos {
private:
    string tipo;
    int velocidadImpresion;
    int nivelTinta;
    int cantidadPapel;
    string configuracion;
    bool color;

public:
    Impresora(int codigo, string nombre, double precio, int stock, string tipo, int velocidadImpresion, int nivelTinta, int cantidadPapel, string configuracion, bool color);

    string getTipo() const override;
    int getVelocidadImpresion() const;
    int getNivelTinta() const;
    int getCantidadPapel() const;
    string getConfiguracion() const;
    bool getColor() const;

    void mostrarCaracteristicas() const;
    void imprimir() const;
    void copiar() const;
    void escanear() const;
    void cancelarImpresion() const;
    void limpiarCabezales() const;
};

#endif