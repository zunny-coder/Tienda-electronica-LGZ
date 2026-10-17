#include <iostream>
#include "Empleado.h"
using namespace std;

Empleado::Empleado(string d, string n, string t, string c,
                   double su, string h, string ca)
    : Persona(d, n, t, c) {
    sueldo = su;
    horario = h;
    cargo = ca;
}

// Getters
double Empleado::getSueldo() { return sueldo; }
string Empleado::getHorario() { return horario; }
string Empleado::getCargo() { return cargo; }

// Setters
void Empleado::setSueldo(double su) { sueldo = su; }
void Empleado::setHorario(string h) { horario = h; }
void Empleado::setCargo(string ca) { cargo = ca; }


void Empleado::registrarVenta() {
    string producto;
    int cantidad;

    cout << "Producto vendido: ";
    cin >> producto;
    cout << "Cantidad: ";
    cin >> cantidad;

    cout << "Venta registrada: " << cantidad << " de " << producto << endl;
}


void Empleado::consultarProducto() {
    string codigo;

    cout << "Codigo del producto a consultar: ";
    cin >> codigo;

    cout << "Consultando producto con codigo " << codigo << "..." << endl;
}


void Empleado::actualizarStock() {
    string codigo;
    int nuevoStock;

    cout << "Codigo del producto: ";
    cin >> codigo;
    cout << "Nuevo stock: ";
    cin >> nuevoStock;

    cout << "Stock del producto " << codigo << " actualizado a " << nuevoStock << endl;
}

void Empleado::mostrarDatos() const {
    cout << "--- EMPLEADO ---" << endl;
    cout << "DNI: " << dni << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Correo: " << correo << endl;
    cout << "Sueldo: " << sueldo << endl;
    cout << "Horario: " << horario << endl;
    cout << "Cargo: " << cargo << endl;
}