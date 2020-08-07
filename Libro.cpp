#include "Libro.h"
#include <string>

Libro:: Libro(std::string titulo, std:: string autor, int fecha_lanzamiento){
    this -> titulo = titulo;
    this -> autor = autor;
    this -> fecha_lanzamiento = fecha_lanzamiento;
}
//Mutadores
//Titulo
std:: string Libro:: getTitulo(){
    return  titulo;
}

//Autor
std:: string Libro :: getAutor(){
    return autor;
} 

//Fecha de Lanzamiento
int Libro :: getFechaLanzamiento(){
    return fecha_lanzamiento;
}

//Destructor
Libro :: ~Libro(){}