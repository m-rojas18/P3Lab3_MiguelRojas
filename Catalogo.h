//Clase Catalogo
#include "Libro.h"
#include <vector>

#ifndef CATALOGO_H
#define CATALOGO_H
class Catalogo {
    //Atributo
    public :
        std:: vector<Libro> lista_libros;
        public :
    //Constructor
        Catalogo();
    //Metodos
        int getTamano();
        Libro getLibro(int);
        void setLibro(Libro);
    //Destructor    
        ~Catalogo();
};
#endif
