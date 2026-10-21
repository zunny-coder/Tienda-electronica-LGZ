cmake_minimum_required(VERSION 3.21)

project(TiendaElectronicaLGZ LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

# Todas las clases, esten en la raiz o en subcarpetas
# (se excluyen: build, ventanas y el main de consola)
file(GLOB_RECURSE CLASES_CPP CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
list(FILTER CLASES_CPP EXCLUDE REGEX "/(build|ventanas)/")
list(FILTER CLASES_CPP EXCLUDE REGEX "main_consola\\.cpp$")
file(GLOB_RECURSE CLASES_H CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
list(FILTER CLASES_H EXCLUDE REGEX "/(build|ventanas)/")

qt_add_executable(TiendaElectronicaLGZ
    ${CLASES_CPP}
    ${CLASES_H}
    ventanas/VentanaPrincipal.h
    ventanas/VentanaPrincipal.cpp
)

# Imagenes dentro del .exe (recursos/imagenes/*.jpg, *.jpeg, *.png)
file(GLOB IMAGENES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS
    "recursos/imagenes/*.jpg"
    "recursos/imagenes/*.jpeg"
    "recursos/imagenes/*.png")
qt_add_resources(TiendaElectronicaLGZ "imagenes" PREFIX "/" FILES ${IMAGENES})

# Cada carpeta que tenga archivos .h entra a las rutas de #include
set(CARPETAS_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR})
foreach(h ${CLASES_H})
    get_filename_component(carpeta ${h} DIRECTORY)
    list(APPEND CARPETAS_INCLUDE ${carpeta})
endforeach()
list(REMOVE_DUPLICATES CARPETAS_INCLUDE)

target_include_directories(TiendaElectronicaLGZ
    PRIVATE ${CARPETAS_INCLUDE}
)

target_link_libraries(TiendaElectronicaLGZ
    PRIVATE Qt6::Widgets
)

file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/recursos")

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/recursos/estilos.qss"
    "${CMAKE_CURRENT_BINARY_DIR}/recursos/estilos.qss"
    COPYONLY
)