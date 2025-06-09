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

void seleccionarNombres(string &jugador1, string &jugador2)
{

    cout << "============================================================" << endl;
    cout << "                       Enfrendados" << endl;
    cout << "============================================================" << endl << endl;


    cin.ignore();


    cout << "Ingresar nombre de Jugador 1: ";

    getline(cin, jugador1);

    cout << "Ingresar nombre de Jugador 2: ";

    getline(cin, jugador2);
}

void interfazJuego(string jugador1, string jugador2, int numeroDeRonda, int dadosJugador1, int dadosJugador2, int puntajeJugador1, int puntajeJugador2,bool turno)
{
    system("cls");
    int contadorStock=0,seleccion,sumaStock=0,x,dadosObjetivo[2],dadosStockElegidos[12],dadosStock[12],resultadoObjetivo=0;
    char confirmacion;
    for (int x=0; x<2; x++)
    {
        dadosObjetivo[x] = tirarDado(12);
        resultadoObjetivo+= dadosObjetivo[x];
    }

    cout << "============================================================" << endl;
    cout << "                       Enfrendados 123" << endl;
    cout << "============================================================" << endl << endl;

    cout << "Turno de:";
    if (turno == true)
    {
        cout << jugador1;
    }
    else
    {
        cout << jugador2;
    }
    cout << "                                               Dados objetivo (d12):" << dadosObjetivo[0] << " + " << dadosObjetivo[1] << " = " << resultadoObjetivo << endl;
    cout << "Stock actual: ";
    if (turno==true)
    {
        cout << dadosJugador1 << ": [";
        for (x=0; x<dadosJugador1; x++)
        {
            dadosStock[x] = tirarDado(6);
            sumaStock += dadosStock[x];
            cout << dadosStock[x];
            if (x < dadosJugador1-1)
            {
                cout << ",";
            }
        }

    }
    else
    {
        cout << dadosJugador2 << ": [ ";
        for (x=0; x<dadosJugador2; x++)
        {
            dadosStock[x] = tirarDado(6);
            sumaStock += dadosStock[x];
            cout << dadosStock[x];
            if (x < dadosJugador2-1)
            {
                cout << " , ";
            }
        }
    }
    cout << "]" << endl;

    if(sumaStock<resultadoObjetivo)
    {
        cout << "No se puede llegar al numero objetivo, turno perdido" << endl;
    }
    else
    {
        sumaStock=0;
        cout << "Seleccionar dados: ";
        while(resultadoObjetivo > sumaStock)
        {

            cin >> seleccion;
            while (dadosStock[seleccion-1]==0)
            {
                cout << "Dado incorrecto, por favor seleccionar otro: ";
                cin >> seleccion;
            }
            dadosStockElegidos[contadorStock] = dadosStock[seleccion-1];
            dadosStock[seleccion-1] = 0;
            sumaStock += dadosStockElegidos[contadorStock];
            contadorStock++;
        }

        for (x=0; x<contadorStock; x++)
        {
            cout << dadosStockElegidos[x];
            if (x< contadorStock-1)
            {
                cout << " + ";
            }
        }
        if (resultadoObjetivo < sumaStock)
        {
            cout << " = " << sumaStock << endl;
            cout << "El numero sumado es mayor al objetivo";
            sumaStock=0;
        }
        else
        {
            cout << " = " << sumaStock;
        }

        cout << endl << "Puntos: 12 x 3 = 36" << endl;
        cout << "Transfiere 3 dados a Maria" << endl;
        cout << jugador1 << "3 dados restantes, 36 pts" << endl;
        cout << jugador2 << "9 dados (recibio 3)" << endl;
    }
}

int tirarDado(int caras)
{
    return rand() % caras + 1;
}

bool quienEmpieza(bool turno)
{
    int j1,j2;
    do
    {
        j1 = tirarDado(6);
        j2 = tirarDado(6);
        // cout << j1 << "   " << j2 << endl;
    }
    while(j1 == j2);
    //system("pause");
    if (j1 > j2)
    {
        return true;
    }
    else
    {
        return false;
    }



}
