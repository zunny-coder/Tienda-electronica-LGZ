#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QList>
#include <QStringList>
#include <vector>

class QStackedWidget;
class QLabel;
class QPushButton;
class QTableWidget;
class QLineEdit;
class QSpinBox;

class Productos;
class Cliente;
class Empleado;
class Proveedor;

class VentanaPrincipal : public QMainWindow
{
public:
    explicit VentanaPrincipal(QWidget *parent = nullptr);

    void cargarProductos(const std::vector<Productos*> &lista);
    void cargarClientes(const std::vector<Cliente*> &lista);
    void cargarEmpleados(const std::vector<Empleado*> &lista);
    void cargarProveedores(const std::vector<Proveedor*> &lista);

private:
    void cargarEstilos();
    void crearInterfaz();
    QWidget *crearInicio();
    QWidget *crearRecomendados();
    QWidget *crearPaginaGestion(const QString &titulo,
                                const QString &descripcion,
                                const QStringList &columnas,
                                QTableWidget *&tablaDestino);
    void cambiarPagina(int indice);

    QStackedWidget *paginas;
    QLabel *tituloSeccion;
    QList<QPushButton*> botonesMenu;

    QTableWidget *tablaProductos = nullptr;
    QTableWidget *tablaClientes = nullptr;
    QTableWidget *tablaEmpleados = nullptr;
    QTableWidget *tablaProveedores = nullptr;

    QWidget *crearPaginaVenta();
    void registrarVenta();
    void refrescarTablaProductos();
    Productos *buscarProducto(int codigo) const;

    std::vector<Productos*> listaProductos;
    QLineEdit *ventaCodigo = nullptr;
    QSpinBox *ventaCantidad = nullptr;
    QLabel *ventaInfo = nullptr;
    QLabel *ventaMensaje = nullptr;
};

#endif