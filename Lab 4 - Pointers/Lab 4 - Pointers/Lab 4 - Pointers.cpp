#include <iostream>
#include <ctime>
using namespace std;



int main()
{
    cout << "!BANG!" << endl;
    cout << "!Y Arrancan!" << endl;



    

    string pista[70] = {"-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-" };

    int* posConejo;
    int* posTortuga;

    int poSimpleConejo = 0;
    int poSimpleTortuga = 0;

    int posAntiguaConejo = 0;
    int posAntiguaTortuga = 0;

    //while (posConejo != 70 && *posTortuga =! 70)

    srand(time(NULL));
    int i, n, aleatorioConejo, aleatorioTortuga, DESDE = 1, HASTA = 10;

    for (i = 1; i <= 1; i++)
    {

        pista[posAntiguaConejo] = '-';
        pista[posAntiguaTortuga] = '-';


        aleatorioConejo = rand() % (HASTA - DESDE + 1) + DESDE;
        aleatorioTortuga = rand() % (HASTA - DESDE + 1) + DESDE;


        if (aleatorioTortuga <= 5) {
            //  paso veloz tortuga avanza 3 cuados a la derecha
            int posSiguienteTortuga = poSimpleTortuga + 3;
            pista[posSiguienteTortuga] = 'T';
            posAntiguaTortuga = posSiguienteTortuga;
        }
        else if ((aleatorioTortuga <= 7) && (aleatorioTortuga > 5)) {
            //  resbalon tortuga avanza 6 cuados a la izquierda
            // AGREGAR CONDICIONAL SI LA RESTA DE LA POSSIGUIENTE DE LA TORTUGA ES NEGATIVO COLAR LA POSISITUENTE EN 0
            int posSiguienteTortuga = poSimpleTortuga - 6;
            pista[posSiguienteTortuga] = 'T';
            posAntiguaTortuga = posSiguienteTortuga;
        }
        else {
            //  paso lento tortuga avanza 1 cuados a la derecha
            int posSiguienteTortuga = poSimpleTortuga + 1;
            pista[posSiguienteTortuga] = 'T';
            posAntiguaTortuga = posSiguienteTortuga;
        }

            //  Duerme, no se mueve
        if (aleatorioConejo <= 2) {
            int posSiguienteConejo = poSimpleConejo;
            pista[posSiguienteConejo] = 'H';
            posAntiguaConejo = posSiguienteConejo;
        }

            // Gran Salto, 9 cuadros a la derecha
        if (aleatorioConejo > 2 && aleatorioConejo <= 4) {
            int posSiguienteConejo = poSimpleConejo + 9;
            pista[posSiguienteConejo] = 'H';
        }

           // Gran Resbalon, 12 cuadros a la izquierda
        if (aleatorioConejo == 5) {
             int posSiguienteConejo = poSimpleConejo - 12;
             pista[posSiguienteConejo] = 'H';
             posAntiguaConejo = posSiguienteConejo;

        }

            // Salto Pequeno, 1 cuadro a la derecha
        if (aleatorioConejo > 5 && aleatorioConejo <= 8) {
            int posSiguienteConejo = poSimpleConejo + 1;
            pista[posSiguienteConejo] = 'H';
        }

        // Resbalon Pequeno, 2 cuadro a la derecha
        else if(aleatorioConejo > 8 && aleatorioConejo <= 10)
        {
            int posSiguienteConejo = poSimpleConejo - 2;
            pista[posSiguienteConejo] = 'H';
            posAntiguaConejo = posSiguienteConejo;
        }

        for (string i : pista) {

            std::cout << i << ' ';
        }


    }
    cout << endl;
    system("pause");
}