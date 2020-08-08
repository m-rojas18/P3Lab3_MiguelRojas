#include "Catalogo.h"
#include "Libro.h"
#include <vector>
using namespace std;

Catalogo:: Catalogo(){}
Libro* Catalogo:: getLibro(int posicion){
    return lista_libros[posicion];
}

std:: vector<Libro*> Catalogo:: getListaLibros(){
    return lista_libros;
}

void Catalogo:: setLibro(Libro* libro){
    
    lista_libros.push_back(libro);
}

Catalogo:: ~Catalogo(){}

