#include "stdafx.h"
#include "Graficos.h"



void dibujar(int &posicionJugador, int &posicionBala,int &posicionJosico, int &estadoBala, int &estadoJosico, int &estadoJuego, char(*pfnElegirClima)())
{
	//Colocamos la linea en el punto deseado de la pantalla
	for (int i = 0; i < PRIMERA_LINEA; i++) printf("\n");
	// Colocamos el inicio de la pantalla en la columna deseada
	for (int i = 0; i < PRIMERA_COLUMNA; i++) printf(" ");

	// Imprimimos por pantalla las posiciones de los elementos
	for (int i = 1; i < ANCHO + 1; i++)
	{
		if (!estadoJuego)
		{
			printf("GAME OVER. PRESS 'R' TO RESTART");
			break;
		}
		else if (i == posicionJugador) printf("%c", PERSONAJE);
		else if (i == posicionBala && estadoBala > 0) printf("%c", BALA);
		else if (i == posicionJosico && estadoJosico > 0) printf("%c", JOSICO);
		else printf("%c", pfnElegirClima());
	}
}