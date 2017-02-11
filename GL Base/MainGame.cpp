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
	Input::Init();
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

		Input::Update(event);

		float speed = .1f;
		//move
		if (Input::GetKeyDown(SDLK_w))
		{
			for (auto model : m_scene)
			{
				model->Move(glm::vec3(0, speed, 0));
			}
		}
		if (Input::GetKeyDown(SDLK_s))
		{
			for (auto model : m_scene)
			{
				model->Move(glm::vec3(0, -speed, 0));
			}
		}
		if (Input::GetKeyDown(SDLK_a))
		{
			for (auto model : m_scene)
			{
				model->Move(glm::vec3(-speed, 0, 0));
			}
		}
		if (Input::GetKeyDown(SDLK_d))
		{
			for (auto model : m_scene)
			{
				model->Move(glm::vec3(speed, 0, 0));
			}
		}
		if (Input::GetKeyDown(SDLK_q))
		{
			for (auto model : m_scene)
			{
				model->Move(glm::vec3(0, 0, speed));
			}
		}
		if (Input::GetKeyDown(SDLK_e))
		{
			for (auto model : m_scene)
			{
				model->Move(glm::vec3(0, 0, -speed));
			}
		}

			//rotate
		if (Input::GetKeyDown(SDLK_j))
		{
			for (auto model : m_scene)
			{
				model->Rotate(-1);
			}
		}
		if (Input::GetKeyDown(SDLK_l))
		{
			for (auto model : m_scene)
			{
				model->Rotate(1);
			}
		}

			//scale
		if (Input::GetKeyDown(SDLK_i))
		{
			for (auto model : m_scene)
			{
				model->Scale(1+speed);
			}
		}
		if (Input::GetKeyDown(SDLK_k))
		{
			for (auto model : m_scene)
			{
				model->Scale(1-speed);
			}
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
