
#include "Fruta.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

Fruta::Fruta()
{
	posicionX = 100;
	posicionY = 100;
	ancho = 20;
	alto = 20;
	anchoPantalla = 640;
	altoPantalla = 480;
	visible = false;
	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
	imagen = 1;
}

Fruta::Fruta(int _posicionX, int _posicionY, int _imagen) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = 20;
	alto = 20;
	anchoPantalla = 640;
	altoPantalla = 480;
	visible = false;
	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
	imagen = _imagen;
}

Fruta::Fruta(int _posicionX, int _posicionY, int _imagen, SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _frutaTexture)
{
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = 20;
	alto = 20;
	anchoPantalla = 640;
	altoPantalla = 480;
	visible = false;
	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
	imagen = _imagen;
	window = _window;
	renderer = _renderer;
	screenSurface = _screenSurface;
	frutaTexture = _frutaTexture;
};

void Fruta::mostrar()
{
	if (contadorTiempoVisible >= tiempoVisible) {
		visible = false;
		if (contadorTiempoNoVisible >= tiempoNoVisible) {
			posicionX = 100 + rand() % (600 - 100);
			posicionY = 100 + rand() % (400 - 100);
			imagen = 1 + rand() % (6 - 1);
			contadorTiempoVisible = 0;
			contadorTiempoNoVisible = 0;
			visible = true;

		}
		else {
			contadorTiempoNoVisible++;
		}
	}
	else {
		contadorTiempoVisible++;
	}
};

void Fruta::render(SDL_Texture* Textura)
{
	if (visible) {
		SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };
		SDL_RenderCopyEx(renderer, Textura, nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
	}
}