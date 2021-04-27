#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>

#include "GameObject.h"
#include "Texture.h"

using namespace std;

class Fruta : public GameObject
{
private:
	/*TIPO_FRUTA tipoFruta;*/

	int tiempoVisible;
	int tiempoNoVisible;

	int contadorTiempoVisible;
	int contadorTiempoNoVisible;
	int numeroFrutaVisible;
	int x;

	int tipo;

public:
	//// Renderizador de la ventana
	//SDL_Renderer* renderer = nullptr;

	//// Array de las texturas de las diferentes frutas;
	//vector<SDL_Texture*> frutasTextures;

	Texture* frutaTexture;
public:
	//Constructores y destructores
	Fruta(Texture* frutaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
	//~Fruta();

	//Metodos accesores


	int getTiempoVisible() { return tiempoVisible; }
	int getTiempoNoVisible() { return tiempoNoVisible; }

	void setTiempoVisble(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }
	void setTiempoNoVisble(int _tiempoNoVisible) { tiempoNoVisible = _tiempoNoVisible; }

	// Metodos varios

	// Manejador de eventos de la fruta
	//void handleEvent(SDL_Event& e);

	// Mostrar u ocultar fruta
	void mostrar();
	// Renderizar imagen fruta
	//void render();

};
