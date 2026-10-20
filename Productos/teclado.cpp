#include <iostream>
#include "Teclado.h"
using namespace std;

Teclado::Teclado(string con, double cons, string t)
    : Periferico(con, cons) {
    tipo = t;
}

void Teclado::escribir() {
    string texto;

    cout << "Escriba una palabra: ";
    cin >> texto;

    cout << "Texto escrito: " << texto << endl;
}

void Teclado::presionarTecla() {
    char tecla;

    cout << "Tecla a presionar: ";
    cin >> tecla;

    cout << "Tecla presionada: " << tecla << endl;
}