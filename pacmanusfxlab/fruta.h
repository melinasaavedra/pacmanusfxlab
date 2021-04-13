#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>


#include <SDL.h>
#include <SDL_image.h>
using namespace std;
//enum TIPO_FRUTA {
//	TIPO_FRUTA_GUINDA,
//	TIPO_FRUTA_FRUTILLA,
//	TIPO_FRUTA_NARANJA,
//	TIPO_FRUTA_PLATANO,
//	TIPO_FRUTA_MANZANA
//};
class Fruta {
private:
	int posicionX;
	int posicionY;

	int ancho;
	int alto;

	int anchoPantalla;
	int altoPantalla;
	int imagen;
	bool visible;
	int tiempoVisible;
	int tiempoNoVisible;

	int contadorTiempoVisible;
	int contadorTiempoNoVisible;


public:
	// Ventana en la que se realizara el tratamiento grafico de renderizacion
	SDL_Window* window = nullptr;

	// Renderizador de la ventana
	SDL_Renderer* renderer = nullptr;

	// La superficie grafica (surface) que contiene la ventana
	SDL_Surface* screenSurface = nullptr;

	// Supeerficie grafica del fantasma;
	//SDL_Surface* frutaSurface = nullptr;
	SDL_Texture* frutaTexture = nullptr;
public:
	//Constructores y destructores
	Fruta();
	Fruta(int _posicionX, int _posicionY, int _imagen);
	Fruta(int _posicionX, int _posicionY, int _imagen, SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _frutaTexture);
	//~Fantasma();
	//Metodos accesores
	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getAnchoPantalla() { return anchoPantalla; }
	int getAltoPantalla() { return altoPantalla; }
	bool getVisible() { return visible; }
	int getTiempoVisible() { return tiempoVisible; }
	int getTiempoNoVisible() { return tiempoNoVisible; }
	int getImagen() { return imagen; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }

	void setVisible(bool _visible) { visible = _visible; }
	void setTiempoVisble(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }
	void setTiempoNoVisble(int _tiempoNoVisible) { tiempoNoVisible = _tiempoNoVisible; }
	void serImagen(int _imagen) { imagen = _imagen; }
	// Metodos varios
	// Manejador de eventos del fantasma
	//void handleEvent(SDL_Event& e);
// Mostrar u ocultar fruta
	void mostrar();
	// Renderizar imagen fruta
	void render(SDL_Texture* Textura);
};
