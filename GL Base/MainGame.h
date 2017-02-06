#ifndef MAINGAME_H
#define MAINGAME_H

#include "Display.h"
#include "Mesh.h"
#include "Shader.h"

enum class GameState { PLAY, EXIT };

class MainGame
{
public:
	MainGame(const char* gameName);
	~MainGame();

	void Run();

private:
	void Init();
	void ProcessInput();
	void GameLoop();
	void Draw();

	Display m_gameDisplay;
	GameState m_state;

	const char* m_gameName;
};

#endif