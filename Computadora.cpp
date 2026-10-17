#include "Computadora.h"

Computadora::Computadora(int codigo, string nombre, double precio, int stock,
                        string procesador, int memoriaRAM, int almacenamiento, string puerto,
                        string pantalla, string tarjetaGrafica, string sistemaOperativo)
    : ProductosElectronicos(precio, to_string(codigo), "Marca", nombre), procesador(procesador), 
        memoriaRAM(memoriaRAM) {}

string Computadora::getTipo() const {
    return "Computadora";
}

string Computadora::getProcesador() const {
    return procesador;
}

int Computadora::getMemoriaRAM() const {
    return memoriaRAM;
}

int Computadora::getAlmacenamiento() const {
    return almacenamiento;
}

string Computadora::getPuerto() const {
    return puerto;
}

string Computadora::getPantalla() const {
    return pantalla;
}

string Computadora::getTarjetaGrafica() const {
    return tarjetaGrafica;
}

string Computadora::getSistemaOperativo() const {
    return sistemaOperativo;
}

void Computadora::mostrarCaracteristicas() const {
    cout << "Procesador: " << getProcesador() << " | RAM: " << getMemoriaRAM() << "GB" << endl;
}

void Computadora::mostrarCompatibilidad() const {
    cout << "Compatibilidad del sistema." << endl;
}

void Computadora::getActualizar() const {
    cout << "Componentes de la PC actualizados." << endl;
}