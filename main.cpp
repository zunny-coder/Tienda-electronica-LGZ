#include <QApplication>
#include <vector>

#include "ventanas/VentanaPrincipal.h"
#include "Productos.h"
#include "Computadora.h"
#include "Laptop.h"
#include "Celular.h"
#include "cliente.h"
#include "empleado.h"
#include "proveedor.h"
#include "Impresora.h"
#include "Smartwatches.h"
#include "Funda.h"
#include "Audifonos.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setApplicationName("TiendaElectronicaLGZ");
    app.setOrganizationName("LGZ");

    VentanaPrincipal ventana;

        auto catalogo = [](Productos *p, int codigo, const std::string &nombre,
                       double precio, int stock, const std::string &categoria) {
        p->configurar(codigo, nombre, precio, stock, categoria);
        return p;
    };
        std::vector<Productos*> productos = {
        // Computadoras
        new Computadora(1001, "Dell Inspiron 3910", 2499.0, 6, "Intel i5", 8, 512,
                        "USB-C", "21.5 pulgadas", "Intel UHD", "Windows 11"),
        new Computadora(1002, "HP All-in-One 24", 2999.0, 4, "Intel i7", 16, 512,
                        "USB-C", "23.8 pulgadas", "Intel Iris Xe", "Windows 11"),
        new Computadora(1003, "Lenovo IdeaCentre 3", 2199.0, 7, "AMD Ryzen 5", 8, 256,
                        "USB-C", "21.5 pulgadas", "AMD Radeon", "Windows 11"),
        new Computadora(1004, "ASUS ExpertCenter", 3499.0, 3, "Intel i7", 32, 1000,
                        "USB-C", "27 pulgadas", "NVIDIA GTX 1660", "Windows 11"),
        new Computadora(1005, "Acer Aspire XC", 2099.0, 8, "Intel i5", 8, 512,
                        "USB-C", "21.5 pulgadas", "Intel UHD", "Windows 11"),
        new Computadora(1006, "Lenovo ThinkCentre Neo", 2799.0, 5, "Intel i7", 16, 512,
                        "USB-C", "23.8 pulgadas", "Intel Iris Xe", "Windows 11"),

        
        // Laptops
        new Laptop(2001, "Lenovo IdeaPad 3", 1799.0, 12, "AMD Ryzen 5", 8),
        new Laptop(2002, "HP 15 Laptop", 2099.0, 9, "Intel i5", 8),
        new Laptop(2003, "ASUS Vivobook 15", 2399.0, 5, "Intel i5", 16),
        new Laptop(2004, "Acer Aspire 5", 2199.0, 7, "Intel i5", 8),
        new Laptop(2005, "Dell Inspiron 15", 2599.0, 4, "Intel i7", 16),
        new Laptop(2006, "Apple MacBook Air M2", 5299.0, 3, "Apple M2", 8),
        new Laptop(2007, "ASUS TUF Gaming F15", 3999.0, 4, "Intel i7", 16),
        new Laptop(2008, "HP Pavilion 14", 2699.0, 6, "AMD Ryzen 7", 16),
        new Laptop(2009, "Acer Nitro 5", 3799.0, 3, "Intel i5", 16),
        new Laptop(2010, "Lenovo ThinkPad E14", 3199.0, 5, "Intel i5", 16),

        // Celulares
        new Celular(3001, "Samsung Galaxy A54", 1399.0, 20, "Exynos 1380", 8, "A54", "128GB"),
        new Celular(3002, "Xiaomi Redmi Note 13", 899.0, 25, "Snapdragon 685", 8, "Note 13", "256GB"),
        new Celular(3003, "Apple iPhone 14", 3599.0, 8, "A15 Bionic", 6, "iPhone 14", "128GB"),
        new Celular(3004, "Motorola Moto G54", 799.0, 15, "Dimensity 7020", 8, "G54", "256GB"),
        new Celular(3005, "Honor X8b", 949.0, 12, "Snapdragon 680", 8, "X8b", "256GB"),
        new Celular(3006, "Samsung Galaxy S23", 3299.0, 10, "Snapdragon 8 Gen 2", 8, "S23", "256GB"),
        new Celular(3007, "Xiaomi Poco X6", 1099.0, 18, "Snapdragon 7s Gen 2", 8, "X6", "256GB"),
        new Celular(3008, "Apple iPhone 13", 2899.0, 7, "A15 Bionic", 4, "iPhone 13", "128GB"),
        new Celular(3009, "Motorola Edge 40", 1699.0, 9, "Dimensity 8020", 8, "Edge 40", "256GB"),
        new Celular(3010, "Honor 90 Lite", 849.0, 14, "Dimensity 6020", 8, "90 Lite", "256GB"),
    
        // Impresoras
                new Impresora(4001, "Epson EcoTank L3250", 899.0, 10, "Inyeccion de tinta", 10, 100, 100, "WiFi", true),
        new Impresora(4002, "HP Smart Tank 580", 949.0, 8, "Inyeccion de tinta", 12, 100, 100, "WiFi", true),
        new Impresora(4003, "Canon Pixma G3110", 799.0, 12, "Inyeccion de tinta", 9, 100, 100, "WiFi", true),
        new Impresora(4004, "Brother DCP-T520W", 859.0, 6, "Inyeccion de tinta", 11, 100, 100, "WiFi", true),

        new Smartwatches(5001, "Apple Watch SE", 1299.0, 9, "Deportivo", 32, true, 18, "watchOS"),
        new Smartwatches(5002, "Samsung Galaxy Watch 6", 1199.0, 11, "Deportivo", 16, true, 40, "Wear OS"),
        new Smartwatches(5003, "Huawei Watch Fit 3", 599.0, 14, "Fitness", 4, true, 240, "HarmonyOS"),
        new Smartwatches(5004, "Xiaomi Watch 2", 549.0, 16, "Casual", 32, true, 65, "Wear OS")
     
                // Fundas
        catalogo(new Funda("Grande", 20, "Negro", "Alta", "Rectangular"),
                 6001, "Spigen Funda Galaxy A54", 59.0, 30, "Funda"),
        catalogo(new Funda("Mediano", 15, "Azul", "Media", "Rectangular"),
                 6002, "OtterBox Funda iPhone 14", 129.0, 15, "Funda"),
        catalogo(new Funda("Grande", 25, "Transparente", "Alta", "Rectangular"),
                 6003, "Samsung Funda Galaxy S23", 99.0, 20, "Funda"),

        // Audifonos
        catalogo(new Audifonos("Bluetooth", 0.5, 50),
                 7001, "JBL Tune 510BT", 159.0, 25, "Audifonos"),
        catalogo(new Audifonos("Cable 3.5mm", 0.1, 40),
                 7002, "Sony MDR-ZX110", 79.0, 30, "Audifonos"),
        catalogo(new Audifonos("Bluetooth", 0.4, 60),
                 7003, "Xiaomi Redmi Buds 4", 119.0, 18, "Audifonos")
    };

    std::vector<Cliente*> clientes = {
        new Cliente("70215483", "Alquimia", "987123456", "alquimia@gmail.com"),
        new Cliente("45678123", "María",    "954321876", "maria@gmail.com"),
        new Cliente("72341890", "Juan",     "962874135", "juan@gmail.com"),
        new Cliente("41826739", "Pedro",    "981456723", "pedro@gmail.com"),
        new Cliente("70983124", "José",     "947213658", "jose@gmail.com"),
        new Cliente("73215846", "Rocio",    "995312784", "rocio@gmail.com"),
        new Cliente("46231987", "Juana",    "936528417", "juana@gmail.com"),
        new Cliente("75012364", "Andrea",   "978456123", "andrea@gmail.com"),
        new Cliente("43178952", "Roberto",  "951874236", "roberto@gmail.com"),
        new Cliente("40567218", "Américo",  "964123897", "americo@gmail.com"),
        new Cliente("76432109", "Joan",     "983647215", "joan@gmail.com"),
        new Cliente("44819365", "Lida",     "927583146", "lida@gmail.com")
    };

    std::vector<Empleado*> empleados = {
        new Empleado("71162420", "Zunny Mamani", "917058536", "zunnymamani@est.unap.edu.pe", 7000.0, "Lun-Vie 11am-4pm", "Gerente"),
        new Empleado("73581649", "Lourdes Cabana", "963447086", "lourdescabana@est.unap.edu.pe", 5000.0, "Lun-Vie 8am-4pm", "Gerente"),
        new Empleado("61152643", "Georgina Martinez", "950505307", "georginamartinez@est.unap.edu.pe", 5000.0, "Lun-Vie 8am-5pm", "Gerente"),
        new Empleado("60908881", "Crhristian Cutipa", "910514666", "christiancutipa@gmail.com", 1300.0, "Lun-Dom 8am-9pm", "Limpieza")
    }; 
    std::vector<Proveedor*> proveedores = {
        new Proveedor("62878901", "TechSupply" , "987561209", "techsupply@gmail.com", "RUC4568890", 100, "PROV001"),
        new Proveedor("62878902", "ElectroWorld" , "987561210", "electroworld@gmail.com", "RUC4568891", 150, "PROV002")
    };

    ventana.cargarProductos(productos);
    ventana.cargarClientes(clientes);
    ventana.cargarEmpleados(empleados);
    ventana.cargarProveedores(proveedores);

    ventana.show();

    return app.exec();
}