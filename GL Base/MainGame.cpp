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
	m_gameDisplay.ClearDisplay();

	Vertex vertices[] = {
		Vertex(glm::vec3(-.5f, -.5f, 0)),
		Vertex(glm::vec3(0, .5f, 0)),
		Vertex(glm::vec3(.5f, -.5f, 0))
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("res/shaders/shader");
	shader.Bind();
	mesh.Draw();

	// old code for testing only 
	glEnableClientState(GL_COLOR_ARRAY);
	glEnd();

	// SWAP BUFFER HERE
	m_gameDisplay.SwapBuffer();
}
