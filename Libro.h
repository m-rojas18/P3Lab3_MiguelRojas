//Clase Libro
#include <string>

#ifndef LIBRO_H
#define LIBRO_H

class Libro {
    //atributos
    public :
        std::string titulo;
        std:: string autor;
        int fecha_lanzamiento;

    public:
        Libro(std:: string titulo, std:: string autor,int fecha_lanzamiento);//constructor
        //Mutadores
        //Titulo
        std:: string getTitulo();
        //Autor
        std:: string getAutor();
        //Fecha
        int getFechaLanzamiento();
        //Destructor
        ~Libro();
};
#endif