#include "stdafx.h"
#include "Graficos.h"
#include "GestorAtmosferico.h"

// Definicion de variables globales
int posicionJugador;
int posicionBala;
int posicionJosico;
int estadoJosico; // 1-> moviendo hacia izquiera, 2 -> moviendo hacia derecha, 0-> muerto
int estadoBala; // 1-> bala izquierda, 2 -> bala derecha, 0-> no hay bala
int estadoJuego;
char caracterActual;
char climaActual;


// Declaracion de funciones
void actualizarEstados(); // Funcion de actualizacion de estados
void init(); // Funcion de inicilizacion de estados


int main()
{
	init(); // Llamada a inicializacion

	// Bucle de juego
	while (1)
	{
		system("cls"); // Limpiar consola
		actualizarEstados();
		dibujar(posicionJugador, posicionBala, posicionJosico, estadoBala, estadoJosico, estadoJuego, crearClima);
		// Calcula de espera para cumplir FPS deseados
		Sleep(1000 / FPS);
	}
	return 0;
}


void actualizarEstados()
{
	// Comprobacion de entrada 
	if (_kbhit())
	{
		// Obtencion del caracter pulsado
		caracterActual = _getch();

		// Movimiento del jugador
		if (!estadoJuego && caracterActual == 'r') init();
		else if (posicionJugador < ANCHO && caracterActual == 'p') posicionJugador++;
		else if (posicionJugador > 1 && caracterActual == 'o') posicionJugador--;

		// Comprobacion de disparo del jugador
		else if (!estadoBala && caracterActual == 'q')
		{
			estadoBala = 1;
			posicionBala = posicionJugador;
		}
		else if (!estadoBala && caracterActual == 'w')
		{
			estadoBala = 2;
			posicionBala = posicionJugador;
		}
	}

	// Actualizacion si hay bala en pantalla: colision con enemigo y movimiento
	if (posicionJosico == posicionBala + 1 || posicionJosico == posicionBala - 1 || posicionJosico == posicionBala)
	{
		estadoJosico = 0;
		estadoBala = 0;
	}
	else if (posicionBala > ANCHO || posicionBala < 1) estadoBala = 0;
	else if (estadoBala == 1) posicionBala--;
	else if (estadoBala == 2) posicionBala++;

	// Actualizacion de enemigo: colision con jugador y movimiento
	if (!estadoJosico)
	{
		estadoJosico = (rand() % 2 ? 1 : 2);
		posicionJosico = (estadoJosico > 1 ? 1 : ANCHO);
	}
	else if (posicionJugador == posicionJosico + 1 || posicionJugador == posicionJosico + 1 || posicionJugador == posicionJosico) estadoJuego = 0;
	else if (estadoJosico == 1) posicionJosico--;
	else if (estadoJosico == 2) posicionJosico++;

}

void init()
{
	posicionJugador = ANCHO / 2;
	estadoBala = 0;
	estadoJosico = 0;
	estadoJuego = 1;
}


