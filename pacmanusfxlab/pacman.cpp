
#include <stdio.h>
#include "Pacman.h"

Pacman::Pacman()
{
	posicionX = 100;
	posicionY = 100;
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = 5;
	ancho = 20;
	alto = 20;
	anchoPantalla = 640;
	altoPantalla = 480;
}
Pacman::Pacman(int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla)
{
	posicionX = _posicionX;
	posicionY = _posicionY;
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = 5;
	ancho = 20;
	alto = 20;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
}
Pacman::Pacman(int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla, int _velocidadPatron, SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _pacmanTexture)
{
	posicionX = _posicionX;
	posicionY = _posicionY;
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	ancho = 25;
	alto = 25;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	window = _window;
	renderer = _renderer;
	screenSurface = _screenSurface;
	pacmanTexture = _pacmanTexture;
}

void Pacman::handleEvent(SDL_Event& e)
{
	//SI SE HA PRECIONADO UNA TECLA
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//SE AJUSTA LA VELOCIDAD
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velocidadY -= velocidadPatron; break;
		case SDLK_DOWN: velocidadY += velocidadPatron; break;
		case SDLK_LEFT: velocidadX -= velocidadPatron; break;
		case SDLK_RIGHT: velocidadX += velocidadPatron; break;
		}
	}
	//SI SE A SOLTADO UNA TECLA
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//SE AJUSTA LA VELOCIDAD
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velocidadY += velocidadPatron; break;
		case SDLK_DOWN: velocidadY -= velocidadPatron; break;
		case SDLK_LEFT: velocidadX += velocidadPatron; break;
		case SDLK_RIGHT: velocidadX -= velocidadPatron; break;
		}
	}
	//move();
}

void Pacman::move()
{
	//SE MUEVE EL PACMAN A LA IZQUIERDA O DERECHA
	posicionX += velocidadX;

	//SE VERIFIVA QUE NO SOBREPASE LA PANTALLA DE LOS BORDES horizontales
	if ((posicionX < 0) || (posicionX + ancho > anchoPantalla))
	{
		//Move back
		posicionX -= velocidadX;
	}

	//se mueve el pacman arriba o abajo
	posicionY += velocidadY;

	//se verifica que no se pase lo bordes verticales
	if ((posicionY < 0) || (posicionY + alto > altoPantalla))
	{
		//mover atras
		posicionY -= velocidadY;
	}
}

void Pacman::render()
{
	SDL_Texture* newTexture = NULL;
	SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };
	SDL_RenderCopyEx(renderer, pacmanTexture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
}