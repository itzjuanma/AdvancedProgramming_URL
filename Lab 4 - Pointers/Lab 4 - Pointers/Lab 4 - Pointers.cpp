#include <iostream>
#include <ctime>
using namespace std;



int main()
{
    string pista[70] = { "-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-","-", "-", "-", "-", "-" };

    int* posConejo;
    int* posTortuga;

    int poSimpleConejo = 0;
    int poSimpleposTortuga = 0;

    int posAntiguaConejo = 0;
    int posAntiguaTortuga = 0;


    srand(time(NULL));
    int i, n, aleatorioConejo, aleatorioTortuga, DESDE = 1, HASTA = 10;

    for (i = 1; i <= 1; i++)
    {

        pista[posAntiguaConejo] = '-';
        pista[posAntiguaTortuga] = '-';


        aleatorioConejo = rand() % (HASTA - DESDE + 1) + DESDE;
        aleatorioTortuga = rand() % (HASTA - DESDE + 1) + DESDE;


        if (aleatorioTortuga <= 5) {
            //  paso velor tortuga avanza 3 cuados a la derecha
            int posSiguienteTortuga = poSimpleConejo + 3;
            pista[posSiguienteTortuga] = 'T';
            posAntiguaTortuga = posSiguienteTortuga;
        }
        else if ((aleatorioTortuga <= 7) && (aleatorioTortuga > 5)) {
            //  resbalon tortuga avanza 6 cuados a la izquierda
            
            int posSiguienteTortuga = poSimpleConejo - 6;
            pista[posSiguienteTortuga] = 'T';
            posAntiguaTortuga = posSiguienteTortuga;
        }
        else {
            //  paso lento tortuga avanza 1 cuados a la derecha
            int posSiguienteTortuga = poSimpleConejo + 1;
            pista[posSiguienteTortuga] = 'T';
            posAntiguaTortuga = posSiguienteTortuga;
        }






        for (string i : pista) {

            std::cout << i << ' ';
        }


    }
    cout << endl;
    system("pause");
}
