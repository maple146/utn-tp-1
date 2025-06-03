#include <iostream>
#include "funciones.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "spanish");
    int option;

    do
    {
        cout << "======" << endl;
        cout << "Enfrentados - Menu" << endl;

        cout << "1 - Jugar" << endl;
        cout << "2 - Estadisticas" << endl;
        cout << "3 - Creditos" << endl;
        cout << "0 - Salir" << endl;


        cout << "Seleccione una opcion: ";
        // TODO: Agregar condicion de if
        cin >> option;

        switch (option)
        {
        case 1:
            jugar();
            break;
        case 2:
            mostrarEstadisticas();
            break;
        case 3:
            mostrarCreditos();
            break;
        case 0:
            cout << "Desea salir del juego?" << endl;
        // TODO: Agregar confirmacion
        default:
            break;

        }

    }
    while (option != 0);

    return 0;

}
