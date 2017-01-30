#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>

class Display
{
public:
	Display();
	~Display();

	void InitDisplay();
	void SwapBuffers();

private:
	void ReturnError(std::string errorString);

	SDL_Window* m_window; //holds pointer to out window
	int m_screenWidth;
	int m_screenHeight;


};

#endif