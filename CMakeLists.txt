cmake_minimum_required(VERSION 3.21)

project(TiendaElectronicaLGZ LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

# Todas las clases de la raiz, menos el main de consola
file(GLOB CLASES_CPP CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
list(FILTER CLASES_CPP EXCLUDE REGEX "main_consola\\.cpp$")
file(GLOB CLASES_H CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

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

target_include_directories(TiendaElectronicaLGZ
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
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