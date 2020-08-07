#include "Catalogo.h"
#include "Biblioteca.h"
#include <string>

Biblioteca::Biblioteca(){}
Biblioteca::Biblioteca(std:: string nombre, std:: string ubicacion, int cantidad_pisos, int cantidad_estantes, int cantidad_secciones) {
    this -> nombre = nombre;
    this -> ubicacion = ubicacion;
    this -> cantidad_pisos = cantidad_pisos;
    this -> cantidad_estantes = cantidad_estantes;
    this -> cantidad_secciones = cantidad_secciones;

    //Creacion de arreglo tridimensional
    arreglo = new Catalogo**[cantidad_pisos];
    for(int i =0; i < cantidad_pisos; i++){
        arreglo[i] = new Catalogo*[cantidad_estantes];
        for(int j =0; j < cantidad_estantes; j++){
            arreglo[i][j] = new Catalogo[cantidad_secciones];
        }
    }
}

std:: string Biblioteca:: getNombre(){
    return nombre;
}

std:: string Biblioteca:: getUbicacion(){
    return ubicacion;
}

int Biblioteca:: getCantidadPisos(){
    return cantidad_pisos;
}
int Biblioteca:: getCantidadEstantes(){
    return cantidad_estantes;
}
int Biblioteca:: getCantidadSecciones(){
    return cantidad_secciones;
}

Catalogo Biblioteca:: getCatalogo(int posicion_piso, int posicion_estante, int posicion_seccion){
    return arreglo[posicion_piso][posicion_estante][posicion_seccion]
    ;
}

void Biblioteca::liberarArreglo(){
    for ( int i = 0; i < cantidad_pisos; i++ ){
        for ( int j = 0; j < cantidad_estantes; j++ ){
            delete[] arreglo[i][j];
        }
        delete[] arreglo[i];
    }
    delete[] arreglo;
}

// implementación de los setters y getters siguiendo el formato de MiClase.cpp

Biblioteca:: ~Biblioteca() {}