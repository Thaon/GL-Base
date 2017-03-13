#include "MainGame.h"

int main(int argc, char** argv)
{
	MainGame game("Gl Base test");
	game.Init();

	game.CreateModel("Suit");
	game.GetModel(0).LoadModelFromFile("res/models/NS2/nanosuit2.3ds");
	game.GetModel("Suit").SetShader("res/shaders/shader");

	game.Run();

	return 0;
}