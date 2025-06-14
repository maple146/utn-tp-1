#include <iostream>
#include "funciones.h"
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "spanish");
    int puntajeGanador,puntajeEstadistica[5]={},option;
    string jugadorEstadistica[5],jugador1="Jugador 1",jugador2="Jugador 2",ganador;
    bool turno;

    menu();
    //seleccionarNombres(jugador1,jugador2);
    turno = quienEmpieza(turno);

    int numeroDeRonda = 1, dadosJugador1=6, dadosJugador2=6, puntajeJugador1 = 0, puntajeJugador2 = 0,contadorRonda=0;
    bool sinDados=false;

    while (numeroDeRonda < 4)
    {
        // ACA EMPEZARIA EL JUEGO
        system("cls");

        interfazJuego(sinDados,jugador1, jugador2, numeroDeRonda, dadosJugador1, dadosJugador2, puntajeJugador1, puntajeJugador2,turno);

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
        jugadorGanador(turno,jugador1,jugador2,puntajeJugador1,puntajeJugador2,ganador,puntajeGanador);
        ordenarEstadistica(ganador,puntajeGanador,jugadorEstadistica,puntajeEstadistica);
        system("pause");

    }

    return 0;

}



