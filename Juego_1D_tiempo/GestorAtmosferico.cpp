#include "stdafx.h"
#include "GestorAtmosferico.h"

#define LLUVIA '`'
#define VIENTO '~'
#define DESPEJADO '-'
#define CD_CLIMA 600

//Declaracion de variables globales
int cdClimaActual = 0;
int nuevoClima;
char climas[3] = { LLUVIA, VIENTO, DESPEJADO };


char crearClima()
{
	if (!cdClimaActual)
	{
		// Randomizamos el numero de variable
		nuevoClima = 0 + (rand() % (int)(((sizeof(climas) / sizeof(climas[0])) - 1) - 0 + 1));
		cdClimaActual = CD_CLIMA;
	}
	else cdClimaActual--;
	return climas[nuevoClima];
}