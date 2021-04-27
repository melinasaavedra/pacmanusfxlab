#include "Fruta.h"
#include <iostream>

using namespace std;

Fruta::Fruta(Texture* _frutasTextures, int _posicionX, int _posicionY,
	int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) :
	GameObject(_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla, _frutasTextures, posicionXTextura, posicionYTextura){
	// Inicializa propiedade de la fruta

	visible = false;
	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
	int numeroFrutaVisible = 0;
	frutaTexture = _frutasTextures;
	//tipo = _tipo;
}


void Fruta::mostrar()
{
	if (contadorTiempoVisible >= tiempoVisible) {
		visible = false;
		if (contadorTiempoNoVisible >= tiempoNoVisible) {
			posicionX = 1 + rand() % anchoPantalla;
			posicionY = 1 + rand() % altoPantalla;
			contadorTiempoVisible = 0;
			contadorTiempoNoVisible = 0;
			visible = true;
			/*numeroFrutaVisible = rand() % frutaTexture.size();*/
			//numeroFrutaVisible = rand() % TIPO_FRUTA_MAXIMO;
		}
		else {
			contadorTiempoNoVisible++;
			//contadorTiempoNoVisible = contadorTiempoNoVisible + 1;
		}
	}
	else {
		contadorTiempoVisible++;
	}
}

//void Fruta::render()
//{
//	if (visible) {
//		
//
//		SDL_Rect clip = { 0, 0, ancho, alto };
//		frutaTexture[numeroFrutaVisible]->render(posicionX, posicionY, &clip);
//	}
//}