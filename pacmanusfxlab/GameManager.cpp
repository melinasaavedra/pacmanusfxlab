#include "GameManager.h"

using namespace std;
GameManager::GameManager() {
	gWindow = nullptr;
	gRenderer = nullptr;
	gScreenSurface = nullptr;
	juego_en_ejecucion = true;
}

int GameManager::onExecute() {
	if (onInit() == false) {
		return -1;
	}
	//// llamandao a pacman
	//actoresJuego.push_back(new Pacman(PacmanTexture, SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2, 25, 25, SCREEN_WIDTH, SCREEN_HEIGHT, 5,0,0));
	///*cout << pacman->getIdObjeto() << endl;*/
	////funcion fantasma
	//for (int i = 0; i <= 3; i++) {
	//	actoresJuego.push_back(new Fantasma(fantasmaTexture, 100, 50+(i*50), 25, 25, SCREEN_WIDTH, SCREEN_HEIGHT, 5,0));
	//}
	//
	////funcion fruta
	//for (int i = 0; i <= 4; i++) {
	//	actoresJuego.push_back(new Fruta(FrutaTexture, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 25, 25, SCREEN_WIDTH, SCREEN_HEIGHT,0));
	//}
	////funcion moneda
	//int posx = 0;
	//for (int i = 0; i < 10; i++)
	//{
	//	posx = i * 50;
	//	actoresJuego.push_back(new Moneda(MonedaTexture, posx, 100, 50, 50, SCREEN_WIDTH, SCREEN_HEIGHT));
	//}
	//// funcion supermoneda
	//for (int i = 0; i < 4; i++)
	//{
	//	actoresJuego.push_back(new Moneda(SuperMonedaTexture, 50 + (i * 50), 50 + (i * 50), 50, 50, SCREEN_WIDTH, SCREEN_HEIGHT));
	//}
	////funcion muros;
	//for (int i = 0; i < 10; i++)
	//{	
	//	actoresJuego.push_back(new Muros(MurosTexture, i*50, i*50, 25, 25, SCREEN_WIDTH, SCREEN_HEIGHT));
	//}
	//comprobando los actores
	/*for (int i = 0; i < actoresJuego.size(); i++) {
		cout << actoresJuego[i]->getIdObjeto() << endl;
	}*/

	srand(time(NULL));

	generadorNivelJuego = new MapGenerator(SCREEN_WIDTH, SCREEN_HEIGHT);
	generadorNivelJuego->load("Resources/mapa.txt");
	generadorNivelJuego->populate(actoresJuego);


	SDL_Event Event;

	while (juego_en_ejecucion) {
		while (SDL_PollEvent(&Event)) {
			onEvent(&Event);
			for (int i = 0; i < actoresJuego.size(); i++) {
				actoresJuego[i]->handleEvent(Event);
			}
		}
		//// Mover Pacman//movimiento
		/*pacman->move();*/

		//// Mover Fantasma
		//fantasma->move();
		//
		//fruta->mostrar();

		for (int i = 0; i < actoresJuego.size(); i++) {
			actoresJuego[i]->move();
		}
		for (int i = 0; i < actoresJuego.size(); i++) {
			actoresJuego[i]->mostrar();
		}
		////Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(gRenderer);

		//Update screen
		onLoop();
		onRender();
		SDL_RenderPresent(gRenderer);
	}

	onCleanup();

	return 0;
}

bool GameManager::onInit() {
	//Initialization flag
	bool success = true;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("Pacman USFX", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				//Initialize renderer colort
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}

			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
			//cambiando textura
			Texture::renderer = gRenderer;
			//	//imagens pacman
			//	PacmanTexture.push_back(new Texture());
			//	PacmanTexture[0]->loadFromImage("Resources/PacMan.bmp");

			///*	PacmanTexture = new Texture();
			//	PacmanTexture->loadFromImage("Resources/PacMan.bmp");*/
			//	//Imagenes fantasmas
			//	fantasmaTexture.push_back(new Texture());
			//	fantasmaTexture[0]->loadFromImage("Resources/Inkey.bmp");
			//	fantasmaTexture.push_back(new Texture());
			//	fantasmaTexture[1]->loadFromImage("Resources/Clyde.bmp");
			//	fantasmaTexture.push_back(new Texture());
			//	fantasmaTexture[2]->loadFromImage("Resources/Blinky.bmp");
			///*	fantasmaTexture = new Texture();k
			//	fantasmaTexture->loadFromImage("Resources/Blinky.bmp");
			//	/*gFantasmaTexture = loadTexture("Resources/Fantasma.bmp");
			//	if (gFantasmaTexture == NULL)
			//	{	cout << "Fallo en la carga de la textura aqui" << endl;
			//		success = false;}*/

			//	//imagenes de frutas
			//	//gFrutasTextures.push_back(loadTexture("Resources/Fruta04.png"));
			//	FrutaTexture.push_back(new Texture());
			//	FrutaTexture[0]->loadFromImage("Resources/Fruta01.bmp");
			//	FrutaTexture.push_back(new Texture());
			//	FrutaTexture[1]->loadFromImage("Resources/fruta01.png");
			//	FrutaTexture.push_back(new Texture());
			//	FrutaTexture[2]->loadFromImage("Resources/fruta02.png");
			//	FrutaTexture.push_back(new Texture());
			//	FrutaTexture[3]->loadFromImage("Resources/fruta03.png");
			//	FrutaTexture.push_back(new Texture());
			//	FrutaTexture[4]->loadFromImage("Resources/fruta04.png");

			//	MonedaTexture.push_back(new Texture());
			//	MonedaTexture[0]->loadFromImage("Resources/mo1.jpg");
			//	//MonedaTexture = new Texture();
			//	//MonedaTexture->loadFromImage("Resources/mo1.jpg"); 
			//	SuperMonedaTexture.push_back(new Texture());
			//	SuperMonedaTexture[0]->loadFromImage("Resources/fruta04.png");
			//	//SuperMonedaTexture = new Texture();
			//	//SuperMonedaTexture->loadFromImage("Resources/point2.bmp");
			//	////imagens de muros
			//	MurosTexture.push_back(new Texture());
			//	MurosTexture[0]->loadFromImage("Resources/point.bmp");
			//	 
			//	//MurosTexture = new Texture();
				//MurosTexture->loadFromImage("Resources/point.bmp");
		}
	}

	return success;
};

void GameManager::onEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		juego_en_ejecucion = false;
	}
};
void GameManager::onLoop() {};
void GameManager::onRender() {
	for (int i = 0; i < actoresJuego.size(); i++) {
		actoresJuego[i]->renderObjetos();
	}
	/*pacman->update();*/
	for (int i = 0; i < actoresJuego.size(); i++) {
		actoresJuego[i]->update();
	}
};
void GameManager::onCleanup() {
	SDL_FreeSurface(gScreenSurface);

	SDL_Quit();
};
