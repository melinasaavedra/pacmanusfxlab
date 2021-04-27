#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>

#include "Pacman.h"
#include "Fantasma.h"
#include "Fruta.h"
#include "Moneda.h"
#include "Texture.h"
#include "Muros.h"
#include "MapGenerator.h"
using namespace std;


//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

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

    //vector<Texture*> PacmanTexture;
    //vector<Texture*> fantasmaTexture;
    ///*Texture* frutastexture = nullptr;*/
    //vector<Texture*> FrutaTexture;
    //vector<Texture*> MonedaTexture;
    //vector<Texture*> SuperMonedaTexture;
    //vector<Texture*> MurosTexture;
public:
    //Pacman* pacman;
    ////vector<Fantasma*> fantasma;
    //Fantasma* fantasma;
    //Fruta* fruta;
    //vector<Moneda*> monedas;
    //vector<Moneda*> superMonedas;
    vector<GameObject*> actoresJuego;
    /*Muros* muros;*/
    MapGenerator* generadorNivelJuego;

public:
    GameManager();
    int onExecute();
    
    bool onInit();
    void onEvent(SDL_Event* Event);
    void onLoop();
    void onRender();
    void onCleanup();
};

    