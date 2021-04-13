#pragma once
#include <SDL.h>

class Fantasma {
private:
	// posicion actual en la pantalla
	int posicionX;
	int posicionY;

	//Velocidad en eje X
	int velocidadX;

	//Velocidad en el eje Y
	int velocidadY;

	//Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

	int ancho;
	int alto;

	int anchoPantalla;
	int altoPantalla;
	int tipoFantasma;
	int x;
public:
	// Ventana en la que se realizara el tratamiento grafico de renderizacion
	SDL_Window* window = nullptr;

	// Renderizador de la ventana
	SDL_Renderer* renderer = nullptr;

	// La superficie grafica (surface) que contiene la ventana
	SDL_Surface* screenSurface = nullptr;

	// Supeerficie grafica del fantasma;
	//SDL_Surface* fantasmaSurface = nullptr;
	SDL_Texture* fantasmaTexture = nullptr;

public:
	//Constructores y destructores
	Fantasma();
	//~Fantasma();
	Fantasma(int _posicionX, int _posicionY, int _tipoFantasma, int _x);
	Fantasma(int _posicionX, int _posicionY, int _tipoFantasma, int _x, SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _fantasmaTexture);
	//Metodos accesores

	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getAnchoPantalla() { return anchoPantalla; }
	int getAltoPantalla() { return altoPantalla; }
	int getTipoFantasma() { return tipoFantasma; }
	int getX() { return x; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }
	void setTipoFantasma(int _tipoFantasma) { tipoFantasma = _tipoFantasma; }
	void setX(int _x) { x = _x; }
	// Metodos varios

	// Manejador de eventos del fantasma
	//void handleEvent(SDL_Event& e);

	// Mover fantasma
	void move();
	// Renderizar imagen fantasma
	void render(SDL_Texture* Textura);

}; 
