#ifndef CELULAR_H
#define CELULAR_H

#include "ProductosElectronicos.h"

class Celular : public ProductosElectronicos {
private:
    string procesador;
    int memoriaRAM;
    string modelo;
    string almacenamiento;

public:
    Celular(int codigo, string nombre, double precio, int stock,
            string procesador, int memoriaRAM, string modelo, string almacenamiento);

    string getTipo() const override;
    string getProcesador() const;
    int getMemoriaRAM() const;
    string getModelo() const;
    string getAlmacenamiento() const;

    void llamar() const;
    void enviarMensaje() const;
    void tomarFoto() const;
    void configuracion() const;

};

#endif