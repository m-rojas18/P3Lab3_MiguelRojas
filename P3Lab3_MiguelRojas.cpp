#include <iostream>
#include <vector>
#include <string>
#include "Biblioteca.cpp"
#include "Catalogo.cpp"
#include "Libro.cpp"

using namespace std;
void imprimirBibliotecas(vector<Biblioteca*>);
void imprimirCatalogo(Biblioteca*, int, int,int);
void buscarTitulos(vector<Biblioteca*>, string);
void buscarAutor(vector<Biblioteca*>, string);
bool buscarLibros(vector<Biblioteca*>);
int main(){

    char seguir = 's';
    int opcion_usuario;
    //Lista de Bibliotecas
    vector<Biblioteca*> lista_bibliotecas;
    while (seguir == 's'){
        cout << "Menu Lab 3 " << endl
             << "[1] Crear Biblioteca" << endl
             << "[2] Agregar Libro" << endl
             << "[3] Buscar por Titulo" << endl
             << "[4] Buscar por Autor" << endl
             << "[5] Explorar Biblioteca" << endl
             << "[6] Salir" << endl
             << "Seleccione una opcion: ";
        cin >> opcion_usuario;
        cout << endl;
        switch (opcion_usuario){

        case 1:{
            //Creacion de Biblioteca
            //Atributos de la biblioteca 
            string nombre_biblioteca, ubicacion_biblioteca;
            int cantidad_pisos, cantidad_estantes, cantidad_secciones;
            //Nombre
            cout << "Ingrese el nombre de la biblioteca: ";
            getline(cin, nombre_biblioteca); 
            getline(cin, nombre_biblioteca); 
            cout << endl;
            //Ubicacion
            cout << "Ingrese la ubicacion de la biblioteca: ";
            getline(cin, ubicacion_biblioteca); 
            cout << endl;
            //Cantidad de Pisos
            cout << "Ingrese la cantidad de pisos hay en la biblioteca: ";
            cin >> cantidad_pisos;
            cout << endl;
            //Cantidad de Estantes
            cout << "Ingrese la cantidad de estantes por piso: ";
            cin >> cantidad_estantes;
            cout << endl;
            //Cantidad de Secciones
            cout << "Ingrese cantidad de secciones por estante: ";
            cin >> cantidad_secciones;
            cout << endl;

            //Creacion de Objeto Biblioteca
            Biblioteca* b = new Biblioteca(nombre_biblioteca, ubicacion_biblioteca, cantidad_pisos, cantidad_estantes, cantidad_secciones);
            lista_bibliotecas.push_back(b);
            
            cout << "Se creo exitosamente la biblioteca!!!" << endl<< endl;
            break;
        }
        case 2:{
            //Agregar Libro
            //Mostrar Bibliotecas si existen 
            if(lista_bibliotecas.size() >= 1){
                imprimirBibliotecas(lista_bibliotecas);

                cout << "Seleccione una biblioteca: ";
                int opcion_biblioteca;
                cin >> opcion_biblioteca;
                //Mostrar aributos de la Biblioteca
                Biblioteca* biblioteca_elegida = lista_bibliotecas.at(opcion_biblioteca);//biblioteca elegida
                //Elegir Piso
                int posicion_piso;
                cout << "Cantidad de Pisos : " << biblioteca_elegida -> getCantidadPisos() << "." << endl;
                cout << "Eliga un piso: ";
                cin >> posicion_piso;
                while(posicion_piso > biblioteca_elegida -> getCantidadPisos() || posicion_piso <= 0) {
                    cout << "Piso no valido.\nIngrese un piso valido: ";
                    cin >> posicion_piso;
                    cout << endl;
                }
                cout << endl;
                //Elegir Estante
                int posicion_estante;
                cout << "Cantidad de Estantes en el piso " << posicion_piso << " es igual a: "<< biblioteca_elegida -> getCantidadEstantes() << " estantes." << endl;
                cout << "Eliga un estante: ";
                cin >> posicion_estante;
                while(posicion_estante > biblioteca_elegida -> getCantidadEstantes() || posicion_estante <= 0) {
                    cout << "Estante no valido.\nIngrese un estante valido: ";
                    cin >> posicion_estante;
                    cout << endl;
                }
                cout << endl;
                //Elegir Seccion
                int posicion_seccion;
                cout << "Cantidad de secciones en el estante " << posicion_estante << " es igual a: " << biblioteca_elegida -> getCantidadSecciones() << "." << endl;
                cout << "Eliga una seccion: ";
                cin >> posicion_seccion;
                while(posicion_seccion > biblioteca_elegida -> getCantidadSecciones() || posicion_estante <= 0){
                    cout << "Seccion no valida.\nIngrese una seccion valida: ";
                    cin >> posicion_seccion;
                    cout << endl;
                }
                cout << endl;
                //Atributos de un libro
                string autor_libro, titulo_libro;
                int year_lanzamiento;
                //Autor
                cout << "Ingrese el nombre del autor del libro: ";
                getline(cin, autor_libro); 
                cout << endl;
                //Titulo
                cout << "Ingrese el titulo del libro: ";
                getline(cin, titulo_libro); 
                cout << endl;
                //Año de Lanzamiento
                cout << "Ingrese el año de lanzamiento del libro: ";
                cin >> year_lanzamiento;
                cout << endl;

                --posicion_piso;
                --posicion_estante;
                --posicion_seccion;
                Libro* libro_creado = new Libro(titulo_libro, autor_libro, year_lanzamiento);
                Catalogo*** catalogo = biblioteca_elegida -> getCatalogo();
                catalogo[posicion_piso][posicion_estante][posicion_seccion].setLibro(libro_creado);

                //Probar si agrego
                /*for (int i = 0; i < cat[posicion_piso][posicion_estante][posicion_seccion].getListaLibros().size(); i++){
                    cout << "[" << i << "]"<<  cat[posicion_piso][posicion_estante][posicion_seccion].getLibro(i)->getAutor();
                }*/
                cout << "Se agrego exitosamente el libro!!" << endl << endl;
            } else {
                cout << "No existe ninguna biblioteca." << endl << endl;
            }
            break; 
        }
        case 3:{
            //Buscar por Titulo
            if(lista_bibliotecas.size() >= 1){
                //Existe minimo 1 biblioteca
                //Buscar Si existen libros
                bool verificar = buscarLibros(lista_bibliotecas);
                if(verificar == true){
                    //Existe minimo 1 libro
                    //Pedir titulo de libro buscado
                    string titulo_libroBuscado;
                    cout << "Ingrese el titulo del libro a buscar: ";
                    getline(cin, titulo_libroBuscado); 
                    buscarTitulos(lista_bibliotecas, titulo_libroBuscado);
                    cout << endl << endl;
                } else {
                    cout << "No existe ningun libro."<< endl << endl;
                }    
            } else {
                cout << "No existe ninguna biblioteca." << endl << endl;
            }
            break;
        }
        case 4:{
            //Buscar por Autor
            if(lista_bibliotecas.size() >= 1){
                //Existe minimo 1 biblioteca
                bool verificar_Libros = buscarLibros(lista_bibliotecas);//Buscar Si existen libros
                if(verificar_Libros == true){
                    //Existe minimo 1 libro
                    //Pedir autor de libro buscado
                    string autor_libroBuscado;
                    cout << "Ingrese el nombre del autor de libros a buscar: ";
                    getline(cin, autor_libroBuscado); 
                    buscarTitulos(lista_bibliotecas, autor_libroBuscado);
                    cout << endl << endl;
                } else {
                    cout << "No existe ningun libro."<< endl << endl;
                }    
            } else {
                cout << "No existe ninguna biblioteca." << endl << endl;
            }
            break;
        }
        case 5:{
            //Explorar biblioteca
            if(lista_bibliotecas.size() >= 1){
                bool verificar_Libros = buscarLibros(lista_bibliotecas);
                if(verificar_Libros == true){

                    imprimirBibliotecas(lista_bibliotecas);
                    cout << "Seleccione una biblioteca: ";
                    int seleccion_biblioteca;
                    cin >> seleccion_biblioteca;
                    //Mostrar aributos de la Biblioteca
                    Biblioteca* biblioteca_elegida = lista_bibliotecas.at(seleccion_biblioteca);//biblioteca elegida
                    //Elegir Piso
                    int seleccion_piso;
                    cout << "Cantidad de Pisos : " << biblioteca_elegida->getCantidadPisos() << "." << endl;
                    cout << "Eliga un piso: ";
                    cin >> seleccion_piso;
                    while(seleccion_piso > biblioteca_elegida->getCantidadPisos() || seleccion_piso <= 0) {
                        cout << "Piso no valido.\nIngrese un piso valido: ";
                        cin >> seleccion_piso;
                        cout << endl;
                    }
                    cout << endl;
                    //Elegir Estante
                    int seleccion_estante;
                    cout << "Cantidad de Estantes en el piso " << seleccion_piso << " es igual a: "<< biblioteca_elegida->getCantidadEstantes() << " estantes." << endl;
                    cout << "Eliga un estante: ";
                    cin >> seleccion_estante;
                    while(seleccion_estante > biblioteca_elegida->getCantidadEstantes() || seleccion_estante <= 0) {
                        cout << "Estante no valido.\nIngrese un estante valido: ";
                        cin >> seleccion_estante;
                        cout << endl;
                    }
                    cout << endl;
                    //Elegir Seccion
                    int seleccion_seccion;
                    cout << "Cantidad de secciones en el estante " <<seleccion_estante << " es igual a: " << biblioteca_elegida->getCantidadSecciones() << "." << endl;
                    cout << "Eliga una seccion: ";
                    cin >> seleccion_seccion;
                    while(seleccion_seccion > biblioteca_elegida->getCantidadSecciones() || seleccion_seccion <= 0){
                        cout << "Seccion no valida.\nIngrese una secciona valida: ";
                        cin >> seleccion_seccion;
                        cout << endl;
                    }
                    cout << endl;
                    imprimirCatalogo(biblioteca_elegida, seleccion_piso, seleccion_estante, seleccion_seccion);
                } else {
                    cout << "No existe ningun libro."<< endl << endl;
                }
            } else {
                cout << "No existe ninguna biblioteca." << endl << endl;
            }

            break;
        }
        case 6:{
            //Salir
            //Liberar memoria de Arreglos
            for (int i = 0; i < lista_bibliotecas.size(); i++){

                lista_bibliotecas[i] -> liberarArreglo();
            }
            cout << "Fin del Programa" << endl;
            seguir = 'n';
            break;
        }    
        default:
            cout << "Opcion ingresada no valida." << endl
                 << endl;
            break;
        }
    }
    return 0;
}

void imprimirBibliotecas(vector<Biblioteca*> lista_bibliotecas){
    cout << "Lista de Bibliotecas\n" << endl;
    for (int i = 0; i < lista_bibliotecas.size(); i++)
        cout << "[" << i << "] " << lista_bibliotecas[i] -> getNombre() << endl;
}

void imprimirCatalogo(Biblioteca* biblioteca, int piso, int estante, int seccion){
    cout << "Catalogo :" << endl<< endl;
    Catalogo*** catalogo_temporal = biblioteca ->getCatalogo();
    Catalogo catalogo_imprimir = catalogo_temporal[piso][estante][seccion];
    //Imprescion del catalogo seleccionado
    for (int i = 0; i < catalogo_imprimir.getListaLibros().size(); i++){
        Libro* libro_temporal = catalogo_imprimir.getLibro(i);
        if(catalogo_imprimir.getListaLibros().size() >= 1){
            cout << "[" << i << "] "<<"Titulo: " << libro_temporal->getTitulo()<< endl
                << "Autor: " << libro_temporal->getAutor() << endl
                << "Año: " << libro_temporal->getFechaLanzamiento() << endl
                << "Biblioteca: " << biblioteca->getNombre() << endl
                << "Ubicado en el piso " << piso << " del estante " << estante << " de la seccion " << seccion << ".\n" << endl;
        } else {
            cout << "No hay ningun libro en el catalogo." << endl << endl;
        }
             
    }
}

void buscarTitulos(vector<Biblioteca*> lista_bibliotecas, string titulo){
    //Metodo utilizado para buscar libros con el mismo titulo
    for (int i = 0; i < lista_bibliotecas.size(); i++){
        //Recorrer Bibliotecas
        Biblioteca* b_temporal = lista_bibliotecas[i];
        for (int j = 0; j < b_temporal->getCantidadPisos(); j++){
            //Recorrer Pisos
            for (int k = 0; k < b_temporal ->getCantidadEstantes(); k++){
                    //Recorrer Estantes
                for (int l = 0; l < b_temporal ->getCantidadSecciones(); l++){
                    //Recorre Secciones
                    Catalogo*** catalogo_biblioteca = b_temporal  ->getCatalogo();
                    Catalogo cat_temporal = catalogo_biblioteca[j][k][l];
                    for (int m = 0; m < cat_temporal.getListaLibros().size(); m++){
                        Libro*  libro_temporal = cat_temporal.getLibro(i);
                        //Comparacion de titulos
                        if(libro_temporal->getTitulo() == titulo){
                            //Imprimir Libro
                            int piso = j + 1;
                            int estante = k + 1;
                            int seccion = l + 1;
                            cout << "Titulo: " << titulo << endl
                            << "Autor: " << libro_temporal->getAutor() << endl
                            << "Año: " << libro_temporal->getFechaLanzamiento() << endl
                            << "Biblioteca: " << b_temporal->getNombre() << endl
                            << "Ubicado en el piso " << piso << " del estante " << estante << " de la seccion " << seccion << ".\n" << endl;
                        }
                    }
                }
                
            }
            
        }
    }
}

void buscarAutor(vector<Biblioteca*> lista_bibliotecas, string nombre_autorBuscando){
    //Metodo utilizado para buscar libros con el mismo autor
    for (int i = 0; i < lista_bibliotecas.size(); i++){
        //Recorre Bibliotecas
        Biblioteca* b_temporal = lista_bibliotecas[i];
        for (int j = 0; j < b_temporal->getCantidadPisos(); j++){
            //Recorrer Pisos
            for (int k = 0; k < b_temporal ->getCantidadEstantes(); k++){
                    //Recorrer Estantes
                for (int l = 0; l < b_temporal ->getCantidadSecciones(); l++){
                    //Recorre Secciones
                    Catalogo*** catalogo_biblioteca = b_temporal  ->getCatalogo();
                    Catalogo cat_temporal = catalogo_biblioteca[j][k][l];
                    for (int m = 0; m < cat_temporal.getListaLibros().size(); m++){
                        Libro*  libro_temporal = cat_temporal.getLibro(i);

                        if(libro_temporal->getAutor() == nombre_autorBuscando){
                            //Imprimir Libro
                            int piso = j + 1;
                            int estante = k + 1;
                            int seccion = l + 1;
                            cout << "Titulo: " << libro_temporal->getTitulo() << endl
                            << "Autor: " << nombre_autorBuscando << endl
                            << "Año: " << libro_temporal->getFechaLanzamiento() << endl
                            << "Biblioteca: " << b_temporal->getNombre() << endl
                            << "Ubicado en el piso " << piso << " del estante " << estante << " de la seccion " << seccion << ".\n" << endl;
                        }
                    }
                }
                
            }
            
        }
    }
}

bool buscarLibros(vector<Biblioteca*> lista_bibliotecas){

    bool respuesta = false;
    for (int i = 0; i < lista_bibliotecas.size(); i++){
        //Recorres Bibliotecas
        Biblioteca* b_temporal = lista_bibliotecas[i];
        for (int j = 0; j < b_temporal->getCantidadPisos(); j++){
            //Recorres Pisos
            for (int k = 0; k < b_temporal ->getCantidadEstantes(); k++){
                    //Recorrer Estantes
                for (int l = 0; l < b_temporal ->getCantidadSecciones(); l++){
                    //Recorre Secciones
                    Catalogo*** catalogo_biblioteca = b_temporal  ->getCatalogo();
                    Catalogo  cat_temporal = catalogo_biblioteca[j][k][l];
                    for (int m = 0; m < cat_temporal.getListaLibros().size(); m++){
                        //Recorre la lista de libros por catalogo
                        if(cat_temporal.getListaLibros().size() >= 1){
                            respuesta = true;
                            break;
                            //Existe minimo un libro
                        }
                    }
                }
                
            }
            
        }
    }
    return respuesta;
}
