#ifndef SMARTWATCHES_H
#define SMARTWATCHES_H

#include "ProductosElectronicos.h"

class Smartwatches : public ProductosElectronicos {
private:
    string tipo;
    int almacenamiento;
    bool gps;
    int duracionBateria;
    string sistemaOperativo;

public:
    Smartwatches(int codigo, string nombre, double precio, int stock, string tipo, 
        int almacenamiento, bool gps, int duracionBateria, string sistemaOperativo);
    string getTipo() const;
    int getAlmacenamiento() const;
    bool getGPS() const;
    int getDuracionBateria() const;
    string getSistemaOperativo() const;

    void mostrarAplicaciones() const;
    void notificaciones() const;
    void actualizarSistema() const;
    void hacerLlamadas() const;
    void contarPasos() const;
    void medirRitmoCardiaco() const;
};

#endif // SMARTWATCHES_H