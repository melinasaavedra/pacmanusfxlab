#include "Fantasma.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
Fantasma::Fantasma() {
	posicionX = 100 + rand() % (600 - 100);
	posicionY = 100 + rand() % (400 - 100);
	velocidadX = 2;
	velocidadY = 2;
	velocidadPatron = 5;
	ancho = 50;
	alto = 50;
	anchoPantalla = 640;
	altoPantalla = 480;
	x = rand() % 2;
	tipoFantasma = 1;
}
Fantasma::Fantasma(int _posicionX, int _posicionY, int _tipoFantasma, int _x) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	velocidadX = 2;
	velocidadY = 2;
	velocidadPatron = 5;
	ancho = 20;
	alto = 20;
	anchoPantalla = 640;
	altoPantalla = 480;
	x = _x;
	tipoFantasma = _tipoFantasma;
}



Fantasma::Fantasma(int _posicionX, int _posicionY, int _tipoFantasma, int _x, SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _fantasmaTexture) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	velocidadX = 2;
	velocidadY = 2;
	velocidadPatron = 5;
	ancho = 20;
	alto = 20;
	anchoPantalla = 640;
	altoPantalla = 480;
	x = _x;
	tipoFantasma = _tipoFantasma;
	window = _window;
	renderer = _renderer;
	screenSurface = _screenSurface;
	fantasmaTexture = _fantasmaTexture;
}
void Fantasma::move()
{
	if (x == 0) {
		// Mover el fantasma a la izquierda o derecha
		posicionX += velocidadX;

		// Verificar si la posicion del fantasma no salio de los bordes izquierdo o derecho
		if ((posicionX < 0) || (posicionX + ancho > anchoPantalla))
		{
			// Mover fantasma atras
			posicionX -= velocidadX;
			velocidadX *= -1;
			if (posicionX >= anchoPantalla - 30) {
				x = rand() % 2;
			}
			if (posicionX < 20) {
				x = rand() % 2;
			}
		}

	}
	// Mover el fantasma arriba o abajo
	if (x == 1) {
		posicionY += velocidadY;

		// Verificar si la posicion del fantasma no salio de los bordes superior e inferior
		if ((posicionY < 0) || (posicionY + alto > altoPantalla))
		{
			// Mover fantasma atras
			posicionY -= velocidadY;
			velocidadY *= -1;
			if (posicionX >= altoPantalla - 30) {
				x = rand() % 2;
			}
			if (posicionY < 20) {
				x = rand() % 2;
			}

		}
	}
}
void Fantasma::render(SDL_Texture* Textura)
{
	SDL_Texture* nuevaTextura = NULL;
	SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };
	SDL_RenderCopyEx(renderer, Textura, nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
}