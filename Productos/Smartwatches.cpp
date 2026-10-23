#include "Smartwatches.h"

Smartwatches::Smartwatches(int codigo, string nombre, double precio, int stock, string tipo, 
    int almacenamiento, bool gps, int duracionBateria, string sistemaOperativo)
    : ProductosElectronicos(precio, to_string(codigo), "Marca", nombre, stock), 
        tipo(tipo), almacenamiento(almacenamiento), gps(gps), 
        duracionBateria(duracionBateria), sistemaOperativo(sistemaOperativo) {}

string Smartwatches::getTipo() const {
    return "Smartwatch";
}

int Smartwatches::getAlmacenamiento() const {
    return almacenamiento;
}

bool Smartwatches::getGPS() const {
    return gps;
}

int Smartwatches::getDuracionBateria() const {
    return duracionBateria;
}

string Smartwatches::getSistemaOperativo() const {
    return sistemaOperativo;
}

void Smartwatches::mostrarAplicaciones() const {
    cout << "Mostrando aplicaciones instaladas en el smartwatch." << endl;
}

void Smartwatches::notificaciones() const {
    cout << "   Tienes una nueva notificacion..." << endl;
}

void Smartwatches::actualizarSistema() const {
    cout << "   Actualizando..." << endl;
}

void Smartwatches::hacerLlamadas() const {
    cout << "   Haciendo llamada..." << endl;
}

void Smartwatches::contarPasos() const {
    int pasos = 100;
    cout << "   La cantidad de pasos que dio en este recorrido es: ";
    cout << pasos << endl;
}
void medirRitmoCardiaco() const { 
    double cardio = 80;
    cout<<" Ritmo cardiaco: "<<cardio<<" PPM"<<endl; 
}