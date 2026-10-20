#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"

class Empleado : public Persona {
private:
    double sueldo;
    string horario;
    string cargo;

public:
    Empleado(string d, string n, string t, string c,
             double su, string h, string ca);

    
    double getSueldo();
    string getHorario();
    string getCargo();

    
    void setSueldo(double su);
    void setHorario(string h);
    void setCargo(string ca);

    void registrarVenta();
    void consultarProducto();
    void actualizarStock();

    
    void mostrarDatos() const override;
};

#endif