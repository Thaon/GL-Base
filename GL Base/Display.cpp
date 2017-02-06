#include "Display.h"


Display::Display()
{
	m_window = nullptr;
	m_screenWidth = 800;
	m_screenHeight = 600;
}

Display::~Display()
{
	SDL_GL_DeleteContext(m_context);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Display::ReturnError(std::string errorString)
{
	std::cout << errorString << std::endl;
	system("PAUSE");
	SDL_Quit();
}

void Display::SwapBuffer()
{
	SDL_GL_SwapWindow(m_window);
}

void Display::InitDisplay(const char* title)
{
	//init SDL
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	m_window = SDL_CreateWindow(title ,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_screenWidth, m_screenHeight, SDL_WINDOW_OPENGL);
	m_context = SDL_GL_CreateContext(m_window);

	//init glew
	GLenum error = glewInit();
	if (m_window == nullptr)
		ReturnError("Window failed to be created");
	if (m_context == nullptr)
		ReturnError("GL context could not be created");
	if (error != GLEW_OK)
		ReturnError("Glew could not be initialised");

	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
}

void Display::ClearDisplay()
{
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
