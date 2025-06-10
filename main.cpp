#include <iostream>
#include "funciones.h"
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "spanish");
    int option;
    string jugador1="Jugador 1",jugador2="Jugador 2";
    bool turno=true;

    // Temporal, pruebas
    int numeroDeRonda = 1, dadosJugador1 = 6, dadosJugador2= 6, puntajeJugador1 = 0, puntajeJugador2 = 0;

    menu();
    // ACA EMPEZARIA EL JUEGO
    system("cls");

    //seleccionarNombres(jugador1,jugador2);
    turno = quienEmpieza(turno);

    interfazJuego(jugador1, jugador2, numeroDeRonda, dadosJugador1, dadosJugador2, puntajeJugador1, puntajeJugador2,turno);
    return 0;

}



