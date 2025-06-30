#include <iostream>
#include "funciones.h"
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "spanish");
    int puntajeGanador,puntajeEstadistica[5]= {},option;
    string jugadorEstadistica[5],jugador1="Jugador 1",jugador2="Jugador 2",ganador;
    bool turno;

    while(option!=0)
    {
        menu(puntajeEstadistica,jugadorEstadistica);
        seleccionarNombres(jugador1,jugador2);
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

            if (sinDados == true)
            {
                if (turno==true)
                {
                    cout << jugador1 << " se quedo sin dados" << endl;
                    cout << jugador1 << " gano el juego." << endl;
                }
                else
                {
                    cout << jugador2 << " se quedo sin dados" << endl;
                    cout << jugador2 << " gano el juego." << endl;
                }
                system("pause");
                break;
            }
            turno=!turno;

            system("pause");

        }
        if(puntajeJugador1==puntajeJugador2)
        {
            system("cls");
            cout << "============================================================" << endl;
            cout << "                       Enfrendados " << endl;
            cout << "============================================================" << endl << endl;
            cout << "Juego empatado, no hay ganador" << endl;
        }
        else
        {
            jugadorGanador(sinDados,turno,jugador1,jugador2,puntajeJugador1,puntajeJugador2,ganador,puntajeGanador);
            ordenarEstadistica(ganador,puntajeGanador,jugadorEstadistica,puntajeEstadistica);
        }
        system("pause");
    }
    return 0;

}



