#include "Input.h"

//remember to initialise static members!!!
float Input::m_mouseX = 0;
float Input::m_mouseY = 0;
bool Input::m_keys[323];
bool Input::m_leftMouse = false;
bool Input::m_rightMouse = false;
bool Input::m_keys_untriggeredPress[323];

void Input::Init()
{
	m_mouseX = 0;
	m_mouseY = 0;

	for (int i = 0; i < 323; i++)
	{
		m_keys[i] = false;
	}
}

void Input::Update(SDL_Event& event)
{
	m_mouseX = 0;
	m_mouseY = 0;
	m_rightMouse = false;
	m_leftMouse = false;

	//While we still have events in the queue
	if (event.type == SDL_KEYUP)
	{
		if (event.key.keysym.sym >= 0 && event.key.keysym.sym < 323)
		{
			m_keys_untriggeredPress[event.key.keysym.sym] = false;
			m_keys[event.key.keysym.sym] = false;
		}
	}
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym >= 0 && event.key.keysym.sym < 323)
		{
			m_keys_untriggeredPress[event.key.keysym.sym] = true;
			m_keys[event.key.keysym.sym] = true;
		}
	}
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			m_leftMouse = true;
		}
		else if (event.button.button == SDL_BUTTON_RIGHT)
		{
			m_rightMouse = true;
		}
		//m_mouseX = event.button.x;
		//m_mouseY = event.button.y;
	}
	if (event.type == SDL_MOUSEBUTTONUP)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			m_leftMouse = false;
		}
		else if (event.button.button == SDL_BUTTON_RIGHT)
		{
			m_rightMouse = false;
		}
		//m_mouseX = event.button.x;
		//m_mouseY = event.button.y;
	}
	if (event.type == SDL_MOUSEMOTION)
	{
		m_mouseX = event.motion.x;
		m_mouseY = event.motion.y;
	}

}