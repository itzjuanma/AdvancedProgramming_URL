#include <iostream>
#include<stdio.h> 
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


struct Nodo {
    string dato;
    Nodo* siguiente;
};


//CREAR PILA 

void agregarPila(Nodo*& pila, string n) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
};

//SACAR EL PRIMER VALOR DE LA PILA
void sacarPila(Nodo*& pila, string& n) {
    Nodo* aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
};

//MOSTRAR LA PILA
void mostrarPila(Nodo*& pila) {

    Nodo* a = pila;
    while (a != NULL) {
        std::cout << "             - " << a->dato << "\n";
        a = a->siguiente;
    }
};

//ORDENAMIENTO por BUBBLESORT

void bubbleSortCancionPila(Nodo*& pila, string optOrder) {

    Nodo* a = pila;
    Nodo* b = pila;
    string delimiter = "-";
    //Determinando el tamano de la pila
    int sizePila = 0;
    while (a != NULL) {
        sizePila = sizePila + 1;
        a = a->siguiente;
    }

    vector<string> listaCanciones(sizePila);
    vector<string> listaArtistas(sizePila);

    // Colocacion de datos dentro de los vectores para ordenar
    for (int i = 0; i < sizePila; i++) {
        string word = b->dato;
        string nombreCancion = word.substr(0, word.find(delimiter));
        string artista = word.substr(word.find("-") + 1);

        listaCanciones[i] = nombreCancion;
        listaArtistas[i] = artista;
        b = b->siguiente;
    }

    string aux, auxArt;
    int x, j;
    for (x = 0; x < sizePila; x++) {
        for (j = 0; j < sizePila - x - 1; j++) {
            if (listaCanciones[j] > listaCanciones[j + 1]) {
                // Ordenando cancion
                aux = listaCanciones[j];
                listaCanciones[j] = listaCanciones[j + 1];
                listaCanciones[j + 1] = aux;

                // Ordenando artista
                auxArt = listaArtistas[j];
                listaArtistas[j] = listaArtistas[j + 1];
                listaArtistas[j + 1] = auxArt;

            }
        }
    }

    if (optOrder == "1") {
        // Descendente
        pila = NULL;
        cout << "Orden descendente: \n";
        for (int i = 0; i < sizePila; i++) {
            string word = listaCanciones[i] + "-" + listaArtistas[i];
            agregarPila(pila, word);
        }
        mostrarPila(pila);
    }
    else {
        pila = NULL;
        // Ascendente
        cout << "Orden ascendente: \n";
        for (int i = sizePila - 1; i >= 0; i--) {
            string word = listaCanciones[i] + "-" + listaArtistas[i];
            agregarPila(pila, word);
        }
        mostrarPila(pila);
    }
};

void bubbleSortArtistaPila(Nodo*& pila, string optOrder) {
    // Los parametros son por referencia
    // creando una copia de la pila
    Nodo* a = pila;
    Nodo* b = pila;
    string delimiter = "-";
    //Determinando el size de la pila
    int sizePila = 0;
    while (a != NULL) {
        sizePila = sizePila + 1;
        a = a->siguiente;
    }

    vector<string> listaCanciones(sizePila);
    vector<string> listaArtistas(sizePila);

    // Colocacion de datos dentro de los vectores para ordenar
    for (int i = 0; i < sizePila; i++) {
        string word = b->dato;
        string nombreCancion = word.substr(0, word.find(delimiter));
        string artista = word.substr(word.find("-") + 1);

        listaCanciones[i] = nombreCancion;
        listaArtistas[i] = artista;
        b = b->siguiente;
    }

    string aux, auxArt;
    int x, j;
    for (x = 0; x < sizePila; x++) {
        for (j = 0; j < sizePila - x - 1; j++) {

            string artista = listaArtistas[j].substr(listaArtistas[j].find("-") + 1);
            if (listaArtistas[j] > listaArtistas[j + 1] || (artista == "desconocido")) {
                // Ordenando cancion
                aux = listaCanciones[j];
                listaCanciones[j] = listaCanciones[j + 1];
                listaCanciones[j + 1] = aux;

                // Ordenando artista
                auxArt = listaArtistas[j];
                listaArtistas[j] = listaArtistas[j + 1];
                listaArtistas[j + 1] = auxArt;

            }
        }
    }

    if (optOrder == "1") {
        //Ordenamos descendente
        // descendente
        pila = NULL;
        cout << "Orden descendente: \n";
        for (int i = 0; i < sizePila; i++) {
            string word = listaCanciones[i] + "-" + listaArtistas[i];
            agregarPila(pila, word);
        }
        mostrarPila(pila);
    }
    else {
        pila = NULL;
        // Ascendente
        cout << "Orden ascendente: \n";
        for (int i = sizePila - 1; i >= 0; i--) {
            string word = listaCanciones[i] + "-" + listaArtistas[i];
            agregarPila(pila, word);
        }
        mostrarPila(pila);
    }
};

//MOSTRAR COLA
void mostrarCola(Nodo*& inicioCola) {
    // Los parametros son por referencia
    // creando una copia de la pila
    Nodo* a = inicioCola;
    while (a != NULL) {
        std::cout << "Cancion: " << a->dato << "\n";
        a = a->siguiente;
    }
};

//VERIFICAR SI LA COLA ESTA VACIA
bool colaVacia(Nodo*& inicioCola) {
    return (inicioCola == NULL) ? true : false;
}

//IR INSERTANDO VALORES EN LA COLA
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











void filaAPlaylis(Nodo*& inicioCola, Nodo*& pila) {
    // Los parametros son por referencia
    // creando una copia de la pila
    pila = NULL;
    Nodo* a = inicioCola;
    while (a != NULL) {
        agregarPila(pila, a->dato);
        a = a->siguiente;
    }
    mostrarPila(pila);

};

// LEER ARCHIVO CSV
void read_csv_words(Nodo*& pila, string csvPath)
{
    string delimiter = "-";
    // LEE UN ARCHIVO csv Y CREA UNA PILA APARTIR DE ESTE.
      // File pointer
    fstream file;

    // Open an existing file
    file.open(csvPath, ios::in);

    if (!file) {
        cout << "El archivo ingresado no existe.\n" << endl;
        // exit(1);
    }

    string line, word, temp, lastWord;

    while (getline(file, line, '\n')) {
        // read an entire row and
        // store it in a string variable 'line'
    // used for breaking words
        stringstream s(line);

        while (getline(s, word, ',')) {
            // Con esto seleccionas el nombre de la cancion
            string nombreCancion = word.substr(0, word.find(delimiter));
            string artista = word.substr(word.find("-") + 1);
            if (nombreCancion == "") {
                cout << "El archivo contiene un espacio vacio, una o mas canciones no se agregaron a la playlist\n";
            }
            else {
                agregarPila(pila, word);
            }

        }
    }
    file.close();

};

// PASAMOS LA PILA PARA VERIFICAR SI EL ARTISTA EXISTE, SI NO EXISTE SE PONE DESCONOCIDO, SIN EMBARGO POR ALGUNA RAZON NO DETECTA LA ULTIMA PALABRA PERO SI FUNCIONA.
void artistaDesconocido(Nodo*& pila) {
    Nodo* a = pila;
    pila = NULL;
    string delimiter = "-";
    // Arreglamos lo de los artistas desconocidos sustituimos
    while (a != NULL) {
        string saveWord = a->dato;
        string nombreCancion = saveWord.substr(0, saveWord.find(delimiter));
        string artista = saveWord.substr(saveWord.find("-") + 1);

        if (artista == "") {
            string noa = "desconocido";
            string w = nombreCancion + "-" + noa;
            agregarPila(pila, w);
        }
        else {
            if (saveWord.find("-") == -1) {
                // Es decir que no encontro el separador por lo que el artista es desconocido.
                string des = "desconocido";
                string o = nombreCancion + "-" + des;
                agregarPila(pila, o);
            }
            else {
                agregarPila(pila, saveWord);
            }
        }
        a = a->siguiente;
    }
}




void playlistToFila(Nodo*& frenteCola, Nodo*& finalCola, Nodo*& pila) {
    // Los parametros son por referencia
    // creando una copia de la pila
    frenteCola = NULL;
    finalCola = NULL;

    Nodo* a = pila;
    while (a != NULL) {
        insertarCola(frenteCola, finalCola, a->dato);
        a = a->siguiente;
    }
};





//FUNCION: EXPORTAR CSV a un Archivo

int write_csv(Nodo*& pila, string csvPath)
{
    std::ofstream myFile(csvPath);
    Nodo* a = pila;
    while (a != NULL) {
        myFile << a->dato;
        myFile << "\n";
        a = a->siguiente;
    }
    std::cout << "\nSe Genero el Archivo Correctamente " << csvPath << "\n";
    myFile.close();
    return 0;

}










//Funcion: GENERAR e INTERACTUAR CON MENU PRINCIPAL

void menu() {
    string opc;
    string opc1;
    string pathCSV;
    string nameC;
    string nameA;
    Nodo* pila = NULL;
    string output;
    Nodo* frenteCola = NULL;
    Nodo* finalCola = NULL;

    //MENU PRINCIPAL, SE MUESTRAN AMBAS PLATAFORMAS

    int menuPrincipal = 1;

    do {
        if (menuPrincipal == 1) {
            cout << "PLATAFORMA PARTY MIX: MENU PRINCIPAL\n\n";
            cout << "[ 1 ] Funciones de Playlist \n";
            cout << "[ 2 ] Funciones de Fila de Reproduccion\n";
            cout << "[ 3 ] Salir del Programa\n\n";
            cout << "Opcion: ";
            getline(std::cin, opc, '\n');
            system("cls");
        

    // MENU PLAYLIST, SE SELECCIONA EL ARCHIVO A UTILIZAR

            if (opc == "1") {
                cout << "PLATAFORMA PARTY MIX: PLAYLIST \n\n";
                menuPrincipal = 2;
                cout << "[ 1 ] Crear Playlist a partir de CSV \n";
                cout << "[ 2 ] Mover de Fila de Reproduccion a Playlist \n\n";
                cout << "Opcion: ";
                getline(std::cin, opc1, '\n');

    // SELECCIONAR EL CSV A UTILIZAR

                if (opc1 == "1") {
                    system("cls");
                    cout << "PLATAFORMA PARTY MIX: PLAYLIST \n\n";
                    cout << "Insertar Nombre de Archivo CSV para Cargar Playlist: \n\n";
                    cout << "[ Opciones ] \n\n";
                    cout << "archivo1 \n";
                    cout << "archivo2 \n";
                    cout << "archivo3 \n";
                    cout << "archivo4 \n";
                    cout << "archivo5 \n";
                    cout << "archivo6 \n\n";
                    cout << "Archivo a utilizar: ";
                    getline(std::cin, pathCSV, '\n');
                    pila = NULL;
                    read_csv_words(pila, pathCSV);
                    artistaDesconocido(pila);
                    cout << "\n\nArchivo anadido correctamente, presione ENTER para Continuar";
                    cin.get();
                    system("cls");
                    
                }

                else if (opc1 == "2") {
                    system("cls");
                    cout << "Moviendo Fila a Playlist \n";
                    if (pila == NULL) {
                        if (colaVacia(frenteCola)) {
                            cout << "La Fila de Reproduccion No Puede Estar Vacia \n";
                            cout << "\n\nPresione ENTER para Continuar";
                            cin.get();
                            system("cls");
                        }
                        else {
                            cout << "La Fila de Reproduccion Ya Tiene Canciones \n";
                            filaAPlaylis(frenteCola, pila);
                            cout << "\n\nPresione ENTER para Continuar";
                            cin.get();
                            system("cls");
                        }

                    }
                    else {
                        cout << "La Pila tiene que Estar Vacia para Hacer Esta Operacion\n";
                        cout << "\n\nPresione ENTER para Continuar";
                        cin.get();
                        system("cls");
                    }




                }


     //MENU FILA DE REPRODUCCION

            }
            else if (opc == "2") {
                menuPrincipal = 3;
                cout << "PLATAFORMA PARTY MIX: FILA REPRODUCCION \n\n";
                cout << "[ 1 ] Agregar una cancion a la fila de reproduccion\n";
                cout << "[ 2 ] Eliminar la primera cancion  de la cola de la fila de reproduccion\n";
                cout << "[ 3 ] Sincronizar fila de reproduccion con playlist \n";
                cout << "[ 4 ] Mostrar toda la fila de reproduccion.\n";
                cout << "[ 7 ] Regresar al menu principal\n\n";

                cout << "Opcion: ";
                getline(std::cin, opc1, '\n');

    // AGREGAR CANCION A FILA DE REPRODUCCION
                if (opc1 == "1") {
                    system("cls");
                    cout << "FILA DE REPRODUCCION: Anadir Cancion\n\n";
                    agregarCancionFila(frenteCola, finalCola);
                    cout << "\nCancion anadida satisfactoriamente, presione ENTER para regresar al menu";
                    cin.get();
                    system("cls");
                }
    // ELIMINAR CANCION DE FILA DE REPRODUCCION
                else if (opc1 == "2") {
                    system("cls");
                    eliminarCola(frenteCola, finalCola, output);
                    cout << "\nCancion eliminada satisfactoriamente, presione ENTER para regresar al menu";
                    cin.get();
                    system("cls");
                }
                else if (opc1 == "3") {
                    system("cls");
                    playlistToFila(frenteCola, finalCola, pila);
                    cout << "\nFila de Reproduccion Sincronizada Sorrectamente. Presione ENTER para regresar al menu";
                    cin.get();
                    system("cls");


                }
                else if (opc1 == "4") {
                    if (frenteCola == NULL) {
                        system("cls");
                        cout << "FILA DE REPRODUCCION: Mostrar Canciones dentro de Fila de Reproduccion\n\n";
                        cout << "\nLa Fila de Reproduccion se Encuentra Vacia, Use la Opcion 1 para Anadir una Cancion.\n";
                        cout << "\nPresione ENTER para regresar al menu";
                        cin.get();
                        system("cls");
                    }
                    else{
                        system("cls");
                        cout << "FILA DE REPRODUCCION: Mostrar Canciones dentro de Fila de Reproduccion\n\n";
                        mostrarCola(frenteCola);
                        cout << "\nPresione ENTER para regresar al menu";
                        cin.get();
                        system("cls");
                    }
                }
                else if (opc1 == "5") {
                    system("cls");
                    string cancionReporducindo;
                    sacarPila(pila, cancionReporducindo);
                    std::cout << "Reproduciendo canción " << cancionReporducindo;
                    cout << "\nPresione ENTER para regresar al menu";
                    cin.get();
                    system("cls");
                }

                else if (opc1 == "7") {
                    system("cls");
                    menuPrincipal = 1;
                }

            }
            else if (opc == "3") {
            exit(0);
            }
            else {
                cout << "PLATAFORMA PARTY MIX: PLAYLIST \n\n";
            }
        }


        //MENU PRINCIPAL PLAYLIST: ACCIONES A REALIZAR
        else if (menuPrincipal == 2) {


            cout << "PLATAFORMA PARTY MIX: PLAYLIST \n\n";
            menuPrincipal = 2;
            cout << "[ 1 ] Ordenar Playlist por Cancion \n";
            cout << "[ 2 ] Ordenar Playlist por Artista \n";
            cout << "[ 3 ] Visualizar Cancion en Reproduccion (Primera en la Pila) \n";
            cout << "[ 4 ] Reproducir Cancion \n";
            cout << "[ 5 ] Mover de Fila de Reproduccion a Playlist \n";
            cout << "[ 6 ] Mostrar Playlist \n";
            cout << "[ 7 ] Exportar Playlist a CSV \n";
            cout << "[ 8 ] Regresar a Menu Principal \n\n";
            cout << "Opcion: ";
            getline(std::cin, opc1, '\n');
           
     //PLAYLIST: ORDENAMIENTO POR CANCION

            if (opc1 == "1") {
                system("cls");

                cout << "PLAYLIST: Ordenando por Cancion: \n";
                cout << "Ingrese [ 0 ] para Ordenar Ascendente y [ 1 ] para Ordenar Descendente: \n";
                string opc2;
                cout << "Opcion: ";
                getline(std::cin, opc2, '\n');

                bubbleSortCancionPila(pila, opc2);

                cout << "\n\nPresione ENTER para regresar al menu de Playlist";
                cin.get();
                system("cls");

            }

    //PLAYLIST: ORDENAMIENTO POR ARTISTA
            else if (opc1 == "2") {
                system("cls");
                cout << "PLAYLIST: Ordenando por artista: \n";
                cout << "Ingrese [ 0 ] para Ordenar Ascendente y [ 1 ] para Ordenar Descendente: \n";
                string opc2;
                cout << "Opcion: ";
                getline(std::cin, opc2, '\n');
                bubbleSortArtistaPila(pila, opc2);


                cout << "\n\nPresione ENTER para regresar al menu de Playlist";
                cin.get();
                system("cls");

            }
     //PLAYLIST: MOSTRAR LA CANCION QUE SE ESTA REPRODUCIENDO           
            else if (opc1 == "3") {
                system("cls");
                cout << "PLAYLIST: Mostrar Cancion en Reproduccion\n\n";
                cout << "La Cancion en Reproduccion es: ";
                cout << pila->dato;
                cout << "\n\nPresione ENTER para regresar al menu de Playlist";
                cin.get();
                system("cls");
            }
        
      //PLAYLIST: REPRODUCIR CANCION
            else if (opc1 == "4") {
                system("cls");
                cout << "PLAYLIST: Reproducir Cancion\n\n";
                string ss;
                sacarPila(pila, ss);
                std::cout << "Reproduciendo Cancion, Se Sacara de la Playlist\n\n " << "              - " << ss;
                cout << "\n\nPresione ENTER para regresar al menu de Playlist\n\n";
                cin.get();
                system("cls");

            }

        //PLAYIST Mover de Fila a Playlist
            else if (opc1 == "5") {
                system("cls");
                cout << "PLAYLIST: Moviendo Fila a Playlist \n";

                //No puede mover canciones si Playlista no esta vacia y la FP tiene que tener almenos una cancion
                if (pila == NULL) {
                    if (colaVacia(frenteCola)) {
                        cout << "La Fila de Reproduccion No Puede Estar Vacia \n";
                        cout << "\n\nPresione ENTER para regresar al menu de Playlist\n\n";
                        cin.get();
                        system("cls");
                    }

                    else {
                        cout << "La Fila de Reproduccion Ya Tiene Canciones \n";
                        filaAPlaylis(frenteCola, pila);
                        cout << "\n\nPresione ENTER para regresar al menu de Playlist\n\n";
                        cin.get();
                        system("cls");
                    }

                }
                else {
                    cout << "La pila tiene que estar vacia para hacer esta operación\n";
                }
            }

    //MOSTRAR PLAYLIST

            else if (opc1 == "6") {
                system("cls");
             
                cout << "PLAYLIST: Mostrar Playlist\n\n";
                cout << "La playlist Elegida es: \n\n";
                mostrarPila(pila);
                cout << "\n\nPresione ENTER para regresar al menu de Playlist";
                cin.get();
                system("cls");
            }

    //PLAYLIST: EXPORTAR A CSV 

            else if (opc1 == "7") {
                system("cls");
                cout << "PLAYLIST: Exportando Playlist a CSV\n\n ";
                cout << "Insertar nombre de archivo CSV para exportar playlist: ";

                getline(std::cin, pathCSV, '\n');

                write_csv(pila, pathCSV);

                cin.get();
                system("cls");
            }
            else if (opc1 == "8") {
                system("cls");
                menuPrincipal = 1;

            }




        }

        else if (menuPrincipal == 3) {
            cout << "PLATAFORMA PARTY MIX: FILA REPRODUCCION \n\n";
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
                cout << "FILA DE REPRODUCCION: Eliminar Cancion\n\n";
                eliminarCola(frenteCola, finalCola, output);
                cout << "\nCancion eliminada satisfactoriamente, presione ENTER para regresar al menu";
                cin.get();
                system("cls");
            }
            else if (opc1 == "3") {
                system("cls");
                cout << "FILA DE REPRODUCCION: Sincronizar\n\n";
                playlistToFila(frenteCola, finalCola, pila);
                cout << "\nFila de Reproduccion Sincronizada Correctamente. Presione ENTER para regresar al menu";
                cin.get();
                system("cls");

            }

            else if (opc1 == "4") {
                if (frenteCola == NULL) {
                    system("cls");
                    cout << "FILA DE REPRODUCCION: Mostrar Canciones dentro de Fila de Reproduccion\n\n";
                    cout << "\nLa Fila de Reproduccion se Encuentra Vacia, Use la Opcion 1 para Anadir una Cancion.\n";
                    cout << "\nPresione ENTER para regresar al menu";
                    cin.get();
                    system("cls");
                }
          
                else {
                    system("cls");
                    cout << "FILA DE REPRODUCCION: Mostrar Canciones dentro de Fila de Reproduccion\n\n";
                    mostrarCola(frenteCola);
                    cout << "\nPresione ENTER para regresar al menu";
                    cin.get();
                    system("cls");
                }
            }
            else if (opc1 == "5") {
                system("cls");
                string cancionReporducindo;
                sacarPila(pila, cancionReporducindo);
                std::cout << "Reproduciendo canción " << cancionReporducindo;
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

    // Declarando una variable que puede almacenar la dirección de una variable de tipo Nodo.
    // Nodo *pila = NULL;

    // std::cout << "Hello World!\n";
    // std::cin>>valorUsuario;
    // agregarPila(pila, valorUsuario);



    // while(pila != NULL){
    //   sacarPila(pila, ss);
    //   std::cout << "pilaaaaad! "<<ss<<" sdf";
    // }

    menu();
    // read_csv_words();
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