#include "Moneda.h"

Moneda::Moneda(Texture*_MonedasTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) :
	GameObject(_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla, _MonedasTexture, posicionXTextura, posicionYTextura)
{
	// Inicializa propiedade de de pacman
	valor = 1;
	//tipoPoderMoneda = PODER_MONEDA_NINGUNO;
	tiempoPoderMoneda = 0;
	/*renderer = _renderer;*/
	MonedasTexture = _MonedasTexture;
	
}



//void Moneda::render() {
//
//	SDL_Rect renderQuad = { 0, 0, ancho, alto };
//	//Render to screen
//	MonedasTexture[0]->render(posicionX, posicionY, &renderQuad);
//	//SDL_RenderCopyEx(renderer, fantasmaTexture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
//
//}
void Moneda::update() {

	contadorFrames++;
	numeroFrame = contadorFrames / 6;

	if (numeroFrame > fremeMovimientos - 1) {
		numeroFrame = 0;
		contadorFrames = 0;

	}

}
