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
    while (option != 0);
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
    for (int x=0;x<5;x++){
        cout << jugadorEstadistica[x] << " ----- " << puntajeEstadistica[x] << endl;
    }
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
    system("cls");

    cout << "============================================================" << endl;
    cout << "                       Enfrendados" << endl;
    cout << "============================================================" << endl << endl;


    cin.ignore();


    cout << "Ingresar nombre de Jugador 1: ";

    getline(cin, jugador1);

    cout << "Ingresar nombre de Jugador 2: ";

    getline(cin, jugador2);
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
        cout << jugador1 << endl;
    }
    else
    {
        cout << jugador2 << endl;
    }
    cout << "Puntos actuales:" ;
    if (turno == true)
    {
        cout << puntajeJugador1 << endl;
    }
    else
    {
        cout << puntajeJugador2 << endl;
    }
    cout << "                                    Dados objetivo (d12):" << dadosObjetivo[0] << " + " << dadosObjetivo[1] << " = " << resultadoObjetivo << endl;
    cout << endl;
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
        cout << dadosJugador2 << ": [";
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
             cout << endl;
        cout << "######Calculo de los resultados######" << endl;

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
            tiradaNoExitosa(sumaStock, turno, dadosJugador1, dadosJugador2, jugador1, jugador2);
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
        // cout << j1 << "   " << j2 << endl;
    }
    while(j1 == j2);
    //system("pause");
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
    cout << endl << "Puntos ganados: " << dadosUsados << " x " << sumaStock << " = " << puntosGanados << endl;
    cout << endl;
    // turno true = jugador1, turno false = false
    if (turno == true)
    {
        puntajeJugador1 += puntosGanados;

        dadosJugador1 -= dadosUsados;
        dadosJugador2 += dadosUsados;
        if (dadosJugador1 == 0)
        {
            sinDados=!sinDados;
            puntajeJugador1 += 10000;
            // TODO: Aca deberia terminar el juego, depende de la logica de "Condicion de victoria"
        }
        else
        {
            cout << jugador1 << " transfiere " << dadosUsados << " dados a " << jugador2 << endl;

            cout << endl << "######Estado actual######" << endl;
            cout << jugador1 << " " << dadosJugador1 << " dados restantes, " << puntajeJugador1 << " pts" << endl;
            cout << jugador2 << " " << dadosJugador2 << " dados (recibio " << dadosUsados << ")" << endl;

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
            // TODO: Aca deberia terminar el juego, depende de la logica de "Condicion de victoria"
        }

        else{
        cout << jugador2 << " transfiere " << dadosUsados << " dados a " << jugador1 << endl;

        cout << endl << "######Estado actual######" << endl;
        cout << jugador2 << " " << dadosJugador2 << " dados restantes, " << puntajeJugador2 << " pts" << endl;
        cout << jugador1 << " " << dadosJugador1 << " dados (recibio " << dadosUsados << ")" << endl;
        }

    }
}

void tiradaNoExitosa(int sumaStock, bool turno, int &dadosJugador1, int &dadosJugador2, string jugador1, string jugador2)
{
    // TODO: Cambiar tipo de la variable turno?
    cout << " = " << sumaStock << endl;
    cout << endl;
    if (turno && dadosJugador2 > 1)
    {
        dadosJugador1++;
        dadosJugador2--;
        // TODO: Checkear porque no corta la linea antes

        cout << jugador1 << " no tuvo buena tirada, recibe un dado de " << jugador2 << endl;

        cout << endl << "######Estado actual######" << endl;
        cout << "Dados de " << jugador1 << ": " << dadosJugador1 << endl;
        cout << "Dados de " << jugador2 << ": " << dadosJugador2 << endl;
    }
    else if (!turno && dadosJugador1 > 1)
    {
        dadosJugador2++;
        dadosJugador1--;
        // TODO: Checkear porque no corta la linea antes
        cout << jugador2 << " no tuvo buena tirada, recibe un dado de " << jugador1 << endl;

        cout << endl << "######Estado actual######" << endl;
        cout << "Dados de " << jugador1 << ": " << dadosJugador1 << endl;
        cout << "Dados de " << jugador2 << ": " << dadosJugador2 << endl;
    }
    else
    {
        // TODO: Revisar que deberia pasar aca..
    }
}
void jugadorGanador(bool turno,string jugador1,string jugador2,int puntajeJugador1,int puntajeJugador2,string &ganador,int &puntajeGanador)
{
    if (turno==true)
    {
        ganador=jugador1;
        puntajeGanador=puntajeJugador1;
    }
    else
    {
        ganador=jugador2;
        puntajeGanador=puntajeJugador2;
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
