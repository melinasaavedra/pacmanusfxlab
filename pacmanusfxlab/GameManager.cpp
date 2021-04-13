#include "GameManager.h"

using namespace std;

GameManager::GameManager() {
	gWindow = nullptr;
	gRenderer = nullptr;
	gScreenSurface = nullptr;
	gPacmanTexture = nullptr;
	//gFantasmaTexture[] = nullptr;
	for (int i = 0; i <= 4; i++)
	{
		gFantasmaTexture[i] = nullptr;
	}
	//textura de la fruta
	for (int i = 0; i <= 4; i++)
	{
		gFrutaTexture[i] = nullptr;
	}
	juego_en_ejecucion = true;
	//fruta posicion
	for (int i = 0; i <= 4; i++)
	{
		int t = 1 + rand() % (6 - 1);
		int x = 100 + rand() % (600 - 100);
		int y = 100 + rand() % (400 - 100);
		fruta[i] = new Fruta(x, y, t);
	}
	//posicion de los fantasmas
	for (int i = 0; i <= 4; i++)
	{
		int w = rand() % 2;
		int t = 1 + rand() % (6 - 1);
		int x = 100 + i * 40;
		int y = 100 + i * 20;
		fantasma[i] = new Fantasma(x, y, t, w);
	}
}

int GameManager::onExecute() {
	if (onInit() == false) {
		return -1;
	}
	pacman = new Pacman(ancho / 2, alto / 2, ancho, alto, 5, gWindow, gRenderer, gScreenSurface, gPacmanTexture);
	//fantasma = new Fantasma(gWindow, gRenderer, gScreenSurface, gFantasmaTexture);
	//posicion de fantasmas;
	for (int i = 0; i <= 4; i++)
	{
		srand(time(NULL));
		int w = rand() % 2;
		int t = 1 + rand() % (6 - 1);
		int x = 100 + i * 80;
		int y = 100 + i * 80;
		fantasma[i] = new Fantasma(x, y, t, w, gWindow, gRenderer, gScreenSurface, gFrutaTexture[i]);
	}
	//declaracion de frutas
	for (int i = 0; i <= 4; i++)
	{
		srand(time(NULL));
		int t = 1 + rand() % (6 - 1);
		int x = 100 + rand() % (600 - 100);
		int y = 100 + rand() % (400 - 100);
		fruta[i] = new Fruta(x, y, t, gWindow, gRenderer, gScreenSurface, gFrutaTexture[i]);
	}

	SDL_Event Event;

	while (juego_en_ejecucion) {
		while (SDL_PollEvent(&Event)) {
			onEvent(&Event);
			pacman->handleEvent(Event);

		}
		// Mover Pacman
		pacman->move();
		// Mover Fantasma
		//fantasma->move();
		for (int i = 0; i <= 4; i++)
		{
			fantasma[i]->move();
		}
		//Mostrar y ocultar fruta
		for (int i = 0; i <= 4; i++)
		{
			fruta[i]->mostrar();
		}

		//Limpiar pantalla
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);
		//Actualizar pantalla
		onLoop();
		onRender();
		SDL_RenderPresent(gRenderer);
	}
	onCleanup();
	return 0;
}

bool GameManager::imagenesFruta()
{
	bool success = true;
	for (int i = 0; i <= 4; i++)
	{
		switch (fruta[i]->getImagen())
		{
		case 1:
			gFrutaTexture[i] = loadTexture("Resources/fruta1.png");
			if (gFrutaTexture[i] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			break;
		case 2:
			gFrutaTexture[i] = loadTexture("Resources/fruta2.png");
			if (gFrutaTexture[i] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			break;
		case 3:
			gFrutaTexture[i] = loadTexture("Resources/fruta3.png");
			if (gFrutaTexture[i] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			break;
		case 4:
			gFrutaTexture[i] = loadTexture("Resources/fruta4.png");
			if (gFrutaTexture[i] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			break;
		case 5:
			gFrutaTexture[i] = loadTexture("Resources/Orange.png");
			if (gFrutaTexture[i] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			break;
		}
	}
	return success;
}

bool GameManager::onInit() {
	//Inicializar flag
	bool success = true;

	//Inicializar SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Crear ventana
		gWindow = SDL_CreateWindow("Pacman USFX", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ancho, alto, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{

			//Crear renderizador vsynced para la ventana
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				//Inicializar color de renderizado
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
			//Conseguir superficie de ventana
			gScreenSurface = SDL_GetWindowSurface(gWindow);
			//Cargar texturas a las superficies de los objetos
			gPacmanTexture = loadTexture("Resources/PacMan_01.bmp");
			if (gPacmanTexture == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			/*gFantasmaTexture = loadTexture("Resources/Fantasma.bmp");
			if (gFantasmaTexture == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}*/
			gFantasmaTexture[0] = loadTexture("Resources/fa1.png");
			if (gFantasmaTexture[0] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			gFantasmaTexture[1] = loadTexture("Resources/fa2.png");
			if (gFantasmaTexture[1] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			gFantasmaTexture[2] = loadTexture("Resources/fa3.png");
			if (gFantasmaTexture[2] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			gFantasmaTexture[3] = loadTexture("Resources/Fantasma3.bmp");
			if (gFantasmaTexture[3] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			gFantasmaTexture[4] = loadTexture("Resources/Fantasma4.bmp");
			if (gFantasmaTexture[4] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			imagenesFruta();
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
	pacman->render();
	//fantasma->render();
	for (int i = 0; i <= 4; i++)
	{
		fantasma[i]->render(gFantasmaTexture[i]);
	}
	for (int i = 0; i <= 4; i++)
	{
		fruta[i]->render(gFrutaTexture[i]);
	}
	imagenesFruta();
};

void GameManager::onCleanup() {
	SDL_FreeSurface(gScreenSurface);
	SDL_Quit();
};

SDL_Texture* GameManager::loadTexture(string path)
{
	// Textura final generada
	SDL_Texture* newTexture = nullptr;

	// Carga una imagen de una ruta especifica
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		cout << "No se pudo cargarla imagen, SDL_image Error: " << IMG_GetError() << endl;
	}
	else
	{
		// Crea una textura a partir de una superficie de pixeles
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			cout << "No se pudo crear la textura, SDL Error: " << SDL_GetError() << endl;
		}

		// Libera la superficie cargada
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}