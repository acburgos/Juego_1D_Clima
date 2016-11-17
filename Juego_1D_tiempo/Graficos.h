#pragma once

// Caracteristicas pantalla
#define ANCHO 60
#define PRIMERA_LINEA  10
#define PRIMERA_COLUMNA 20
#define FPS 20

// Elementos Juego
#define PERSONAJE '*'
#define FONDO_PANTALLA '-'
#define BALA 'o'
#define JOSICO 'A'

//Declaracion de funciones

// Funcion que se encarga de representar todo a traves de la consola
void dibujar(int &posicionJugador, int &posicionBala, int &posicionJosico, int &estadoBala, int &estadoJosico, int &estadoJuego,char (*fuelegirClima)());
