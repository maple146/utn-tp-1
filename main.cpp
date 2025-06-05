#include <iostream>
#include "funciones.h"
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "spanish");
    int option;
    string Player1,Player2;

    // Temporal, pruebas
    int numeroDeRonda = 1, dadoJugador1 = 6, dadoJugador2= 6, puntajeJugador1 = 5, puntajeJugador2 = 10;

    menu();
    // ACA EMPEZARIA EL JUEGO
    system("cls");

    seleccionarNombres(Player1,Player2);
    interfazJuego(Player1, Player2, numeroDeRonda, dadoJugador1, dadoJugador2, puntajeJugador1, puntajeJugador2);
    return 0;

}



