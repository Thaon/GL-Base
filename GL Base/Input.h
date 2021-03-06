#ifndef Input_H
#define Input_H

#include <SDL.h>
#include <glm\glm.hpp>

class Input
{
public:
	//keyboard
	static bool GetKeyDown(SDL_Keycode code) { return m_keys[code]; }
	static bool GetKeyPressed(SDL_Keycode code) {
		bool ret = m_keys_untriggeredPress[code];
		m_keys_untriggeredPress[code] = false;
		return ret;
	}

	//mouse
	static glm::vec2 GetMousePosition() { return glm::vec2(m_mouseX, m_mouseY); }
	static bool GetLeftMouseDown() { return m_leftMouse; }
	static bool GetRightMouseDown() { return m_rightMouse; }
	static void CenterMousePosition(SDL_Window* window, int x, int y) { SDL_WarpMouseInWindow(window, x, y); }

	static void Init();
	static void Update(SDL_Event& event);

private:
	static float m_mouseX, m_mouseY;
	static bool m_keys[323], m_leftMouse, m_rightMouse;
	static bool m_keys_untriggeredPress[323];
};

#endif