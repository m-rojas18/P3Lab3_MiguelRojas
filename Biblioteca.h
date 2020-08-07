// #include <iostream>
#include <string>
#include "Catalogo.h"

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

class Biblioteca {
    // atributos
    public:
        std:: string nombre;
        std:: string ubicacion;
        Catalogo ***arreglo;
        int cantidad_pisos;
        int cantidad_estantes;
        int cantidad_secciones;

    // contructor
    public:
        Biblioteca();
        Biblioteca(std:: string nombre, std:: string ubicacion, int cantidad_pisos, int cantidad_estantes, int cantidad_secciones);
        // crear el arreglo tridimensional
        // getters y setters
        std:: string getNombre();
        std:: string getUbicacion();
        int getCantidadPisos();
        int getCantidadEstantes();
        int getCantidadSecciones();
        Catalogo getCatalogo(int,int,int);
        void liberarArreglo();
        ~Biblioteca();

};

#endif