#include "MainGame.h"

MainGame::MainGame(const char* gameName)
{
	m_gameName = gameName;

	m_state = GameState::PLAY;
	m_gameDisplay = Display();
	m_scene = std::vector<Model*>();
}

MainGame::~MainGame()
{
	for (auto model : m_scene)
	{
		if (model != nullptr)
			delete model;
	}
}

void MainGame::Run()
{
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
	m_gameDisplay.ClearDisplay();

	for (auto model : m_scene)
	{
		model->Draw();
	}

	// old code for testing only 
	glEnableClientState(GL_COLOR_ARRAY);
	glEnd();

	// SWAP BUFFER HERE
	m_gameDisplay.SwapBuffer();
}

void MainGame::CreateModel(std::string name)
{
	m_scene.push_back(new Model(name));
	//setup model in here??
}

Model & MainGame::GetModel(std::string name)
{
	for (auto model : m_scene)
	{
		if (model->GetName() == name)
		{
			return *model;
		}
	}
}

Model & MainGame::GetModel(int i)
{
	if (i < m_scene.size())
	{
		return *m_scene[i];
	}
}
