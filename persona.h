#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona {
private:                       
    string dni;
    string nombre;
    string telefono;
    string correo;

public:
    Persona(string d, string n, string t, string c);

   
    string getDni();
    string getNombre();
    string getTelefono();
    string getCorreo();

   
    void setDni(string d);
    void setNombre(string n);
    void setTelefono(string t);
    void setCorreo(string c);

    
    virtual void mostrarDatos() const = 0;

   
    virtual void actualizarDatos();
};

#endif