#include <iostream>
#include<stdio.h> 
#include <string>
#include <stdlib.h>
using namespace std;

struct Nodo {
    string dato;
    Nodo* siguiente;
};

void agregarPila(Nodo*& pila, string n) {
    // std::cout << "valorrr !"<<pila;
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
};

void sacarPila(Nodo*& pila, string& n) {
    // Los parametros son por referencia
    // creando una copia de la pila
    Nodo* aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
};

void mostrarPila(Nodo*& pila) {
    // Los parametros son por referencia
    // creando una copia de la pila
    Nodo* a = pila;
    while (a != NULL) {
        std::cout << "pilaaaaad! " << a->dato << " sdf\n\n";
        a = a->siguiente;
    }
};

void mostrarCola(Nodo*& inicioCola) {
    // Los parametros son por referencia
    // creando una copia de la pila
    Nodo* a = inicioCola;
    while (a != NULL) {
        std::cout << "Cancion: " << a->dato << "\n";
        a = a->siguiente;
    }
};

bool colaVacia(Nodo*& inicioCola) {
    return (inicioCola == NULL) ? true : false;
}


void insertarCola(Nodo*& inicioCola, Nodo*& finalCola, string n) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->siguiente = NULL;

    // Verificamos si la cola esta vacia
    if (colaVacia(inicioCola)) {
        inicioCola = nuevoNodo;
    }
    else {
        finalCola->siguiente = nuevoNodo;
    }

    finalCola = nuevoNodo;

};


void eliminarCola(Nodo*& inicioCola, Nodo*& finalCola, string& n) {
    n = inicioCola->dato;
    Nodo* aux = inicioCola;

    // Determinar si la cola tiene un nodo o mas de un nodo
    if (inicioCola == finalCola) {
        inicioCola = NULL;
        finalCola = NULL;
    }
    else {

        inicioCola = inicioCola->siguiente;

    }
    delete aux;

}

void agregarCancionFila(Nodo*& inicioCola, Nodo*& finalCola)
{
    string nameC;
    string nameA;
    string tot;
    cout << "Nombre de la Cancion: ";
    getline(std::cin, nameC, '\n');

    cout << "Nombre del Artista: ";
    getline(std::cin, nameA, '\n');

    tot = nameC + " - " + nameA;
    insertarCola(inicioCola, finalCola, tot);
};

void menu() {
    string opc;
    string opc1;
    string nameC;
    string nameA;

    string output;

    Nodo* frenteCola = NULL;
    Nodo* finalCola = NULL;

    int menuPrincipal = 1;


    do {
        if (menuPrincipal == 1) {
            cout << "PLATAFORMA PARTY MIX: MENU PRINCIPAL\n\n";
            cout << "[ 1 ] Funciones de Playlist \n";
            cout << "[ 2 ] Funciones de Fila de Reproduccion\n";
            cout << "[ 3 ] Salir del Programa\n";
            cout << "\nOpcion: ";
            getline(std::cin, opc, '\n');
            system("cls");

            if (opc == "1") {
                cout << "PLATAFORMA PARTY MIX: PLAYLIST \n\n";
                menuPrincipal = 2;
            }
            else if (opc == "2") {
                menuPrincipal = 3;
                cout << "PLATAFORMA PARTY MIX: FILA REPRODUCCION \n\n";
                // cout<< "1 Crear una nueva fila de reproduccion \n";
                cout << "[ 1 ] Agregar una cancion a la fila de reproduccion\n";
                cout << "[ 2 ] Eliminar la primera cancion  de la cola de la fila de reproduccion\n";
                cout << "[ 3 ] Sincronizar fila de reproduccion con playlist \n";
                cout << "[ 4 ] Mostrar toda la fila de reproduccion.\n";
                cout << "[ 7 ] Regresar al menu principal\n\n";

                cout << "Opcion: ";
                getline(std::cin, opc1, '\n');

                if (opc1 == "1") {
                    system("cls");
                    cout << "FILA DE REPRODUCCION: Anadir Cancion\n\n";
                    agregarCancionFila(frenteCola, finalCola);
                    cout << "\nCancion anadida satisfactoriamente, presione ENTER para regresar al menu";
                    cin.get();
                    system("cls");
                }
                else if (opc1 == "2") {
                    system("cls");
                    eliminarCola(frenteCola, finalCola, output);
                    cout << "\nCancion eliminada satisfactoriamente, presione ENTER para regresar al menu";
                    cin.get();
                    system("cls");
                }
                else if (opc1 == "3") {
                    system("cls");
                    cout << "FILA DE REPRODUCCION: Mostrar Fila de Reproduccion\n\n";
                    system("cls");
                }
                else if (opc1 == "4") {
                    system("cls");
                    cout << "FILA DE REPRODUCCION: Mostrar Canciones dentro de Fila de Reproduccion\n\n";
                    mostrarCola(frenteCola);
                    cout << "\nPresione ENTER para regresar al menu";
                    cin.get();
                    system("cls");
                }
                else if (opc1 == "5") {
                    system("cls");
                }
                else if (opc1 == "6") {
                    system("cls");
                }
                else if (opc1 == "7") {
                    system("cls");
                    menuPrincipal = 1;
                }

            }
            else if (opc == "3") {

            }
            else {
                cout << "PLATAFORMA PARTY MIX: PLAYLIST \n\n";
            }
        }
        else if (menuPrincipal == 2) {
        }

        else if (menuPrincipal == 3) {
            cout << "PLATAFORMA PARTY MIX: FILA REPRODUCCION \n\n";
            // cout<< "1 Crear una nueva fila de reproduccion \n";
            cout << "[ 1 ] Agregar una cancion a la fila de reproduccion\n";
            cout << "[ 2 ] Eliminar la primera cancion  de la cola de la fila de reproduccion\n";
            cout << "[ 3 ] Sincronizar fila de reproduccion con playlist \n";
            cout << "[ 4 ] Mostrar toda la fila de reproduccion.\n";
            cout << "[ 7 ] Regresar al menu principal\n\n";

            cout << "Opcion: ";
            getline(std::cin, opc1, '\n');

            if (opc1 == "1") {
                system("cls");
                cout << "FILA DE REPRODUCCION: Anadir Cancion\n";
                agregarCancionFila(frenteCola, finalCola);
                cout << "\nCancion anadida satisfactoriamente, presione ENTER para regresar al menu";
                cin.get();
                system("cls");
            }
            else if (opc1 == "2") {
                system("cls");
                eliminarCola(frenteCola, finalCola, output);
                cout << "\nCancion eliminada satisfactoriamente, presione ENTER para regresar al menu";
                cin.get();
                system("cls");
            }
            else if (opc1 == "3") {
                system("cls");
                cout << "FILA DE REPRODUCCION: Mostrar Fila de Reproduccion\n";
                system("cls");
            }
            else if (opc1 == "4") {
                system("cls");
                cout << "FILA DE REPRODUCCION: Mostrar Canciones dentro de Fila de Reproduccion\n\n";
                mostrarCola(frenteCola);
                cout << "\nPresione ENTER para regresar al menu";
                cin.get();
                system("cls");
            }
            else if (opc1 == "5") {
                system("cls");
            }
            else if (opc1 == "6") {
                system("cls");
            }
            else if (opc1 == "7") {
                system("cls");
                menuPrincipal = 1;
            }


































        }


    } while (opc != "3");

};


int main() {
    string valorUsuario;

    // Declarando una variable que puede almacenar la direccion de una variable de tipo Nodo.
    // Nodo *pila = NULL;

    // std::cout << "Hello World!\n";
    // std::cin>>valorUsuario;
    // agregarPila(pila, valorUsuario);

    string ss;
    // mostrarPila(pila)
    // sacarPila(pila, ss);
    // std::cout << "se saco el valor ! "<<ss<<" sdf";


    // while(pila != NULL){
    //   sacarPila(pila, ss);
    //   std::cout << "pilaaaaad! "<<ss<<" sdf";
    // }









    menu();


    // agregarCancionFila(frenteCola, finalCola);

    // mostrarCola(frenteCola);


    // insertarCola(frenteCola, finalCola, "holaaaaa");

    // insertarCola(frenteCola, finalCola, "odio");

    // insertarCola(frenteCola, finalCola, "bebe");


    // mostrarCola(frenteCola);

    // cout<<"eliminando ";

    // eliminarCola(frenteCola, finalCola, ss);


    // mostrarCola(frenteCola);






}