#include "MainGame.h"

int main(int argc, char** argv)
{
	MainGame game("Gl Base test");
	game.Init();

	game.CreateModel("Teapot");
	game.GetModel(0).LoadModelFromFile("res/models/teapot.fbx");
	game.GetModel("Teapot").SetShader("res/shaders/shader");

	game.Run();

	return 0;
}