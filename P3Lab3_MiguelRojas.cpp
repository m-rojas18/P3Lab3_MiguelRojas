#include <iostream>
#include <vector>
#include <string>
#include "Biblioteca.cpp"
#include "Catalogo.cpp"
#include "Libro.cpp"

using namespace std;
void imprimirBibliotecas(vector<Biblioteca>);
int main(){

    char seguir = 's';
    int opcion_usuario;
    //Lista de Bibliotecas
    std:: vector<Biblioteca> lista_bibliotecas;
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
            cin >> nombre_biblioteca;
            cout << endl;
            //Ubicacion
            cout << "Ingrese la ubicacion de la biblioteca: ";
            cin >> ubicacion_biblioteca;
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
            Biblioteca biblioteca_creada(nombre_biblioteca, ubicacion_biblioteca, cantidad_pisos, cantidad_estantes, cantidad_secciones);
            lista_bibliotecas.push_back(biblioteca_creada);
            
            cout << "Se creo exitosamente la biblioteca!!!" << endl<< endl;
            break;
        }
        case 2:{
            //Agregar Libro
            //Mostrar Bibliotecas si existen bibliotecas
            if(lista_bibliotecas.size() >= 1){
                //Mostrar Lista de Bibliotecas
                imprimirBibliotecas(lista_bibliotecas);

                cout << "Seleccione una biblioteca: ";
                int opcion_biblioteca;
                cin >> opcion_biblioteca;
                //Mostrar aributos de la Biblioteca
                Biblioteca biblioteca_elegida = lista_bibliotecas.at(opcion_biblioteca);//biblioteca elegida
                //Pisos
                int posicion_piso;
                cout << "Cantidad de Pisos : " << biblioteca_elegida.getCantidadPisos() << "." << endl;
                cout << "Eliga un piso: ";
                cin >> posicion_piso;
                while(posicion_piso > biblioteca_elegida.getCantidadPisos() || posicion_piso <= 0) {
                    cout << "Piso no valido.\nIngrese un piso valido: ";
                    cin >> posicion_piso;
                    cout << endl;
                }
                cout << endl;
                //Elegir Estante
                int posicion_estante;
                cout << "Cantidad de Estantes en el piso " << posicion_piso << " es igual a: "<< biblioteca_elegida.getCantidadEstantes() << " estantes." << endl;
                cout << "Eliga un estante: ";
                cin >> posicion_estante;
                while(posicion_estante > biblioteca_elegida.getCantidadEstantes() || posicion_estante <= 0) {
                    cout << "Estante no valido.\nIngrese un estante valido: ";
                    cin >> posicion_estante;
                    cout << endl;
                }
                cout << endl;
                //Elegir Seccion
                int posicion_seccion;
                cout << "Cantidad de secciones en el estante " << posicion_estante << " es igual a: " << biblioteca_elegida.getCantidadSecciones() << "." << endl;
                cout << "Eliga una seccion: ";
                cin >> posicion_seccion;
                while(posicion_seccion > biblioteca_elegida.getCantidadSecciones() || posicion_seccion <= 0){
                    cout << "Seccion no valida.\nIngrese una secciona valida: ";
                    cin >> posicion_seccion;
                    cout << endl;
                }
                cout << endl;
                //Atributos de un libro
                string autor_libro, titulo_libro;
                int year_lanzamiento;
                //Autor
                cout << "Ingrese el nombre del autor del libro: ";
                cin >> autor_libro;
                cout << endl;
                //Titulo
                cout << "Ingrese el titulo del libro: ";
                cin >> titulo_libro;
                cout << endl;
                //Año de Lanzamiento
                cout << "Ingrese el año de lanzamiento del libro: ";
                cin >> year_lanzamiento;
                cout << endl;

                //Agregar a Catalogo
                Libro libro_creado(titulo_libro, autor_libro, year_lanzamiento);
                
            } else {
                cout << "No existe ninguna biblioteca." << endl;
            }
            break;
        }
        case 3:{
            //Buscar por Titulo

            break;
        }
        case 4:{
            //Buscar por Autor

            break;
        }
        case 5:{
            //Explorar biblioteca
            imprimirBibliotecas(lista_bibliotecas);
            cout << "Seleccione una biblioteca: ";
            int opcion_biblioteca;
            cin >> opcion_biblioteca;
            //Mostrar aributos de la Biblioteca
            Biblioteca biblioteca_seleccionada = lista_bibliotecas.at(opcion_biblioteca);//biblioteca elegida
            //Pisos
            int seleccion_piso;
            cout << "Cantidad de Pisos : " << biblioteca_seleccionada.getCantidadPisos() << "." << endl;
            cout << "Eliga un piso: ";
            cin >> seleccion_piso;
            while(seleccion_piso > biblioteca_seleccionada.getCantidadPisos() || seleccion_piso <= 0) {
                cout << "Piso no valido.\nIngrese un piso valido: ";
                cin >> seleccion_piso;
                cout << endl;
            }
            cout << endl;
            //Elegir Estante
            int seleccion_estante;
            cout << "Cantidad de Estantes en el piso " << seleccion_piso << " es igual a: "<< biblioteca_seleccionada.getCantidadEstantes() << " estantes." << endl;
            cout << "Eliga un estante: ";
            cin >> seleccion_estante;
            while(seleccion_estante > biblioteca_seleccionada.getCantidadEstantes() || seleccion_estante <= 0) {
                cout << "Estante no valido.\nIngrese un estante valido: ";
                cin >> seleccion_estante;
                cout << endl;
            }
            cout << endl;
            //Elegir Seccion
            int seleccion_seccion;
            cout << "Cantidad de secciones en el estante " <<seleccion_estante << " es igual a: " << biblioteca_seleccionada.getCantidadSecciones() << "." << endl;
            cout << "Eliga una seccion: ";
            cin >> seleccion_seccion;
            while(seleccion_seccion > biblioteca_seleccionada.getCantidadSecciones() || seleccion_seccion <= 0){
                cout << "Seccion no valida.\nIngrese una secciona valida: ";
                cin >> seleccion_seccion;
                cout << endl;
            }
            cout << endl;
            break;
        }
        case 6:{
            //Salir
            //Liberar memoria de Arreglos
            for (int i = 0; i < lista_bibliotecas.size(); i++){

                lista_bibliotecas.at(i).liberarArreglo();
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

void imprimirBibliotecas(vector<Biblioteca> lista_bibliotecas){
    cout << "Lista de Bibliotecas\n";
    for (int i = 0; i < lista_bibliotecas.size(); i++)
        cout << "[" << i << "] " << lista_bibliotecas.at(i).getNombre() << endl;
}
