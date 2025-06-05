#include <iostream>
#include "funciones.h"

using namespace std;


void menu()
{
    int option;
    char confirm;


    do
    {
        system("cls");
        cout << "============================================================" << endl;
        cout << "                       Enfrendados" << endl;
        cout << "============================================================" << endl;

        cout << "1 - Jugar" << endl;
        cout << "2 - Estadisticas" << endl;
        cout << "3 - Creditos" << endl;
        cout << "============================================================" << endl;
        cout << "0 - Salir" << endl << endl;


        cout << "Seleccione una opcion: ";
        cin >> option;
        while (option<0 || option>3)
        {
            if (option<0 || option>3)
            {
                cout << "Opcion invalida, por favor seleccione otra vez" << endl;
                cin >> option;
            }
        }

        switch (option)
        {
        case 1:
            return;
        case 2:
            mostrarEstadisticas();
            break;
        case 3:
            mostrarCreditos();
            break;
        case 0:
            cout << "Desea salir del juego? (S/N)" << endl;
            cin >> confirm;
            confirm = toupper(confirm);
            if (confirm == 'S')
            {
                exit(0);
            }
            else
            {
                break;
            }

        default:
            break;

        }

    }
    while (option != 0);
}

void jugar()
{
    system("cls");
    cout << "Seleccionado jugar" << endl;
    cout << "Presione cualquier tecla para volver al menu..." << endl;
    system("pause>nul");
}

void mostrarEstadisticas()
{
    system("cls");
    cout << "Seleccionado estadisticas" << endl;
    cout << "Presione cualquier tecla para volver al menu..." << endl;
    system("pause>nul");
}

void mostrarCreditos()
{
    system("cls");
    cout << "Seleccionado creditos" << endl;
    cout << "Presione cualquier tecla para volver al menu..." << endl;
    system("pause>nul");
}

void seleccionarNombres(string &Player1, string &Player2)
{

    cout << "============================================================" << endl;
    cout << "                       Enfrendados" << endl;
    cout << "============================================================" << endl << endl;


    cin.ignore();


    cout << "Ingresar nombre de Jugador 1: ";

    getline(cin, Player1);

    cout << "Ingresar nombre de Jugador 2: ";

    getline(cin, Player2);
}

void interfazJuego(string Player1, string Player2, int numeroDeRonda, int dadoJugador1, int dadoJugador2, int puntajeJugador1, int puntajeJugador2) {

    cout << "============================================================" << endl;
    cout << "                       Enfrendados" << endl;
    cout << "============================================================" << endl << endl;

    cout << "Turno de:" << Player1 << endl;
    cout << "Dados objetivo (d12):" << puntajeJugador1 << endl;
    cout << "Stock actual: 6 dados (valores) [3, 4, 2, 6, 1, 5]" << endl;
    cout << "Combinacion elegida" << "3 + 4 + 5 = 12" << endl;
    cout << "Dados elegidos: 3 (3 dados)" << endl;
    cout << "Puntos: 12 x 3 = 36" << endl;
    cout << "Transfiere 3 dados a Maria" << endl;
    cout << Player1 << "3 dados restantes, 36 pts" << endl;
    cout << Player2 << "9 dados (recibio 3)" << endl;

}

int tirarDado(int caras)
{
    return rand() % caras + 1;
}
