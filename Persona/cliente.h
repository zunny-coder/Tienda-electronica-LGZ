#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

class Cliente : public Persona {
public:
    Cliente(string d, string n, string t, string c);

    void comprar();
    void consultarProducto();
    void realizarPedido();

    
    void mostrarDatos() const override;
};

#endif
