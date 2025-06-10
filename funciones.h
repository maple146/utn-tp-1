#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
using namespace std;

void menu();
void jugar();
void mostrarEstadisticas();
void mostrarCreditos();
void seleccionarNombres(string &jugador1,string &jugador2);
int tirarDado(int caras);
void interfazJuego(string jugador1, string jugador2, int numeroDeRonda, int dadosJugador1, int dadosJugador2, int puntajeJugador1, int puntajeJugador2,bool turno);
bool quienEmpieza(bool turno);
void tiradaExitosa(bool turno, int sumaStock, int dadosUsados, int puntajeJugador1, int puntajeJugador2, int dadosJugador1, int dadosJugador2, string jugador1, string jugador2);
void tiradaNoExitosa(bool turno, int dadosJugador1, int dadosJugador2, string jugador1, string jugador2);

#endif // FUNCIONES_H_INCLUDED
