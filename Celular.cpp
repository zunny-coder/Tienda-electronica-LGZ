#include "Celular.h"

Celular::Celular(int codigo, string nombre, double precio, int stock,
                 string procesador, int memoriaRAM, string modelo, string almacenamiento)
    : ProductosElectronicos(precio, to_string(codigo), "Marca", nombre), procesador(procesador), 
    memoriaRAM(memoriaRAM), modelo(modelo), almacenamiento(almacenamiento) {}

string Celular::getModelo() const {
    return modelo;
}

string Celular::getAlmacenamiento() const {
    return almacenamiento;
}

void Celular::llamar() const {
    cout << "   Llamando..." << endl;
}

void Celular::enviarMensaje() const {
    cout << "   Enviando mensaje..." << endl;
}

void Celular::tomarFoto() const {
    cout << "   Tomando foto..." << endl;
}

void Celular::configuracion() const {
    cout << "   Configurando celular..." << endl;
}