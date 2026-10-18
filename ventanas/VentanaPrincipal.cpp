#include "VentanaPrincipal.h"

#include <QApplication>
#include <QCoreApplication>
#include <QFile>
#include <QFrame>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include <QPushButton>
#include <QStackedWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QAbstractItemView>
#include <QMessageBox>
#include <QStringList>
#include <QStyle>
#include <QPixmap>
#include <QDebug>
#include <QImageReader>
#include <QDir>

#include "Productos.h"
#include "cliente.h"
#include "empleado.h"
#include "proveedor.h"

static void agregarFila(QTableWidget *tabla, const QStringList &valores)
{
    const int fila = tabla->rowCount();
    tabla->insertRow(fila);

    for (int col = 0; col < valores.size(); ++col) {
        tabla->setItem(fila, col, new QTableWidgetItem(valores[col]));
    }
}

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QMainWindow(parent),
      paginas(nullptr),
      tituloSeccion(nullptr)
{
    setWindowTitle("Tienda Electronica LGZ");
    resize(1150, 720);
    setMinimumSize(850, 560);

    cargarEstilos();
    crearInterfaz();
}

void VentanaPrincipal::cargarEstilos()
{
    const QString ruta =
        QCoreApplication::applicationDirPath()
        + "/recursos/estilos.qss";

    QFile archivo(ruta);

    if (archivo.open(QFile::ReadOnly | QFile::Text)) {
        const QString estilos =
            QString::fromUtf8(archivo.readAll());

        qApp->setStyleSheet(estilos);
        archivo.close();
    } else {
        qWarning("No se pudo cargar recursos/estilos.qss");
    }
}

void VentanaPrincipal::crearInterfaz()
{
    QWidget *central = new QWidget(this);
    central->setObjectName("ventanaPrincipal");
    setCentralWidget(central);

    QHBoxLayout *principal = new QHBoxLayout(central);
    principal->setContentsMargins(0, 0, 0, 0);
    principal->setSpacing(0);

    // MENU LATERAL
    QFrame *sidebar = new QFrame;
    sidebar->setObjectName("sidebar");
    sidebar->setFixedWidth(225);

    QVBoxLayout *menu = new QVBoxLayout(sidebar);
    menu->setContentsMargins(16, 25, 16, 20);
    menu->setSpacing(9);

    QLabel *marca = new QLabel("Tienda Electronica LGZ");
    marca->setObjectName("marca");
    marca->setWordWrap(true);    
    menu->addWidget(marca);
    menu->addSpacing(28);

    QLabel *tituloMenu = new QLabel("MENU PRINCIPAL");
    tituloMenu->setObjectName("submarca");
    menu->addWidget(tituloMenu);
    menu->addSpacing(5);

    const QStringList nombres = {
        "Inicio",
        "Productos",
        "Clientes",
        "Empleados",
        "Proveedores"
    };

    for (int i = 0; i < nombres.size(); ++i) {
        QPushButton *boton = new QPushButton(nombres[i]);
        boton->setObjectName("nav");
        boton->setCursor(Qt::PointingHandCursor);
        boton->setMinimumHeight(43);
        boton->setProperty("active", i == 0);

        botonesMenu.append(boton);
        menu->addWidget(boton);

        connect(boton, &QPushButton::clicked,
                this, [this, i]() {
                    cambiarPagina(i);
                });
    }

    menu->addStretch();

    QLabel *pieMenu = new QLabel(
        "Sistema de gestion\nTienda Electronica LGZ"
    );
    pieMenu->setObjectName("submarca");
    pieMenu->setWordWrap(true);
    menu->addWidget(pieMenu);

    // AREA PRINCIPAL
    QWidget *contenido = new QWidget;
    contenido->setObjectName("contenido");

    QVBoxLayout *area = new QVBoxLayout(contenido);
    area->setContentsMargins(0, 0, 0, 0);
    area->setSpacing(0);

    QFrame *barraSuperior = new QFrame;
    barraSuperior->setObjectName("barraSuperior");

    QHBoxLayout *barra = new QHBoxLayout(barraSuperior);
    barra->setContentsMargins(25, 16, 25, 16);

    tituloSeccion = new QLabel("Inicio");
    tituloSeccion->setObjectName("tituloBarra");

    QLabel *usuario = new QLabel("ADMINISTRACION");
    usuario->setObjectName("etiquetaRosa");

    barra->addWidget(tituloSeccion);
    barra->addStretch();
    barra->addWidget(usuario);

    area->addWidget(barraSuperior);

    paginas = new QStackedWidget;
    paginas->setObjectName("paginas");

    paginas->addWidget(crearInicio());

    paginas->addWidget(crearPaginaGestion(
        "Productos",
        "Catalogo de productos de la tienda.",
        {"Codigo", "Nombre", "Categoria", "Precio", "Stock"},
        tablaProductos
    ));

    paginas->addWidget(crearPaginaGestion(
        "Clientes",
        "Consulta y administra los clientes.",
        {"DNI", "Nombre", "Telefono", "Correo"},
        tablaClientes
    ));

    paginas->addWidget(crearPaginaGestion(
        "Empleados",
        "Consulta y administra los empleados.",
        {"DNI", "Nombre", "Telefono", "Correo", "Cargo", "Horario", "Sueldo"},
        tablaEmpleados
    ));

    paginas->addWidget(crearPaginaGestion(
        "Proveedores",
        "Consulta y administra los proveedores.",
        {"DNI", "Nombre", "Telefono", "Correo", "RUC", "Codigo", "Stock"},
        tablaProveedores
    ));

    area->addWidget(paginas, 1);

    principal->addWidget(sidebar);
    principal->addWidget(contenido, 1);
}

QWidget *VentanaPrincipal::crearInicio()
{
    QWidget *pagina = new QWidget;

    QVBoxLayout *layout = new QVBoxLayout(pagina);
    layout->setContentsMargins(28, 25, 28, 25);
    layout->setSpacing(16);

    QLabel *titulo = new QLabel("¡Bienvenidooo :3 !");
    titulo->setObjectName("tituloPagina");

    QLabel *descripcion = new QLabel(
        "Administra tu tienda desde un solo lugar."
    );
    descripcion->setObjectName("descripcion");
    descripcion->setWordWrap(true);

    layout->addWidget(titulo);
    layout->addWidget(descripcion);
    layout->addSpacing(8);

    QHBoxLayout *tarjetas = new QHBoxLayout;
    tarjetas->setSpacing(14);

    const QStringList nombres = {
        "Productos", "Clientes", "Personal"
    };

    const QStringList detalles = {
        "Catalogo electronico",
        "Gestion de clientes",
        "Empleados y proveedores"
    };

    const QStringList numeros = {"01", "02", "03"};

    for (int i = 0; i < nombres.size(); ++i) {
        QFrame *tarjeta = new QFrame;
        tarjeta->setObjectName("tarjeta");
        tarjeta->setMinimumHeight(145);

        QVBoxLayout *contenido = new QVBoxLayout(tarjeta);
        contenido->setContentsMargins(17, 17, 17, 17);

        QLabel *numero = new QLabel(numeros[i]);
        numero->setObjectName("numeroTarjeta");

        QLabel *nombre = new QLabel(nombres[i]);
        nombre->setObjectName("tituloTarjeta");

        QLabel *detalle = new QLabel(detalles[i]);
        detalle->setObjectName("descripcion");
        detalle->setWordWrap(true);

        contenido->addWidget(numero);
        contenido->addWidget(nombre);
        contenido->addWidget(detalle);
        contenido->addStretch();

        tarjetas->addWidget(tarjeta);
    }

    layout->addLayout(tarjetas);
    layout->addSpacing(12);

    QLabel *subtitulo = new QLabel("RECOMENDADOS");
    subtitulo->setObjectName("etiquetaRosa");
    layout->addWidget(subtitulo);

    layout->addWidget(crearRecomendados());

    QLabel *nota = new QLabel(
        "Selecciona una seccion del menu lateral para comenzar. "

    );
    nota->setObjectName("descripcion");
    nota->setWordWrap(true);

    layout->addWidget(nota);
    layout->addStretch();

    return pagina;
}

QWidget *VentanaPrincipal::crearPaginaGestion(
    const QString &titulo,
    const QString &descripcion,
    const QStringList &columnas,
    QTableWidget *&tablaDestino)
{
    QWidget *pagina = new QWidget;

    QVBoxLayout *layout = new QVBoxLayout(pagina);
    layout->setContentsMargins(28, 24, 28, 24);
    layout->setSpacing(16);

    QLabel *encabezado = new QLabel(titulo);
    encabezado->setObjectName("tituloPagina");

    QLabel *detalle = new QLabel(descripcion);
    detalle->setObjectName("descripcion");
    detalle->setWordWrap(true);

    QLineEdit *busqueda = new QLineEdit;
    busqueda->setObjectName("busqueda");
    busqueda->setPlaceholderText("Buscar por nombre o codigo...");

    QTableWidget *tabla = new QTableWidget(0, columnas.size());
    tabla->setObjectName("tablaDatos");
    tabla->setHorizontalHeaderLabels(columnas);
    tabla->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch
    );
    tabla->verticalHeader()->setVisible(false);
    tabla->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabla->setSelectionBehavior(QAbstractItemView::SelectRows);
    tabla->setSelectionMode(QAbstractItemView::SingleSelection);
    tabla->setShowGrid(false);

    tablaDestino = tabla;

    connect(busqueda, &QLineEdit::textChanged,
            this, [tabla, columnas](const QString &texto) {
                for (int fila = 0; fila < tabla->rowCount(); ++fila) {
                    bool coincide = false;

                    for (int col = 0; col < columnas.size(); ++col) {
                        QTableWidgetItem *item =
                            tabla->item(fila, col);

                        if (item &&
                            item->text().contains(
                                texto, Qt::CaseInsensitive)) {
                            coincide = true;
                            break;
                        }
                    }

                    tabla->setRowHidden(fila, !coincide);
                }
            });

    layout->addWidget(encabezado);
    layout->addWidget(detalle);
    layout->addWidget(busqueda);
    layout->addWidget(tabla, 1);

    return pagina;
}

QWidget *VentanaPrincipal::crearRecomendados()
{
    struct Item {
        QString nombre;
        QString precio;
        QString imagen;
    };

    QString rutaBase = QCoreApplication::applicationDirPath() + "/../recursos/imagenes";

    const QList<Item> items = {
        {"Samsung Galaxy A54", "S/ 1399.00", rutaBase + "/celular.jpg"},
        {"Lenovo IdeaPad 3",   "S/ 1799.00", rutaBase + "/laptop.jpg"},
        {"HP All-in-One 24",   "S/ 2999.00", rutaBase + "/computadora.jpg"}
    };

    QWidget *fila = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout(fila);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(14);

    for (const Item &item : items) {
        QFrame *tarjeta = new QFrame;
        tarjeta->setObjectName("tarjeta");

        QVBoxLayout *contenido = new QVBoxLayout(tarjeta);
        contenido->setContentsMargins(17, 17, 17, 17);
        contenido->setSpacing(8);

        QLabel *foto = new QLabel;
        foto->setAlignment(Qt::AlignCenter);
        foto->setMinimumHeight(140);
        foto->setMaximumHeight(160);

        qDebug() << "Intentando cargar imagen desde:" << item.imagen;

        QPixmap pixmap(item.imagen);

        if (!pixmap.isNull()) {
            foto->setPixmap(
                pixmap.scaled(280, 140, Qt::KeepAspectRatio, Qt::SmoothTransformation)
            );
        } else {
            qWarning() << "¡Fallo al cargar! La ruta exacta es:" << item.imagen;
            foto->setText("Sin imagen");
            foto->setObjectName("descripcion");
        }

        QLabel *nombre = new QLabel(item.nombre);
        nombre->setObjectName("tituloTarjeta");

        QLabel *precio = new QLabel(item.precio);
        precio->setObjectName("descripcion");

        contenido->addWidget(foto);
        contenido->addWidget(nombre);
        contenido->addWidget(precio);

        layout->addWidget(tarjeta);
    }

    return fila;
} 

void VentanaPrincipal::cargarProductos(const std::vector<Productos*> &lista)
{
    tablaProductos->setRowCount(0);

    for (Productos *p : lista) {
        agregarFila(tablaProductos, {
            QString::number(p->getCodigo()),
            QString::fromStdString(p->getNombre()),
            QString::fromStdString(p->getTipo()),
            "S/ " + QString::number(p->getPrecio(), 'f', 2),
            QString::number(p->getStock())
        });
    }
}

void VentanaPrincipal::cargarClientes(const std::vector<Cliente*> &lista)
{
    tablaClientes->setRowCount(0);

    for (Cliente *c : lista) {
        agregarFila(tablaClientes, {
            QString::fromStdString(c->getDni()),
            QString::fromStdString(c->getNombre()),
            QString::fromStdString(c->getTelefono()),
            QString::fromStdString(c->getCorreo())
        });
    }
}

void VentanaPrincipal::cargarEmpleados(const std::vector<Empleado*> &lista)
{
    tablaEmpleados->setRowCount(0);

    for (Empleado *e : lista) {
        const QString sueldo = e->getSueldo() > 0
            ? "S/ " + QString::number(e->getSueldo(), 'f', 2)
            : QString("-");

        agregarFila(tablaEmpleados, {
            QString::fromStdString(e->getDni()),
            QString::fromStdString(e->getNombre()),
            QString::fromStdString(e->getTelefono()),
            QString::fromStdString(e->getCorreo()),
            QString::fromStdString(e->getCargo()),
            QString::fromStdString(e->getHorario()),
            sueldo
        });
    }
}

void VentanaPrincipal::cargarProveedores(const std::vector<Proveedor*> &lista)
{
    tablaProveedores->setRowCount(0);

    for (Proveedor *p : lista) {
        agregarFila(tablaProveedores, {
            QString::fromStdString(p->getDni()),
            QString::fromStdString(p->getNombre()),
            QString::fromStdString(p->getTelefono()),
            QString::fromStdString(p->getCorreo()),
            QString::fromStdString(p->getRUC()),
            QString::fromStdString(p->getCodigo()),
            QString::number(p->getStock())
        });
    }
}

void VentanaPrincipal::cambiarPagina(int indice)
{
    if (indice < 0 || indice >= paginas->count()) {
        return;
    }

    paginas->setCurrentIndex(indice);

    const QStringList nombres = {
        "Inicio", "Productos", "Clientes",
        "Empleados", "Proveedores"
    };

    tituloSeccion->setText(nombres[indice]);

    for (int i = 0; i < botonesMenu.size(); ++i) {
        botonesMenu[i]->setProperty("active", i == indice);
        botonesMenu[i]->style()->unpolish(botonesMenu[i]);
        botonesMenu[i]->style()->polish(botonesMenu[i]);
        botonesMenu[i]->update();
    }
}