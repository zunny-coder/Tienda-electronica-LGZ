#include <iostream>
#include "Periferico.h"
using namespace std;

Periferico::Periferico(string con, double cons)
    : ProductosElectronicos(0.0, "0", "", "Periferico"),
      conexion(con), consumoEnergia(cons) {}

void Periferico::verificarConexion() {
    cout << "Verificando conexion " << conexion << "..." << endl;
    if (conexion == "") {
        cout << "Sin conexion." << endl;
    } else {
        cout << "Conexion establecida." << endl;
    }
}

void Periferico::mostrar() const {
    cout << "--- PERIFERICO ---" << endl;
    cout << "Producto: " << getNombre() << " | Precio: " << getPrecio() << endl;
    cout << "Conexion: " << conexion << endl;
    cout << "Consumo de energia: " << consumoEnergia << endl;
}