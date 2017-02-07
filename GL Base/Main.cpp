#include "MainGame.h"

int main(int argc, char** argv)
{
	MainGame game("Gl Base test");
	game.Init();

	Vertex vertices[] = {
		Vertex(glm::vec3(-.5f, -.5f, 0)),
		Vertex(glm::vec3(0, .5f, 0)),
		Vertex(glm::vec3(.5f, -.5f, 0))
	};

	game.CreateModel("Triangle");
	game.GetModel(0).SetMeshData(vertices, sizeof(vertices) / sizeof(vertices[0]));
	game.GetModel("Triangle").SetShader("res/shaders/shader");

	game.Run();

	return 0;
}