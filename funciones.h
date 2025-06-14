#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
using namespace std;

void menu(int puntajeEstadistica[],string jugadorEstadistica[]);
void jugar();
void mostrarEstadisticas(int puntajeEstadistica[],string jugadorEstadistica[]);
void mostrarCreditos();
void seleccionarNombres(string &jugador1,string &jugador2);
int tirarDado(int caras);
void interfazJuego(bool &sinDados,string jugador1, string jugador2, int numeroDeRonda, int &dadosJugador1, int &dadosJugador2, int &puntajeJugador1, int &puntajeJugador2,bool turno);
bool quienEmpieza(bool turno);
void tiradaExitosa(bool &sinDados,bool turno, int sumaStock, int dadosUsados, int &puntajeJugador1, int &puntajeJugador2, int &dadosJugador1, int &dadosJugador2, string jugador1, string jugador2);
void tiradaNoExitosa(int sumaStock, bool turno, int &dadosJugador1, int &dadosJugador2, string jugador1, string jugador2);
void jugadorGanador(bool turno,string jugador1,string jugador2,int puntajeJugador1,int puntajeJugador2,string &ganador,int &puntajeGanador);
void ordenarEstadistica(string ganador,int puntajeGanador,string jugadorEstadistica[],int puntajeEstadistica[]);

#endif // FUNCIONES_H_INCLUDED
