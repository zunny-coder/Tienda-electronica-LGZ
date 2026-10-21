# Tienda Electrónica LGZ

## Paso 1: 

1. Descargar el instalador de Qt desde https://www.qt.io/download-open-source
2. Ejecutarlo e iniciar sesión con una cuenta.
3. En la pantalla **Select Components**, marcar:
   - **Qt → Qt 6.12.0 → MinGW 64-bit**
   - **Build Tools → MinGW 13.1.0 64-bit**
   - **Build Tools → CMake**
   - **Build Tools → Ninja**
   - **Qt Creator** (ya viene marcado)
4. Pulsar **Next** hasta terminar la instalación.

## Paso 2: 

1. Descomprimir el ZIP del proyecto en github dentro de `C:\`
2. Entrar a la carpeta hasta ver el archivo `CMakeLists.txt`.

## Paso 3: 

1. Abrir **Qt Creator**.
2. Ir a **File → Open File or Project**.
3. Elegir el archivo `CMakeLists.txt` de la carpeta del proyecto.
4. Seleccionar el kit **Desktop Qt 6.12.0 MinGW 64-bit**.
5. Pulsar **Configure Project**.

## Paso 4: 
1. Pulsar el botón verde **Run** (triángulo abajo a la izquierda) o presionar `Ctrl + R`.
2. Esperar a que termine de compilar.
