#pragma once
class MainGame
{
public:
	MainGame();
	~MainGame();
};

#ifndef MAINGAME_H
#define MAINGAME_H

#include "Display.h"

enum class GameState { PLAY, EXIT };

class MainGame
{
public:
	MainGame();
	~MainGame();

	void Run();
private:
	void Init();
	void ProcessInput();
	void GameLoop();
	void Draw();

	Display m_gameDispplay;
	GameState m_state;
};

#endif