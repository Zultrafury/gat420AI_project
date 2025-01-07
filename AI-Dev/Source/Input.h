#pragma once
#include <SDL.h>
#include <vector>
#include <array>

class Input
{
public:
	Input() = default;
	~Input() = default;

	bool Initialize();
	void Shutdown();

	void Update();

	bool GetKeyDown(uint8_t key) { return m_keyboardState[key]; }
	bool GetPreviousKeyDown(uint8_t key) { return m_prevKeyboardState[key]; }

	SDL_Point GetMousePosition() { return m_mousePosition; }
	SDL_Point GetMouseRelative() { return m_mouseRelative; }

	bool GetMouseButtonDown(uint8_t button) { return m_mouseButtonState[button]; }
	bool GetPreviousMouseButtonDown(uint8_t button) { return m_prevMouseButtonState[button]; }

	void SetRelativeMode(bool relative);

private:
	std::vector<uint8_t> m_keyboardState;
	std::vector<uint8_t> m_prevKeyboardState;

	SDL_Point m_mousePosition{ 0, 0 };
	SDL_Point m_mouseRelative{ 0, 0 };
	
	std::array<uint8_t, 3> m_mouseButtonState{ 0, 0, 0 };
	std::array<uint8_t, 3> m_prevMouseButtonState{ 0, 0, 0 };
};