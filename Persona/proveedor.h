#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "Persona.h"

class Proveedor : public Persona {
private:
    string RUC;
    int stock;
    string codigo;

public:
    Proveedor(string d, string n, string t, string c,
              string r, int s, string cod);

    
    string getRUC();
    int getStock();
    string getCodigo();

   
    void setRUC(string r);
    void setStock(int s);
    void setCodigo(string cod);

    void suministrarProducto();
    void actualizarStock();
    int consultarStock();

   
    void mostrarDatos() const override;
};

#endif