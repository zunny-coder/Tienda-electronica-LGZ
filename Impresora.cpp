#include "Impresora.h"

Impresora::Impresora(int codigo, string nombre, double precio, int stock, string tipo, int velocidadImpresion, int nivelTinta, int cantidadPapel, string configuracion, bool color)
    : ProductosElectronicos(precio, to_string(codigo), "Marca", nombre), 
        tipo(tipo), velocidadImpresion(velocidadImpresion), nivelTinta(nivelTinta), 
        cantidadPapel(cantidadPapel), configuracion(configuracion), color(color) {}

string Impresora::getTipo() const {
    return "Impresora";
}

int Impresora::getVelocidadImpresion() const {
    return velocidadImpresion;
}

int Impresora::getNivelTinta() const {
    return nivelTinta;
}

int Impresora::getCantidadPapel() const {
    return cantidadPapel;
}

string Impresora::getConfiguracion() const {
    return configuracion;
}

bool Impresora::getColor() const {
    return color;
}

void Impresora::mostrarCaracteristicas() const {
    cout << "Tipo: " << getTipo() << endl;
    cout << "Velocidad de impresión: " << getVelocidadImpresion() << " ppm" << endl;
    cout << "Nivel de tinta: " << getNivelTinta() << "%" << endl;
    cout << "Cantidad de papel: " << getCantidadPapel() << " hojas" << endl;
    cout << "Configuración: " << getConfiguracion() << endl;
    cout << "Color: " << (getColor() ? "Sí" : "No") << endl;
}

void Impresora::imprimir() const {
    cout << "Imprimiendo documento..." << endl;
}

void Impresora::copiar() const {
    cout << "Fotocopiando documento..." << endl;
}

void Impresora::escanear() const {
    cout << "Escaneando documento..." << endl;
}

void Impresora::cancelarImpresion() const {
    cout << "Cancelando impresión..." << endl;
}

void Impresora::limpiarCabezales() const {
    cout << "Limpiando cabezales de impresión..." << endl;
}
