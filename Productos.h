#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <string>
using namespace std;

class Productos {
protected:
    int codigo;
    string nombre;
    double precio;
    int stock;
    string marca;
    string modelo;
    string material;
    int garantia;
    string compatibilidad;
    double peso;

public:
    Productos(int codigo, string nombre, double precio, int stock, string marca, string modelo, 
        string material, int garantia, string compatibilidad, double peso);

    virtual ~Productos() = default;

    int getCodigo() const;
    string getNombre() const;
    double getPrecio() const;
    int getStock() const;
    string getMarca() const;
    string getModelo() const;
    string getMaterial() const;
    int getGarantia() const;
    string getCompatibilidad() const;
    double getPeso() const;

    void setPrecio(double nuevoPrecio);
    bool reducirStock(int cantidad);
    void Productos::registrar(int codigo);
    void Productos::modificar(int nuevoProducto);
    void Productos::consultar(int nombre);

    virtual string getTipo() const;
};

#endif