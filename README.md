# Tienda Electrónica LGZ

## Pasos para ejecutar el programa: 

1. Descargar el instalador de Qt desde https://www.qt.io/download-open-source
2. Ejecutarlo e iniciar sesión con una cuenta.
3. En la pantalla **Select Components**, marcar:
   - **Qt → Qt 6.12.0 → MinGW 64-bit**
   - **Build Tools → MinGW 13.1.0 64-bit**
   - **Build Tools → CMake**
   - **Build Tools → Ninja**
   - **Qt Creator** (ya viene marcado)
4. Pulsar **Next** hasta terminar la instalación.
5. Descargar el archivo desde github y descomprimir.
6. Abre Visual Studio Code.
7. Ve a Archivo → Abrir carpeta... y selecciona la carpeta principal del proyecto (Tienda-electronica-LGZ-main).

## Compilación del Proyecto por Comandos
Para compilar el proyecto de forma rápida y segura desde la terminal integrada de VS Code, realiza lo siguiente:

1. Abre la terminal integrada presionando las teclas Ctrl + ` (o ve a Terminal → Nueva terminal).
2. Asegúrate de estar posicionado en la carpeta principal del proyecto y crea una carpeta de compilación ejecutando (por separado):

mkdir build
cd build
cmake -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="C:/Qt/6.12.0/mingw_64" ..
cmake --build .
 
con esto deberia de generarse una carpeta llamada build, al tenerla ya en el explorador ejecutar: 

.\TiendaElectronicaLGZ.exe

