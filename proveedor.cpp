#include <iostream>
#include "Proveedor.h"
using namespace std;

Proveedor::Proveedor(string d, string n, string t, string c,
                     string r, int s, string cod)
    : Persona(d, n, t, c) {
    RUC = r;
    stock = s;
    codigo = cod;
}


string Proveedor::getRUC() { return RUC; }
int Proveedor::getStock() { return stock; }
string Proveedor::getCodigo() { return codigo; }


void Proveedor::setRUC(string r) { RUC = r; }
void Proveedor::setStock(int s) { stock = s; }
void Proveedor::setCodigo(string cod) { codigo = cod; }


void Proveedor::suministrarProducto() {
    int cantidad;

    cout << "Cantidad de productos a suministrar: ";
    cin >> cantidad;

    stock = stock + cantidad;
    cout << "Producto suministrado correctamente." << endl;
}


void Proveedor::actualizarStock() {
    int nuevoStock;

    cout << "Nuevo stock: ";
    cin >> nuevoStock;

    stock = nuevoStock;
    cout << "Stock actualizado correctamente." << endl;
}


int Proveedor::consultarStock() {
    return stock;
}

void Proveedor::mostrarDatos() const {
    cout << "--- PROVEEDOR ---" << endl;
    cout << "DNI: " << getDni() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Telefono: " << getTelefono() << endl;
    cout << "Correo: " << getCorreo() << endl;
    cout << "RUC: " << RUC << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Stock: " << stock << endl;
}
