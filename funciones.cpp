#include <iostream>
#include "funciones.h"

using namespace std;


void menu(int puntajeEstadistica[],string jugadorEstadistica[])
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
            mostrarEstadisticas(puntajeEstadistica,jugadorEstadistica);
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
    while (option != 0 || confirm=='N');
}

void jugar()
{
    system("cls");
    cout << "Seleccionado jugar" << endl;
    cout << "Presione cualquier tecla para volver al menu..." << endl;
    system("pause>nul");
}

void mostrarEstadisticas(int puntajeEstadistica[],string jugadorEstadistica[])
{
    system("cls");
    cout << "============================================================" << endl;
    cout << "                       Enfrendados" << endl;
    cout << "============================================================" << endl;
    cout << "MEJOR PUNTUACION" << endl;
    for (int x=0; x<5; x++)
    {
        cout << jugadorEstadistica[x] << " ----- " << puntajeEstadistica[x] << endl;
    }
    cout << "Presione cualquier tecla para volver al menu..." << endl;
    system("pause>nul");
}

void mostrarCreditos()
{
    system("cls");
    cout << "============================================================" << endl;
    cout << "                       Enfrendados" << endl;
    cout << "============================================================" << endl;
    cout << "PARTICIPANTES EN LA CREACION DE ENFRENDADOS " << endl << endl;
    cout << "Grupo 22" << endl;
    cout << "Luciano Alcaraz - Legajo: 23944" << endl;
    cout << "Tomas Zoria - Legajo: 29944" << endl << endl;
    cout << "Presione cualquier tecla para volver al menu..." << endl;
    system("pause>nul");
}
void seleccionarNombres(string &jugador1, string &jugador2)
{
    system("cls");

    cout << "============================================================" << endl;
    cout << "                       Enfrendados" << endl;
    cout << "============================================================" << endl << endl;


    cin.ignore();

    do
    {
        cout << "Ingresar nombre de Jugador 1: ";
        getline(cin, jugador1);
        if (jugador1.empty())
        {
            cout << "Nombre invalido. Ingrese un nombre valido para el Jugador 1." << endl;
        }
    }
    while (jugador1.empty());

    do
    {
        cout << "Ingresar nombre de Jugador 2: ";
        getline(cin, jugador2);
        if (jugador2.empty())
        {
            cout << "Nombre invalido. Ingrese un nombre valido para el Jugador 2." << endl;
        }
    }
    while (jugador2.empty());

}

void interfazJuego(bool &sinDados,string jugador1, string jugador2, int numeroDeRonda, int &dadosJugador1, int &dadosJugador2, int &puntajeJugador1, int &puntajeJugador2,bool turno)
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
    cout << "                       Enfrendados " << endl;
    cout << "============================================================" << endl << endl;

    cout << "RONDA: " << numeroDeRonda << endl << endl;
    cout << "Turno de: ";
    if (turno == true)
    {
        cout << jugador1;
        cout << " \t\t\t\t\t Dados objetivo (d12):" << dadosObjetivo[0] << " + " << dadosObjetivo[1] << " = " << resultadoObjetivo << endl;
        cout << "Puntos actuales: " << puntajeJugador1;
        cout << " \t\t\t\t\t Puntaje " << jugador2 << ": " << puntajeJugador2 << " - " << " dados en stock: " << dadosJugador2;
    }
    else
    {
        cout << jugador2;
        cout << " \t\t\t\t\t Dados objetivo (d12):" << dadosObjetivo[0] << " + " << dadosObjetivo[1] << " = " << resultadoObjetivo << endl;
        cout << "Puntos actuales: " << puntajeJugador2;
        cout << " \t\t\t\t\t Puntaje " << jugador1 << ": " << puntajeJugador1 << " - " << " dados en stock: " << dadosJugador1;
    }
    cout << endl << endl;
    if (turno==true)

    {
        cout << "Numero de dados" << ": \t {";
        for (x=0; x<dadosJugador1; x++)
        {
            cout << x+1;
            if (x < dadosJugador1-1)
            {
                cout << ",";
            }
        }
        cout << "}" << endl;
        cout << "\t\t" << "  \t  ";
        for (x=0; x<dadosJugador1; x++)
        {
            cout << "|";
            if (x < dadosJugador1-1)
            {
                cout << " ";
            }
        }
        cout << endl;

        cout << "Stock actual ";
        cout << dadosJugador1 << ": \t [";
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
        cout << "]" << endl;
    }
    else
    {
        cout << "Numero de dados" << ": \t {";
        for (x=0; x<dadosJugador2; x++)
        {
            cout << x+1;
            if (x < dadosJugador2-1)
            {
                cout << ",";
            }
        }
        cout << "}" << endl;
        cout << "\t\t" << "  \t  ";
        for (x=0; x<dadosJugador2; x++)
        {
            cout << "|";
            if (x < dadosJugador2-1)
            {
                cout << " ";
            }
        }
        cout << endl;

        cout << "Stock actual ";
        cout << dadosJugador2 << ": \t [";
        for (x=0; x<dadosJugador2; x++)
        {
            dadosStock[x] = tirarDado(6);
            sumaStock += dadosStock[x];
            cout << dadosStock[x];
            if (x < dadosJugador2-1)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }



    if(sumaStock<resultadoObjetivo)
    {
        cout << "No se puede llegar al numero objetivo, turno perdido" << endl;
    }
    else
    {
        sumaStock=0;
        cout << "Seleccionar dados: ";
        seleccion=1;
        while(resultadoObjetivo > sumaStock)
        {
            cin >> seleccion;
            if (seleccion==0)
            {
                cout << "El jugador decidio pasar el turno" << endl;
                break;
            }
            else
            {
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
        }

        system("cls");

        cout << "============================================================" << endl;
        cout << "                       Enfrendados " << endl;
        cout << "============================================================" << endl << endl;

        cout << "Dados objetivo: " << resultadoObjetivo << endl;
        cout << "Suma de dados elegidos: ";

        // Suma los dados elegidos y los imprime
        for (x=0; x<contadorStock; x++)
        {
            cout << dadosStockElegidos[x];
            if (x < contadorStock-1)
            {
                cout << " + ";
            }
        }


        // Checkea si la suma de dados elegidos es mayor o igual al objetivo
        if (sumaStock == resultadoObjetivo)
        {
            tiradaExitosa(sinDados,turno, sumaStock, contadorStock,
                          puntajeJugador1, puntajeJugador2,
                          dadosJugador1, dadosJugador2,
                          jugador1, jugador2);
        }
        else
        {
            tiradaNoExitosa(resultadoObjetivo,puntajeJugador1,puntajeJugador2,seleccion,sumaStock, turno, dadosJugador1, dadosJugador2, jugador1, jugador2);
        }
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
    }
    while(j1 == j2);
    
    if (j1 > j2)
    {
        cout << "Jugador 1 empieza" << endl;
        return true;
    }
    else
    {
        cout << "Jugador 2 empieza" << endl;
        return false;
    }
}

void tiradaExitosa(bool &sinDados, bool turno, int sumaStock, int dadosUsados, int &puntajeJugador1, int &puntajeJugador2, int &dadosJugador1, int &dadosJugador2, string jugador1, string jugador2)
{
    int puntosGanados = sumaStock * dadosUsados;
    if(sumaStock!=0)
    {
        cout << " = " << sumaStock << endl;
    }
    cout << endl << "Puntos ganados: " << dadosUsados << " x " << sumaStock << " = " << puntosGanados << endl;
    cout << endl;


    if (turno == true)
    {
        puntajeJugador1 += puntosGanados;

        dadosJugador1 -= dadosUsados;
        dadosJugador2 += dadosUsados;
        if (dadosJugador1 == 0)
        {
            sinDados=!sinDados;
            puntajeJugador1 += 10000;
        }
        else
        {
            cout << jugador1 << " transfiere " << dadosUsados << " dados a " << jugador2 << endl;

            cout << endl << "============================================================" << endl << endl;
            cout << jugador1 << " tiene en stock " << dadosJugador1 << " dados, sumo: " << puntosGanados << " pts" << endl;
            cout << "Puntaje actual de " << jugador1 << ": " << puntajeJugador1 << endl << endl;
            cout << jugador2 << " recibio " << dadosUsados << " dados, acumula en total " << dadosJugador2 << " dados en stock" << endl;
            cout << "Puntaje actual de " << jugador2 << ": " << puntajeJugador2 << endl << endl;

        }
    }
    else
    {
        puntajeJugador2 += puntosGanados;

        dadosJugador2 -= dadosUsados;
        dadosJugador1 += dadosUsados;
        if (dadosJugador2 == 0)
        {
            sinDados=!sinDados;
            puntajeJugador2 += 10000;
        }

        else
        {
            cout << jugador2 << " transfiere " << dadosUsados << " dados a " << jugador1 << endl;

            cout << endl << "============================================================" << endl << endl;
            cout << jugador2 << " tiene en stock " << dadosJugador2 << " dados, sumo: " << puntosGanados << " pts" << endl;
            cout << "Puntaje actual de " << jugador2 << ": " << puntajeJugador2 << endl << endl;
            cout << jugador1 << " recibio " << dadosUsados << " dados, acumula en total " << dadosJugador1 << " dados en stock" << endl;
            cout << "Puntaje actual de " << jugador1 << ": " << puntajeJugador1 << endl << endl;
        }

    }
}

void tiradaNoExitosa(int resultadoObjetivo,int puntajeJugador1, int puntajeJugador2,int seleccion,int sumaStock, bool turno, int &dadosJugador1, int &dadosJugador2, string jugador1, string jugador2)
{
    if(sumaStock!=0)
    {
        cout << " = " << sumaStock << endl;
        cout << " resultado objetivo: " << resultadoObjetivo << endl << endl;
    }
    if (turno && dadosJugador2 > 1)
    {
        dadosJugador1++;
        dadosJugador2--;

        if(seleccion==0)
        {
            cout << jugador1 << " decidio pasar el turno, recibe un dado de " << jugador2 << endl;
        }
        else
        {
            cout << jugador1 << " no tuvo buena tirada, recibe un dado de " << jugador2 << endl;
        }
        cout << endl << "============================================================" << endl << endl;
        cout << "Dados de " << jugador1 << ": " << dadosJugador1 << endl;
        cout << "Puntaje actual de " << jugador1 << ": " << puntajeJugador1 << endl << endl;
        cout << "Dados de " << jugador2 << ": " << dadosJugador2 << endl;
        cout << "Puntaje actual de " << jugador2 << ": " << puntajeJugador2 << endl << endl;
    }
    else if (!turno && dadosJugador1 > 1)
    {
        dadosJugador2++;
        dadosJugador1--;

        if(seleccion==0)
        {
            cout << jugador2 << " decidio pasar el turno" << endl;
        }
        else
        {
            cout << jugador2 << " no tuvo buena tirada, recibe un dado de " << jugador1 << endl;
        }

        cout << endl << "============================================================" << endl << endl;
        cout << "Dados de " << jugador2 << ": " << dadosJugador2 << endl;
        cout << "Puntaje actual de " << jugador2 << ": " << puntajeJugador2 << endl << endl;
        cout << "Dados de " << jugador1 << ": " << dadosJugador1 << endl;
        cout << "Puntaje actual de " << jugador1 << ": " << puntajeJugador1 << endl << endl;
    }
}

void jugadorGanador(bool sinDados,bool turno,string jugador1,string jugador2,int puntajeJugador1,int puntajeJugador2,string &ganador,int &puntajeGanador)
{
    if (puntajeJugador1>puntajeJugador2)
    {
        ganador=jugador1;
        puntajeGanador=puntajeJugador1;
    }
    else
    {
        ganador=jugador2;
        puntajeGanador=puntajeJugador2;
    }
    system("cls");
    cout << "============================================================" << endl;
    cout << "                       Enfrendados " << endl;
    cout << "============================================================" << endl << endl;

    if (sinDados)
    {
        cout << ganador << " se quedo sin dados, "<< ganador << " gano el juego con un puntaje de: " << puntajeGanador << " ¡felicitaciones!" << endl;
    }
    else
    {
        cout << "El ganador fue " << ganador << " con un total de " << puntajeGanador << " ¡felicitaciones!" << endl;
    }

}

void ordenarEstadistica(string ganador,int puntajeGanador,string jugadorEstadistica[],int puntajeEstadistica[])
{
    int x,i,aux,posMin;
    string auxiliar;

    for (x=0; x<5; x++)
    {
        if (puntajeEstadistica[x]==0)
        {
            jugadorEstadistica[x]=ganador;
            puntajeEstadistica[x]=puntajeGanador;
            break;
        }
    }

    for (x=0; x<4; x++)
    {
        posMin=x;
        for (i=x+1; i<5; i++)
        {
            if (puntajeEstadistica[i]>puntajeEstadistica[posMin])
            {
                posMin=i;
            }
        }
        aux=puntajeEstadistica[x];
        puntajeEstadistica[x]=puntajeEstadistica[posMin];
        puntajeEstadistica[posMin]=aux;

        auxiliar=jugadorEstadistica[x];
        jugadorEstadistica[x]=jugadorEstadistica[posMin];
        jugadorEstadistica[posMin]=auxiliar;
    }

}
