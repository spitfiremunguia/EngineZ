#pragma once
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include "Sprite.h"
using namespace std;

using namespace std;

enum class GameState
{
	PLAY,
	EXIT
};


class MainGame
{
public:
	MainGame();
	~MainGame();
	void Run();
private:
	void InitSystems();
	SDL_Window *_window;
	int _screenWidth;
	int _screenHight;
	void ProcessInput();
	void GameLoop();
	void DrawGame();
	GameState _GameState;
	Sprite _sprite;

};

