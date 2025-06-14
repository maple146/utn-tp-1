#include <iostream>
#include "funciones.h"
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "spanish");
    int option,numeroDeRonda = 1, dadosJugador1=6, dadosJugador2=6, puntajeJugador1 = 0, puntajeJugador2 = 0,contadorRonda=0;
    string jugador1="Jugador 1",jugador2="Jugador 2";
    bool turno=true,sinDados=false;

    menu();
    // seleccionarNombres(jugador1,jugador2);
    turno = quienEmpieza(turno);

    while (numeroDeRonda < 4)
    {
        // ACA EMPEZARIA EL JUEGO
        system("cls");

        interfazJuego(sinDados,jugador1, jugador2, numeroDeRonda, dadosJugador1, dadosJugador2, puntajeJugador1, puntajeJugador2,turno);

        cout << "DEBUG- Jugador 1: " << dadosJugador1 << " dados, " << puntajeJugador1 << " pts" << endl;
        cout << "DEBUG- Jugador 2: " << dadosJugador2 << " dados, " << puntajeJugador2 << " pts" << endl;
        cout << "----------------------------" << endl;

        contadorRonda++;
        if (contadorRonda %2 == 0)
        {
            numeroDeRonda++;
        }
        turno=!turno;
        cout << sinDados;
        if (sinDados == true)
        {
            break;
        }
        system("pause");

    }

    return 0;

}



