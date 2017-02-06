#include "MainGame.h"

MainGame::MainGame(const char* gameName)
{
	m_gameName = gameName;

	m_state = GameState::PLAY;
	m_gameDisplay = Display();
}

MainGame::~MainGame()
{
}

void MainGame::Run()
{
	Init();
	GameLoop();
}

void MainGame::Init()
{
	m_gameDisplay.InitDisplay(m_gameName);
}

void MainGame::GameLoop()
{
	while (m_state != GameState::EXIT)
	{
		ProcessInput();
		Draw();
	}
}

void MainGame::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) 
	{
		switch (event.type)
		{
			case SDL_QUIT:
				m_state = GameState::EXIT;
			break;
		}
	}
}

void MainGame::Draw()
{
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// old code for testing only 
	glEnableClientState(GL_COLOR_ARRAY);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0, 0);
	glVertex2f(0, 500);
	glVertex2f(500, 500);
	glEnd();

	// SWAP BUFFER HERE
	m_gameDisplay.SwapBuffer();
}
