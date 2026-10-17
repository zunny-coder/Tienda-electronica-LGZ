#include <iostream>
#include "Cliente.h"
using namespace std;

Cliente::Cliente(string d, string n, string t, string c)
    : Persona(d, n, t, c) {}


void Cliente::comprar() {
    string producto;
    int cantidad;

    cout << "Producto a comprar: ";
    cin >> producto;
    cout << "Cantidad: ";
    cin >> cantidad;

    cout << "Compra realizada: " << cantidad << " de " << producto << endl;
}

void Cliente::consultarProducto() {
    string codigo;

    cout << "Codigo del producto a consultar: ";
    cin >> codigo;

    cout << "Consultando producto con codigo " << codigo << "..." << endl;
}

void Cliente::realizarPedido() {
    string producto;
    int cantidad;

    cout << "Producto a pedir: ";
    cin >> producto;
    cout << "Cantidad: ";
    cin >> cantidad;

    cout << "Pedido registrado: " << cantidad << " de " << producto << endl;
}

void Cliente::mostrarDatos() const {
    cout << "--- CLIENTE ---" << endl;
    cout << "DNI: " << dni << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Correo: " << correo << endl;
}