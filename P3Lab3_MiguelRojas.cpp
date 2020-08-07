#include <iostream>

using namespace std;
int main(){

    char seguir = 's';
    int opcion_usuario;
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
            break;
        }
        case 2:{
            break;
        }
        case 3:{
            break;
        }
        case 4:{
            break;
        }
        case 5:{
            break;
        }
        case 6:{
            //Salir
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
