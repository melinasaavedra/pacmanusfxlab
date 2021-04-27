#pragma once
#include <vector>
#include <SDL.h>

#include "GameObject.h"
#include "Texture.h"


using namespace std;

class Muros : public GameObject
{

private:
	

	int tiempoVisible;
	int tiempoNoVisible;

	int contadorTiempoVisible;
	int contadorTiempoNoVisible;
	int numeroFrutaVisible;
	int x;


public:
	Texture* MurosTextures;
public:
	//Constructores y destructores
	Muros(Texture* _MurosTextures, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
	
	int getTiempoVisible() { return tiempoVisible; }
	int getTiempoNoVisible() { return tiempoNoVisible; }
	void setTiempoVisble(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }
	void setTiempoNoVisble(int _tiempoNoVisible) { tiempoNoVisible = _tiempoNoVisible; }

	// Metodos varios

	// Manejador de eventos de la fruta
	//void handleEvent(SDL_Event& e);

	// Mostrar u ocultar fruta
	// Renderizar imagen fruta
	//void render();


};


