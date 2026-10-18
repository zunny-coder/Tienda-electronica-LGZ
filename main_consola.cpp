#include <iostream>
#include "Productos.h"
#include "ProductosElectronicos.h"
#include "Computadora.h"
#include "Laptop.h"
#include "Celular.h"
#include "Impresora.h"
#include "Smartwatches.h"
using namespace std;

int main() {

    Computadora computadora(1001, "Computadora", 1500.0, 10, "Intel i7", 16, 512, "USB-C", 
        "15.6 pulgadas", "NVIDIA GTX 1660", "Windows 10");
        cout << "Tipo: "<< computadora.getTipo() << endl;
        cout << "Encender: " << computadora.getEncender() << endl;
        cout << "Procesador: " << computadora.getProcesador() << endl;
        cout << "RAM: " << computadora.getMemoriaRAM() << " GB" << endl;
        cout << "Almacenamiento: " << computadora.getAlmacenamiento() << " GB" << endl;
        cout << "Sistema Operativo: " << computadora.getSistemaOperativo() << endl;

    Laptop Laptop(1002, "Laptop", 1200.0, 5, "Intel i5", 8);
        cout << "Tipo: " << Laptop.getTipo() << endl;
        cout << "Encender: " << Laptop.getEncender() << endl;
        cout << "Procesador: " << Laptop.getProcesador() << endl;
        cout << "RAM: " << Laptop.getMemoriaRAM() << " GB" << endl;

    Celular celular(1003, "Celular", 800.0, 20, "Snapdragon 888", 8, "Galaxy S21", "128GB");
        cout << "Tipo: " << celular.getTipo() << endl;
        cout << "Encender: " << celular.getEncender() << endl;
        cout << "Procesador: " << celular.getProcesador() << endl;
        cout << "RAM: " << celular.getMemoriaRAM() << " GB" << endl;
        cout << "Almacenamiento: " << celular.getAlmacenamiento() << " GB" << endl;

    Impresora impresora(1004, "Impresora", 300.0, 15, "Inyección de tinta", 20, 80, 100, "Configuración predeterminada", true);
        cout << "Tipo: " << impresora.getTipo() << endl;
        cout << "Encender: " << impresora.getEncender() << endl;
        cout << "Velocidad de impresión: " << impresora.getVelocidadImpresion() << " ppm" << endl;
        cout << "Nivel de tinta: " << impresora.getNivelTinta() << "%" << endl;
        cout << "Cantidad de papel: " << impresora.getCantidadPapel() << " hojas" << endl;
        cout << "Configuración: " << impresora.getConfiguracion() << endl;
        cout << "Color: " << (impresora.getColor() ? "Sí" : "No") << endl;

    Smartwatches smartwatch(1005, "Smartwatch", 250.0, 8, "Deportivo", 16, true, 48, "Wear OS");
        cout << "Tipo: " << smartwatch.getTipo() << endl;
        cout << "Encender: " << smartwatch.getEncender() << endl;
        cout << "Material: " << smartwatch.getMaterial() << endl;
        cout << "Almacenamiento: " << smartwatch.getAlmacenamiento() << " GB" << endl;
        cout << "GPS: " << (smartwatch.getGPS() ? "Sí" : "No") << endl;
        cout << "Batería: " << smartwatch.getBateria() << " mAh" << endl;
        cout << "Sistema Operativo: " << smartwatch.getSistemaOperativo() << endl;

    return 0;
}
