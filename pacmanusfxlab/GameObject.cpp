#include "GameObject.h"

int GameObject::numeroObjetosCreados = 0;

GameObject::GameObject(int _posicionX, int _posicionY,
	int _ancho, int _alto, int _anchoPantalla,
	int _altoPantalla, Texture* _texturas, int _posicionXTextura, int _posicionYTextura) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = _ancho;
	alto = _alto;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	visible = true;
	numeroObjetosCreados++;
	idObjeto = numeroObjetosCreados;
	texturas = _texturas;
	posicionXTextura = _posicionXTextura;
	posicionYTextura = _posicionYTextura;

}

void GameObject::renderObjetos() {

	if (visible) {
		SDL_Rect renderQuad = { posicionXTextura  , posicionYTextura, ancho, alto };
		//Render to screen
		texturas->render(posicionX, posicionY, &renderQuad);
	}
};

void GameObject::handleEvent(SDL_Event& e) {};

