#include <iostream>
#include "accesorios.h"
using namespace std;

Accesorio::Accesorio(string t, int c, string cat, string col, string cal, string f)
    : Productos(0, "Accesorio", 0.0, 0, "", "", "", 0, "", 0) {
    tamano = t;
    cantidad = c;
    categoria = cat;
    color = col;
    calidad = cal;
    forma = f;
}

void Accesorio::Mostrar() const {
    cout << "--- ACCESORIO ---" << endl;
    cout << "Producto: " << getNombre() << " | Precio: " << getPrecio() << endl;
    cout << "Tamano: " << tamano << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Categoria: " << categoria << endl;
    cout << "Color: " << color << endl;
    cout << "Calidad: " << calidad << endl;
    cout << "Forma: " << forma << endl;
}

void Accesorio::Buscar() {
    string buscada;

    cout << "Categoria a buscar: ";
    cin >> buscada;

    if (buscada == categoria) {
        cout << "Accesorio encontrado." << endl;
        Mostrar();
    } else {
        cout << "No se encontro un accesorio de esa categoria." << endl;
    }
}

void Accesorio::Vender() {
    int cantidadVenta;

    cout << "Cantidad a vender: ";
    cin >> cantidadVenta;

    if (cantidadVenta <= 0) {
        cout << "Cantidad invalida." << endl;
    } else if (cantidadVenta > cantidad) {
        cout << "No hay suficiente stock. Disponible: " << cantidad << endl;
    } else {
        cantidad = cantidad - cantidadVenta;
        cout << "Venta realizada. Total: " << getPrecio() * cantidadVenta << endl;
        cout << "Quedan " << cantidad << " accesorios." << endl;
    }
}