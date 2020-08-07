#include "Catalogo.h"
#include "Libro.h"
#include <vector>

Catalogo::Catalogo(){}

int Catalogo::getTamano(){
    return lista_libros.size();
}
Libro Catalogo:: getLibro(int posicion){
    return lista_libros.at(posicion);
}
void Catalogo:: setLibro(Libro libro){
    lista_libros.push_back(libro);
}

Catalogo:: ~Catalogo(){}

