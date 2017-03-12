#include "MainGame.h"

int main(int argc, char** argv)
{
	MainGame game("Gl Base test");
	game.Init();

	game.CreateModel("Suit");
	//game.GetModel(0).LoadModelFromFile("res/models/NanoSuit/nanosuit.obj");
	game.GetModel(0).LoadModelFromFile("res/models/cabin.obj");
	game.GetModel("Suit").SetShader("res/shaders/shader");

	game.Run();

	return 0;
}