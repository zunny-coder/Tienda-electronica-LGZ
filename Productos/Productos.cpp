#include "Productos.h"
#include <iostream>
using namespace std;

Productos::Productos(int codigo, string nombre, double precio, int stock, string marca, string modelo, 
        string material, int garantia, string compatibilidad, double peso) {
            
    this->codigo = codigo;
    this->nombre = nombre;
    this->precio = precio;
    this->stock = stock;
    this->marca = marca;
    this->modelo = modelo;
    this->material = material;
    this->garantia = garantia;
    this->compatibilidad = compatibilidad;
    this->peso = peso;
}

int Productos::getCodigo() const { return codigo; }
string Productos::getNombre() const { return nombre; }
double Productos::getPrecio() const { return precio; }
string Productos::getMarca() const { return marca; }
string Productos::getModelo() const { return modelo; }
string Productos::getMaterial() const { return material; }
int Productos::getGarantia() const { return garantia; }
string Productos::getCompatibilidad() const { return compatibilidad; }
double Productos::getPeso() const { return peso; }
int Productos::getStock() const { return stock; }

void Productos::setPrecio(double nuevoPrecio) {
    if (nuevoPrecio >= 0) {
        precio = nuevoPrecio;
    }
}

bool Productos::reducirStock(int cantidad) {
    if (cantidad <= 0 || cantidad > stock) {
        return false;
    }

    stock -= cantidad;
    return true;
}

    void Productos::registrar(int codigo, string nombre, double precio, string marca, string modelo, int garantia) {
    cout << "    DATOS DEL PRODUCTO    " << endl;
    cout<< "  | Nombre: " << nombre << endl;
    cout<< "  | Código: " << codigo << endl;
    cout<< "  | Precio: " << precio << endl;
    cout<< "  | Marca: " << marca << endl;
    cout<< "  | Modelo: " << modelo << endl;
    cout<< "  | Garantía: " << garantia << endl;
}
void Productos::modificar(int nuevoProducto) { cout << "Producto modificado." << nuevoProducto << endl; }
void Productos::consultar(int nombre) { cout << "Consultando producto: " << nombre << endl; }


string Productos::getTipo() const { return "Producto"; }