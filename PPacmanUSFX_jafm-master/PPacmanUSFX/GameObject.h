
	int posicionXTextura;
	int posicionYTextura;

	
#pragma once
#include <SDL.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>

#include "Texture.h"

using namespace std;

class GameObject
{
public:
	string nombre;
protected:
	// Posicion en el eje X y Y
	int idObjeto;
	int posicionX;
	int posicionY;
	
	// Ancho y Alto de la imagen del objeto en pixeles
	int ancho;
	int alto;

	// Ancho y alto de la pantalla del juego
	int anchoPantalla;
	int altoPantalla;

	// Si el objeto es visible
	bool visible;
	int tipo;


public:
	static int numeroObjetosCreados;
	Texture*texturas;
public:
	//Constructores y destructores
	GameObject(int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla,
		int _altoPantalla, Texture* _texturas,int _posicionXtextura=0,int _posicionYTextura=0);

	//Metodos accesores
	int getIdObjeto() { return idObjeto; }
	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getAnchoPantalla() { return anchoPantalla; }
	int getAltoPantalla() { return altoPantalla; }
	bool getVisible() { return visible; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }
	void setVisible(bool _visible) { visible = _visible; }

	// Metodos varios

	// Renderizar imagen
	
	virtual void renderObjetos();
	virtual void handleEvent(SDL_Event& e);
	virtual void move() {};
	virtual void update() {/*no se hace nada xd*/};
	virtual void mostrar() {};
};

