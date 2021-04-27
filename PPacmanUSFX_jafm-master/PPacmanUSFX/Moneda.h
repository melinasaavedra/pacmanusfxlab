#pragma once
#include <SDL.h>
#include <vector>
#include "GameObject.h"
#include "Texture.h"

//enum PODER_MONEDA {
//    PODER_MONEDA_NINGUNO,
//    PODER_MONEDA_CRECIMIENTO,
//    PODER_MONEDA_COMER,
//    PODER_MONEDA_VELOCIDAD,
//    PODER_MONEDA_SALTO
//};


class Moneda :
    public GameObject
{
private:
    int valor;
   /* PODER_MONEDA tipoPoderMoneda;*/
    int tiempoPoderMoneda;


    int numeroFrame;
    int contadorFrames;
    const int fremeMovimientos = 10;
    int tiempo;
public:
    //// Renderizador de la ventana
    //SDL_Renderer* renderer = nullptr;

    //// Textura de la grafica del fantasma
    //SDL_Texture* monedaTexture = nullptr;
    Texture* MonedasTexture;


public:
    Moneda(Texture* MonedasTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
    

    int getValor() { return valor; }
    int getTiempoPoderMoneda() { return tiempoPoderMoneda; }
    void setValor(int _valor) { valor = _valor; }
    void setTiempoPoderMoneda(int _tiempoPoderMoneda) { tiempoPoderMoneda = _tiempoPoderMoneda; }

  /*  void render();*/
    void update()  override;
};

