#include "ProductosElectronicos.h"
using namespace std;

ProductosElectronicos::ProductosElectronicos(double precio, string codigo, string marca, string nombre)
    : Productos (0, nombre, precio, 0, marca, "", "", 0, "", 0) {}

string ProductosElectronicos::getEncender() const {
    cout << "Encendiendo dispositivo..." << endl;
    return "Dispositivo encendido.";
}

string ProductosElectronicos::getApagar() const {
    cout << "Apagando dispositivo..." << endl;
    return "Dispositivo apagado.";
}

string ProductosElectronicos::getReiniciar() const {
    cout << "Reiniciando dispositivo..." << endl;
    return "Dispositivo reiniciado.";
}

int ProductosElectronicos::getBateria() const {
    return 100;
}

void ProductosElectronicos::getConectar() const {
    cout << "Dispositivo conectado." << endl;
}

void ProductosElectronicos::getDesconectar() const {
    cout << "Dispositivo desconectado." << endl;
}

string ProductosElectronicos::getTipo() const {
    return "Producto Electrónico";
}