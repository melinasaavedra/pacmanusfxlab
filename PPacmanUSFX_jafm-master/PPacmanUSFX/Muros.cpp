#include "Muros.h"
#include <iostream>
#include <atlalloc.h>

using namespace std;

Muros::Muros(Texture* _MurosTextures, int _posicionX, int _posicionY,
	int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) :
	GameObject(_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla, _MurosTextures, posicionXTextura, posicionYTextura)
{
	// Inicializa propiedade de la fruta

	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
	MurosTextures = _MurosTextures;

}

//void Muros::render()
//{
//		SDL_Rect clip = { 0, 0, ancho, alto };
//		MurosTextures[0]->render(posicionX, posicionY, &clip);
//}
