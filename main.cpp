#include <iostream>
#include "funciones.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "spanish");
    int option;
    string Player1,Player2;

    menu();
    // ACA EMPEZARIA EL JUEGO
    system("cls");
    seleccionarNombres(Player1,Player2);
        /*cout << Player1 << endl;
        cout << Player2 << endl;*/

    return 0;

}
