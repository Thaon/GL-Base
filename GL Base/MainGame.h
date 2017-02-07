#ifndef MAINGAME_H
#define MAINGAME_H

#include "Display.h"
#include "Model.h"
#include <vector>

enum class GameState { PLAY, EXIT };

class MainGame
{
public:
	MainGame(const char* gameName);
	~MainGame();

	void Init();
	
	void CreateModel(std::string name);
	Model& GetModel(std::string name);
	Model& GetModel(int i);

	void Run();

private:
	void ProcessInput();
	void GameLoop();
	void Draw();

	Display m_gameDisplay;
	GameState m_state;

	const char* m_gameName;

	std::vector<Model*> m_scene;
};

#endif