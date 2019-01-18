#include "MainGame.h"



void FatalError(string errorString)
{
	std::cout << errorString << std::endl;
	SDL_Quit();
}
MainGame::MainGame()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHight = 768;
	_GameState = GameState::PLAY;
}


MainGame::~MainGame()
{
}

void MainGame::Run()
{
	InitSystems();
	GameLoop();
}

void MainGame::InitSystems()
{
	//INITIALIZE SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	//CREATE WINDOW
	_window=SDL_CreateWindow("EngineZ",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
		_screenWidth,_screenHight,SDL_WINDOW_OPENGL);
	if (_window == nullptr) 
	{
		FatalError("SDL window could not be created");
	}
	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr) 
	{
		FatalError("SDL gl context could not be created");
	}
	GLenum glerror=glewInit();
	if (glerror !=GLEW_OK ) 
	{
		FatalError("Could not initialize glew");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
	glClearColor(0.0f, 0.5f, 0.5f,1);
	
}

void MainGame::ProcessInput()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) 
	{
		switch (evnt.type) 
		{
			case SDL_QUIT:
				_GameState = GameState::EXIT;
				break; 
			case SDL_MOUSEMOTION:
				std::cout <<"Y: " <<evnt.motion.y<<" X: "<<evnt.motion.x<<"\n" ;
				break;
		}
	}

}

void MainGame::GameLoop()
{
	while (_GameState != GameState::EXIT) 
	{
		ProcessInput();
		_sprite.Init(-1.0f,-1.0f,1.0f,1.0f);
		DrawGame();
	}
	
}

void MainGame::DrawGame()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	/*
	glEnableClientState(GL_COLOR_ARRAY);
	glBegin(GL_TRIANGLES);
	glColor3f(0,0,0);
	glVertex2f(-1, -1);
	glVertex2f(0,-1);
	glVertex2f(0, 0);
	glEnd();
	*/
	_sprite.Draw();

	SDL_GL_SwapWindow(_window);

}
