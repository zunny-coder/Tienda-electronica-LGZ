#include <iostream>
#include "Persona.h"
using namespace std;

Persona::Persona(string d, string n, string t, string c) {
    dni = d;
    nombre = n;
    telefono = t;
    correo = c;
}

string Persona::getDni() { return dni; }
string Persona::getNombre() { return nombre; }
string Persona::getTelefono() { return telefono; }
string Persona::getCorreo() { return correo; }


void Persona::setDni(string d) { dni = d; }
void Persona::setNombre(string n) { nombre = n; }
void Persona::setTelefono(string t) { telefono = t; }
void Persona::setCorreo(string c) { correo = c; }


void Persona::actualizarDatos() {
    string nuevoNombre, nuevoTelefono, nuevoCorreo;

    cout << "Nuevo nombre: ";
    getline(cin, nuevoNombre);
    cout << "Nuevo telefono: ";
    getline(cin, nuevoTelefono);
    cout << "Nuevo correo: ";
    getline(cin, nuevoCorreo);

    setNombre(nuevoNombre);
    setTelefono(nuevoTelefono);
    setCorreo(nuevoCorreo);
}