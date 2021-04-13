#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>
#include <SDL_image.h>

#include "Pacman.h"
#include "Fantasma.h"
#include "Fruta.h"

using namespace std;

class GameManager
{
private:
    bool juego_en_ejecucion;

    //The window we'll be rendering to
    SDL_Window* gWindow;

    //The window renderer
    SDL_Renderer* gRenderer;

    //The surface contained by the window
    SDL_Surface* gScreenSurface;

    //The images we will load and show on the screen
    //SDL_Surface* gPacManSurface;
    SDL_Texture* gPacmanTexture;
    //SDL_Surface* gFantasmaSurface;
    SDL_Texture* gFantasmaTexture[5];
    // SDL_Surface* gFrutaSurface;
    SDL_Texture* gFrutaTexture[5];

public:
    //Dimensiones de la pantalla
    int ancho = 640;
    int alto = 480;

    //punteros
    Pacman* pacman;
    Fantasma* fantasma[5];
    Fruta* fruta[5];

public:
    //procesos
    GameManager();


    int onExecute();
    bool onInit();
    void onEvent(SDL_Event* Event);
    void onLoop();
    bool imagenesFruta();
    void onRender();
    void onCleanup();
    //textura
    SDL_Texture* loadTexture(string path);

};

