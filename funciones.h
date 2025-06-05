#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
using namespace std;

void menu();
void jugar();
void mostrarEstadisticas();
void mostrarCreditos();
void seleccionarNombres(string &Player1,string &Player2);
int tirarDado(int caras);
void interfazJuego(string Player1, string Player2, int numeroDeRonda, int dadoJugador1, int dadoJugador2, int puntajeJugador1, int puntajeJugador2 );

#endif // FUNCIONES_H_INCLUDED
