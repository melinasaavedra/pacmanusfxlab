 <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "GameObject.h"
#include "Texture.h"


class Fantasma : public GameObject{
private:
	//Velocidad en eje X y Y
	int velocidadX;
	int velocidadY;
	//Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;#pragma once
#include <SDL.h>
#include
	int posicionXDestino;
	int posicionYDestino;
	int incrementoPosicionX;
	int incrementoPosicionY;
	//int numeroAnimacion;
	int movimientos;

	int imagenFantasma;
	//animacion
	int tipo;
	int numeroFrame;
	int contadorFrames;
	const int fremeMovimientos =4;
public:
	Texture* fantasmaTexture;
	//Constructores y destructores
	//Fantasma(SDL_Renderer* _renderer, SDL_Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	Fantasma(Texture*_fantasmaTexture, int _posicionX, int _posicionY, 
		int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	//~Fantasma();
	
	//Metodos accesores

	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }
	int getMovimientos() { return movimientos; }
	int getNumeroFrame() { return numeroFrame; }
	int getContadorFrames() { return contadorFrames; }
	


	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	void setMovimientos(int _movimientos) { movimientos = _movimientos; }
	void setNumeroFrame(int _numeroFrame) { numeroFrame = _numeroFrame; }
	void setContadorFrames(int _contadorFrames) { contadorFrames = _contadorFrames; }
	// Metodos varios
		
	// Manejador de eventos del fantasma
	//void handleEvent(SDL_Event& e);
	
	// Mover fantasma
	void move();
	// Renderizar imagen fantasma
	//void render() override;
	//actualizar datos fantasma
	void update() override;
};