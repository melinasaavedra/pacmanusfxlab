#include "Fantasma.h"
#include <iostream>

using namespace std;

Fantasma::Fantasma(Texture* _fantasmaTexture, int _posicionX, int _posicionY,
	int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) :
	GameObject(_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla,_fantasmaTexture,posicionXTextura,posicionYTextura)
{
	// Inicializa propiedade de de pacman
	velocidadX = 3;
	velocidadY = 3;
	//imagens
	numeroFrame = 0;
	contadorFrames = 0;
	//texture
	velocidadPatron = _velocidadPatron;
	fantasmaTexture = _fantasmaTexture;
	//movimientos
	movimientos = rand() % 3;
	/*imagenFantasma = rand() % fantasmaTexture.size();*/
	//tipo = _tipo;

}

void Fantasma::move()
{
	//si es x==0 va hacia arriba y abajo
	if (movimientos == 0) {
		// Mover el fantasma a la izquierda o derecha
		posicionX += velocidadX;
		// Verificar si la posicion del fantasma no salio de los bordes izquierdo o derecho
		if ((posicionX < 0) || (posicionX + ancho > anchoPantalla))
		{
			// Mover fantasma atras
			
			posicionX -= velocidadX;
			velocidadX *= -1;
			if (posicionX >= anchoPantalla - 30) {
				movimientos = rand() % 3;
			}
			if (posicionX < 20) {
				movimientos = rand() % 3;
			}
		}

	}
	// Mover el fantasma arriba o abajo
	if (movimientos == 1) {
		posicionY += velocidadY;

		// Verificar si la posicion del fantasma no salio de los bordes superior e inferior
		if ((posicionY < 0) || (posicionY + alto > altoPantalla))
		{
			// Mover fantasma atras
			posicionY -= velocidadY;
			velocidadY *= -1;
			if (posicionX >= altoPantalla - 30) {
				movimientos = rand() % 3;
			}
			if (posicionY < 20) {
				movimientos = rand() % 3;
			}
		}
	}
	if (movimientos == 2) {

		movimientos = rand() % 3;
		// Mover el fantasma a la izquierda o derecha
		posicionX += velocidadX;
		// Verificar si la posicion del fantasma no salio de los bordes izquierdo o derecho
		if ((posicionX < 0) || (posicionX + ancho > anchoPantalla))
		{
			// Mover fantasma atras

			posicionX -= velocidadX;
			velocidadX *= -1;
		}
		
		posicionY += velocidadY;
		if ((posicionY < 0) || (posicionY + alto > altoPantalla))
		{
			// Mover fantasma atras
			posicionY -= velocidadY;
			velocidadY *= -1;
		
		}
		
	}
}

//void Fantasma::render()
//{	
//		
//		SDL_Rect renderQuad = {  25*numeroFrame, 25, ancho, alto };
//		//Render to screen
//		fantasmaTexture[imagenFantasma]->render(posicionX, posicionY, &renderQuad);
//		//SDL_RenderCopyEx(renderer, fantasmaTexture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
//}

void Fantasma::update()
{
	contadorFrames++;
	numeroFrame = contadorFrames / 8;
	if (numeroFrame > fremeMovimientos - 1) {
		numeroFrame = 0;
		contadorFrames = 0;
	}
}
