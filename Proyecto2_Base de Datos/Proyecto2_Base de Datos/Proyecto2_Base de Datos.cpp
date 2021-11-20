#include <iostream>
#include<stdio.h> 
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <string.h>

using namespace std;

class NodoEstudiante {
private:
    string apellido;
    string nombre;
    string ingreso;
    string dpi;
    string facultadad;
    string tipo;
    string clase1;
    string clase2;
    string clase3;
    string clase4;
    string clase5;
    string nota1;
    string nota2;
    string nota3;
    string nota4;
    string nota5;
    string indice;

    NodoEstudiante* next;
    NodoEstudiante* prev;

    // Para que se puda acceder a los atributos privados
    friend class doubleLinkedListEstudiante;
};

class NodoTrabajador {
private:
    string apellido;
    string nombre;
    string dpi;
    string carnet;
    string salario;
    string profesor;
    string clase1;
    string clase2;
    string clase3;
    NodoTrabajador* next;
    NodoTrabajador* prev;
};

class doubleLinkedListEstudiante {
public:
    // Constructor
    doubleLinkedListEstudiante();
    // Deconstructor
    ~doubleLinkedListEstudiante();
    string getFront() const;
    string getBack() const;

    void addFront(string papellido, string pnombre, string pingreso, string pdpi, string pfacultadad, string ptipo, string pclase1, string pclase2, string pclase3, string pclase4, string pclase5, string pnota1, string pnota2, string pnota3, string pnota4, string pnota5, string pindice);

    void addBack(string papellido, string pnombre, string pingreso, string pdpi, string pfacultadad, string ptipo, string pclase1, string pclase2, string pclase3, string pclase4, string pclase5, string pnota1, string pnota2, string pnota3, string pnota4, string pnota5, string pindice);

    void removeFront();
    void removeBack();
    void printReverse();
    void printFoward();

    // Buscar y devolver el nombre de la persona.
    void buscarDPI(string pdpi);


    // Cantidad de nodos.
    int lenLista();


    // Cantidad de estudiantes por facultad.
    void lenFacultad();


    // Promedio de un estudiante
    void avgEstudiante(string pdpi);



    // Nota mas alta de un estudiante
    void MaxNotaEstudiante(string pdpi);


    // CREACION DE NODOS CENTINELAS
private:
    NodoEstudiante* header;
    NodoEstudiante* trailer;
};

// funcion Constructor
doubleLinkedListEstudiante::doubleLinkedListEstudiante() {
    // cout<<"Ejecucanto el deconstructor";
    // Creacion de nodos
    header = new NodoEstudiante;
    trailer = new NodoEstudiante;
    // Asignar puntos
    header->next = trailer;
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL;
};

string doubleLinkedListEstudiante::getFront() const {
    return header->next->dpi;
};

string doubleLinkedListEstudiante::getBack() const {
    return trailer->prev->dpi;
};

void doubleLinkedListEstudiante::addFront(string papellido, string pnombre, string pingreso, string pdpi, string pfacultadad, string ptipo, string pclase1, string pclase2, string pclase3, string pclase4, string pclase5, string pnota1, string pnota2, string pnota3, string pnota4, string pnota5, string pindice) {
    cout << "agregando\n";
    // Nodo insertado al principio de la LISTAS es decir va corriendo todos los nodos.
    NodoEstudiante* nd = new NodoEstudiante;

    // insertando valores a mi nuevo nodo
    nd->apellido = papellido;
    nd->nombre = pnombre;
    nd->ingreso = pingreso;
    nd->dpi = pdpi;
    nd->facultadad = pfacultadad;
    nd->tipo = ptipo;
    nd->clase1 = pclase1;
    nd->clase2 = pclase2;
    nd->clase3 = pclase3;
    nd->clase4 = pclase4;
    nd->clase5 = pclase5;
    nd->nota1 = pnota1;
    nd->nota2 = pnota2;
    nd->nota3 = pnota3;
    nd->nota4 = pnota4;
    nd->nota5 = pnota5;
    nd->indice = pindice;

    // Cambiando mis punteros de mi nuevo nodo
    nd->prev = header;
    nd->next = header->next;

    // Cambiando los punteros  del header
    header->next->prev = nd;
    header->next = nd;

}

void doubleLinkedListEstudiante::addBack(string papellido, string pnombre, string pingreso, string pdpi, string pfacultadad, string ptipo, string pclase1, string pclase2, string pclase3, string pclase4, string pclase5, string pnota1, string pnota2, string pnota3, string pnota4, string pnota5, string pindice) {

    // Nodo insertado al final de la LISTA
    NodoEstudiante* nd = new NodoEstudiante;

    // insertando valor a mi nuevo nodo
    nd->apellido = papellido;
    nd->nombre = pnombre;
    nd->ingreso = pingreso;
    nd->dpi = pdpi;
    nd->facultadad = pfacultadad;
    nd->tipo = ptipo;
    nd->clase1 = pclase1;
    nd->clase2 = pclase2;
    nd->clase3 = pclase3;
    nd->clase4 = pclase4;
    nd->clase5 = pclase5;
    nd->nota1 = pnota1;
    nd->nota2 = pnota2;
    nd->nota3 = pnota3;
    nd->nota4 = pnota4;
    nd->nota5 = pnota5;
    nd->indice = pindice;

    // Cambiando mis punteros de mi nuevo nodo
    nd->prev = trailer->prev;
    nd->next = trailer;

    // Cambiando los punteros  del trailer y el tail
    trailer->prev->next = nd;
    trailer->prev = nd;
};

void doubleLinkedListEstudiante::removeFront() {
    // guardando el nodo next al nodo head
    NodoEstudiante* nd = header->next->next;
    // eliminar el nodo head
    delete header->next;
    // Actualizacion de punteros
    header->next = nd;
    nd->prev = header;
};

void doubleLinkedListEstudiante::removeBack() {
    NodoEstudiante* nd = trailer->prev->prev;
    // eliminar el nodo tail
    delete trailer->prev;
    // Actualizacion de punteros
    trailer->prev = nd;
    nd->next = trailer;
};

void doubleLinkedListEstudiante::printReverse() {
    // imprimir valores de atras para adelante
    // Haciendo referencia al ultimo nodo tail.
    NodoEstudiante* nd = trailer->prev;
    // recoriendo mi lista DOBLEMENTE enlazada
    while (nd != header) {
        cout << nd->dpi << "  ";
        // Actualizmos nodo
        nd = nd->prev;
    }
};

void doubleLinkedListEstudiante::printFoward() {
    // imprimir valores de adelante para atras, de inicio al final
    // Haciendo referencia al primer elemeto de la lista head
    NodoEstudiante* nd = header->next;
    // recoriendo mi lista DOBLEMENTE enlazada
    while (nd != trailer) {
        cout << nd->nombre << "  \n";
        // Actualizmos nodo
        nd = nd->next;
    }
};

void doubleLinkedListEstudiante::buscarDPI(string pdpi) {
    // Recorrer todos  mis nodos y encontrar mi dpi
    // Haciendo referencia al primer elemeto de la lista head
    NodoEstudiante* nd = header->next;
    // recoriendo mi lista DOBLEMENTE enlazada
    while (nd != trailer) {
        if (nd->dpi == pdpi) {
            cout << "Se encontro el dpi el nombre de la persona es:\n" << nd->nombre << " " << nd->apellido << "\n";
            break;
        }
        // Actualizmos nodo
        nd = nd->next;
    }
};

int doubleLinkedListEstudiante::lenLista() {
    // Recorrer todos  mis nodos y encontrar mi dpi
    // Haciendo referencia al primer elemeto de la lista head
    NodoEstudiante* nd = header->next;

    int contador = 0;
    // recoriendo mi lista DOBLEMENTE enlazada
    while (nd != trailer) {
        contador++;
        // Actualizmos nodo
        nd = nd->next;
    }

    return contador;


};

void doubleLinkedListEstudiante::lenFacultad() {
    // Recorrer todos  mis nodos y encontrar mi dpi
    // Haciendo referencia al primer elemeto de la lista head
    NodoEstudiante* nd = header->next;

    int contador0 = 0;
    int contador1 = 0;
    int contador2 = 0;
    int contador3 = 0;
    int contador4 = 0;
    // recoriendo mi lista DOBLEMENTE enlazada
    while (nd != trailer) {

        if (nd->facultadad == "humanidades") {
            contador0++;
        }
        else if (nd->facultadad == "ingenieria") {
            contador1++;
        }
        else if (nd->facultadad == "economia") {
            contador2++;
        }
        else if (nd->facultadad == "salud") {
            contador3++;
        }
        else if (nd->facultadad == "ambientales") {
            contador4++;
        }
        // Actualizmos nodo
        nd = nd->next;
    }

    cout << "Cantidad de estudiantes por facultad: \n" << "Humanidades: " << contador0 << "\n" << "ingenieria: " << contador1 << "\n" << "economia: " << contador2 << "\n" << "salud: " << contador3 << "\n" << "ambientales: " << contador4 << "\n";
    cout << "Cantidad de estudiantes por facultad: \n" << "Humanidades: " << contador0 << "\n" << "ingenieria: " << contador1 << "\n" << "economia: " << contador2 << "\n" << "salud: " << contador3 << "\n" << "ambientales: " << contador4 << "\n";

};

void doubleLinkedListEstudiante::avgEstudiante(string pdpi) {
    // Recorrer todos  mis nodos y encontrar mi dpi
    // Haciendo referencia al primer elemeto de la lista head
    NodoEstudiante* nd = header->next;
    // recoriendo mi lista DOBLEMENTE enlazada
    while (nd != trailer) {
        if (nd->dpi == pdpi) {
            break;

        }
        // Actualizmos nodo
        nd = nd->next;
    }
    cout << "Se encontro al estudiante calculando promedio de : " << nd->nombre << "\n";
    int n1, n2, n3, n4, n5;
    if (nd->nota1 != "null") {
        n1 = stoi(nd->nota1);
    }
    if (nd->nota2 != "null") {
        n2 = stoi(nd->nota2);
    }
    if (nd->nota3 != "null") {
        n3 = stoi(nd->nota3);
    }
    if (nd->nota4 != "null") {
        n4 = stoi(nd->nota4);
    }
    if (nd->nota5 != "null") {
        n5 = stoi(nd->nota5);
    }

    float avg = (n1 + n2 + n3 + n4 + n5) / 5;

    cout << "EL promedio del alumno es de " << avg;
};

void doubleLinkedListEstudiante::MaxNotaEstudiante(string pdpi) {
    // Recorrer todos  mis nodos y encontrar mi dpi
    // Haciendo referencia al primer elemeto de la lista head
    NodoEstudiante* nd = header->next;
    // recoriendo mi lista DOBLEMENTE enlazada
    while (nd != trailer) {
        if (nd->dpi == pdpi) {
            break;

        }
        // Actualizmos nodo
        nd = nd->next;
    }
    cout << "Se encontro al estudiante calculando la nota mas alta y la minima de :" << nd->nombre << "\n";
    int n1, n2, n3, n4, n5;
    if (nd->nota1 != "null") {
        n1 = stoi(nd->nota1);
    }
    if (nd->nota2 != "null") {
        n2 = stoi(nd->nota2);
    }
    if (nd->nota3 != "null") {
        n3 = stoi(nd->nota3);
    }
    if (nd->nota4 != "null") {
        n4 = stoi(nd->nota4);
    }
    if (nd->nota5 != "null") {
        n5 = stoi(nd->nota5);
    }

    vector<int> result;

    result.push_back(n1);
    result.push_back(n2);
    result.push_back(n3);
    result.push_back(n4);
    result.push_back(n5);

    int finalSize = result.size();

    // Assume first element as maximum and minimum
    int max = result[0];
    int min = result[0];


    int valorFinal = 0;
    for (int i = 1; i < finalSize; i++)
    {
        // If current element is greater than max
        if (result[i] > max) {
            max = result[i];
            valorFinal = i;
        }
        // If current element is smaller than min
        if (result[i] < min) {
            min = result[i];
        }
    }

    if (valorFinal == 0) {
        // La clase 1 es la mas alta


      // Print maximum and minimum element
        cout << "\nNota maxima =" << max << " el nombre de la clase es " << nd->clase1 << "\n";
        // cout<<"Noma minima =" << min << "\n";

    }
    else if (valorFinal == 1) {
        cout << "\nNota maxima =" << max << " el nombre de la clase es " << nd->clase2 << "\n";

    }
    else if (valorFinal == 2) {
        cout << "\nNota maxima =" << max << " el nombre de la clase es " << nd->clase3 << "\n";

    }
    else if (valorFinal == 3) {
        cout << "\nNota maxima =" << max << " el nombre de la clase es " << nd->clase4 << "\n";

    }
    else if (valorFinal == 4) {
        cout << "\nNota maxima =" << max << " el nombre de la clase es " << nd->clase5 << "\n";

    }

};

// Deconstructor para liberar memoria
doubleLinkedListEstudiante::~doubleLinkedListEstudiante() {
    // ciclo para eliminar todos los nodos, se para cuando la lista esta vacia
    while (header->next != trailer) {
        removeFront();
    }
    // eliminando los CENTINELAS
    delete header;
    delete trailer;
};

// READ CSV FOR STUDENT
void read_csv_student(string csvPath, doubleLinkedListEstudiante& listaTotal, doubleLinkedListEstudiante& listaPos, doubleLinkedListEstudiante& listaPre, doubleLinkedListEstudiante& listaDoc)
{
    // LEE UN ARCHIVO csv Y CREA UNA DOUBLE LINKED LIST APARTIR DE ESTE.
      // File pointer
    fstream file;

    // Open an existing file
    file.open(csvPath, ios::in);

    if (!file) {
        cout << "El archivo CSV ingresado no existe.\n" << endl;
        // exit(1);
    }

    string line;
    int contador = 0;

    // Separando cada linea del archivo
    while (getline(file, line, '\n')) {

        // Creacion de varaible stringstream para separar las palabras de la linea.
        stringstream sst(line);

        // Creacion de vector para manipulacion de palabras
        vector<string> result;

        // Llenado de vector con las palabras separadas por coma
        while (sst.good())
        {
            string substr;
            getline(sst, substr, ',');
            result.push_back(substr);
        }

        // tamano del vector creado
        int n = result.size();
        // Agregacion de nulos
        for (int i = n; i < 11; i++) {
            result.push_back("null");
        }

        // Separando  las notas del nombre de la clase
        for (int i = 6; i < 11; i++) {
            string word = string(result[i]);

            // Separando el nombre de la clase y su nota
            string nombreClase = word.substr(0, word.find(" "));
            string nota = word.substr(word.find(" ") + 1);

            // Cambiando el vector para que solo almacene el nombre de la clase
            if (nombreClase != "null") {
                result[i] = nombreClase;
            }
            else {
                result[i] = "null";
            }

            // Agregando a su vector nuevas notas
            if (nota != "null") {
                result.push_back(nota);
            }
            else {
                result.push_back("null");
            }
        }


        // Agregando indice para saber que nodo es
        string scontador = to_string(contador);
        result.push_back(scontador);

        // Tamano final del vector
        int finalSize = result.size();

        // IMPRIMIR VALORES DENTRO DEL VECTOR
        // for (int i = 0; i<finalSize; i++){
        //   cout<< result[i] <<"\n";
        // }

        // CREACION DE LISTAS DOBLEMENTE ENCADENADAS

        // Lista que contiene a todos los estudiantes
        listaTotal.addBack(result[0], result[1], result[2], result[3], result[4], result[5], result[6], result[7], result[8], result[9], result[10], result[11], result[12], result[13], result[14], result[15], result[16]);

        if (result[5] == "postgrado") {
            listaPos.addBack(result[0], result[1], result[2], result[3], result[4], result[5], result[6], result[7], result[8], result[9], result[10], result[11], result[12], result[13], result[14], result[15], result[16]);
        }
        else if (result[5] == "pregrado") {
            listaPre.addBack(result[0], result[1], result[2], result[3], result[4], result[5], result[6], result[7], result[8], result[9], result[10], result[11], result[12], result[13], result[14], result[15], result[16]);
        }
        else {
            listaDoc.addBack(result[0], result[1], result[2], result[3], result[4], result[5], result[6], result[7], result[8], result[9], result[10], result[11], result[12], result[13], result[14], result[15], result[16]);
        }

        contador++;
    }

    file.close();
};

// READ CSV FOR WORKERS
void read_csv_workers(string csvPath)
{
    // LEE UN ARCHIVO csv Y CREA UNA DOUBLE LINKED LIST APARTIR DE ESTE.
      // File pointer
    fstream file;

    // Open an existing file
    file.open(csvPath, ios::in);

    if (!file) {
        cout << "El archivo CSV ingresado no existe.\n" << endl;
        // exit(1);
    }

    string line;
    int contador = 0;

    // Separando cada linea del archivo
    while (getline(file, line, '\n')) {

        // Creacion de varaible stringstream para separar las palabras de la linea.
        stringstream sst(line);

        // Creacion de vector para manipulacion de palabras
        vector<string> result;

        // Llenado de vector con las palabras separadas por coma
        while (sst.good())
        {
            string substr;
            getline(sst, substr, ',');
            result.push_back(substr);
        }

        // tamano del vector creado
        int n = result.size();
        // Agregacion de nulos para mantener siempre la misma cantidad de nulos
        for (int i = n; i < 9; i++) {
            result.push_back("null");
        }

        // Agregando indice para saber que nodo es
        string scontador = to_string(contador);
        result.push_back(scontador);


        // Tamano final del vector
        int finalSize = result.size();

        // IMPRIMIR VALORES DENTRO DEL VECTOR
        // for (int i = 0; i<finalSize; i++){
        //   cout<< result[i] <<"\n";
        // }

        // CREACION DE LISTAS DOBLEMENTE ENCADENADAS

        if (result[5] == "true") {
            cout << "Si es docente\n";
        }
        else {
            cout << "este no es docente \n";
        }

        contador++;
    }
    file.close();
};

int main() {

    // Creacion de objetos
    doubleLinkedListEstudiante estudiantesTotales;
    doubleLinkedListEstudiante EstudiantesPos;
    doubleLinkedListEstudiante EstudiantesPre;
    doubleLinkedListEstudiante EstudiantesDoc;

    read_csv_student("./estu_peque.csv", estudiantesTotales,
        EstudiantesPos, EstudiantesPre, EstudiantesDoc);

    // buscar DPI de estudiantes
    estudiantesTotales.buscarDPI("7439 20543 0113");
    cout << "\n";

    // total de estudiantes
    int size = estudiantesTotales.lenLista();
    cout << "\n Total de estudiantes son de: " << size;

    // total de estudiantes POSTGRADO
    int size0 = EstudiantesPos.lenLista();
    cout << "\n Total de estudiantes POSTGRADO son de: " << size0;

    // total de estudiantes PREGRADO
    int size1 = EstudiantesPre.lenLista();
    cout << "\n Total de estudiantes PREGRADO son de: " << size1;

    // total de estudiantes DOCTORADO
    int size2 = EstudiantesDoc.lenLista();
    cout << "\n Total de estudiantes DOCTORADO son de: " << size2;

    cout << "\n";

    // total de estudiantes por facultadad
    estudiantesTotales.lenFacultad();


    cout << "\n";
    cout << "\n";

    estudiantesTotales.avgEstudiante("7366 49505 0102");



    cout << "\n";
    cout << "\n";

    estudiantesTotales.MaxNotaEstudiante("7366 49505 0102");

}

    // MENU
void menu() {
    string opc;
    string opc1;
    string pathCSV;
    string nameC;
    string nameA;


    int menuPrincipal = 1;
    if (menuPrincipal == 1) {

        cout << "PLATAFORMA UNIVERSIDAD: Control de Datos\n\n";
        cout << "[ 1 ] Gestion de Estudiantes \n";
        cout << "[ 2 ] Gestion de Trabajadores\n";
        cout << "[ 3 ] Realizar Busqueda por DPI\n\n";
        cout << "[ 4 ] Salir del Programa\n\n";
        cout << "Opcion: ";
        getline(std::cin, opc, '\n');
        system("cls");
    }


// REALIZAR BUSQUEDA por DPI





//MENU DE ESTUDIANTES

    if (opc == "1") {
        cout << "PLATAFORMA UNIVERSIDAD: Gestion de Estudiantes \n\n";
        menuPrincipal = 2;
        cout << "[ 1 ] Estudiantes de Pregrado \n";
        cout << "[ 2 ] Estudiantes de Posgrado \n\n";
        cout << "[ 3 ] Conocer Promedio de un Estudiante \n\n";
        cout << "[ 4 ] Conocer Numero de Estudiantes \n\n";
        cout << "[ 7 ] Regresar al menu principal\n\n";
        cout << "Opcion: ";
        getline(std::cin, opc1, '\n');
}


//REQUISITOS FUNCIONALES DE ESTUDIANTES de Pregrado


    if (opc1 == "1") {
        system("cls");
        cout << "ESTUDIANTES: Gestion Estudiantes de Pregrado\n\n";
        cout << "[ 1 ] Mostrar Listado de Estudiantes de Pregrado \n\n";
        cout << "[ 2 ] Exportar Archivo con Lista de Estudiantes de Pregrado\n\n";
        cout << "[ 3 ] Busqueda de Nota mas Alta de Estudiante\n\n";
        cout << "[ 7 ] Regresar al Menu Estudiantes\n\n";
        cout << "Opcion: ";
        getline(std::cin, opc1, '\n');
    }

//MOSTRAR LISTADO DE ESTUDIANTES
        if (opc1 == "1") {
            system("cls");
            cout << "ESTUDIANTES: Anadir Cancion\n\n";

            cout << "\nCancion anadida satisfactoriamente, presione ENTER para regresar al menu";
            cin.get();
            system("cls");
        }


//REQUISITOS FUNCIONALES DE ESTUDIANTES de Postgrado

    if (opc1 == "2") {
        system("cls");
        cout << "ESTUDIANTES: Gestion Estudiantes de Posgrado\n\n";
        cout << "[ 1 ] Mostrar Listado de Estudiantes de Posgrado \n\n";
        cout << "[ 2 ] Exportar Archivo con Lista de Estudiantes de Posgrado \n\n";
        cout << "[ 7 ] Regresar al Menu Estudiantes\n\n";
        cout << "Opcion: ";
        getline(std::cin, opc1, '\n');
    }

//Conocer Promedio de un Estudiante de Pregrado y Posgrado
    if (opc1 == "3") {
        int dpi;
        system("cls");
        cout << "ESTUDIANTES: Conocer Promedio de un Estudiante\n\n";
        cin >> dpi;
        cout << "El Promedio del Estudiante con DPI " << dpi << "es: ";
        cout << "\n\nPresione ENTER para regresar al menu";
        cin.get();
        system("cls");
    }



// GESTION DE TRABAJADORES



    else if (opc == "2") {
        menuPrincipal = 3;
        cout << "PLATAFORMA UNIVERSIDAD: Gestion de Trabajadores \n\n";
        cout << "[ 1 ] Trabajadores Docentes\n";
        cout << "[ 2 ] Trabajadores No Docentes\n";
        cout << "[ 3 ] Calcular Salario Promedio\n";
        cout << "[ 7 ] Regresar al menu principal\n\n";

        cout << "Opcion: ";
        getline(std::cin, opc1, '\n');
    }







//CALCULAR SALARIO PROMEDIO

    else if (opc1 == "3") {
        menuPrincipal = 3;
        cout << "PLATAFORMA UNIVERSIDAD: Calculo de Salario de Promedio \n\n";
        cout << "[ 1 ] Trabajadores Docentes\n";
        cout << "[ 2 ] Trabajadores No Docentes\n";
        cout << "[ 3 ] Ambos tipos de Trabajadores\n";
        cout << "[ 7 ] Regresar al menu principal\n\n";

        cout << "Opcion: ";
        getline(std::cin, opc1, '\n');
    }

    // read_csv_workers("./traba_peque.csv");

    // // Creacion de objetos
    // doubleLinkedListEstudiante ll;
    // ll.addBack("Barrios","Lucia","2002","1 12436 0413","humanidades","postgrado","neurologia","calculo","razonamiento","auditoria","microeconomia", "93", "32", "34", "54", "45", "9999");
    // ll.addBack("Santiago","joos","2002","2 12436 0413","humanidades","postgrado","neurologia","calculo","razonamiento","auditoria","microeconomia", "93", "32", "34", "54", "45", "9999");
    // ll.addBack("Barrera","rebeca","2002","3 12436 0413","humanidades","postgrado","neurologia","calculo","razonamiento","auditoria","microeconomia", "93", "32", "34", "54", "45", "9999");

    // ll.printFoward();

    // cout<<"\nsdfsdfsdf ";
    // ll.printReverse();


