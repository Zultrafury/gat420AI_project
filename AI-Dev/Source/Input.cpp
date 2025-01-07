#include "Input.h"
#include <SDL.h>

bool Input::Initialize()
{
	int numKeys;
	const uint8_t* keyboardState = SDL_GetKeyboardState(&numKeys);

	m_keyboardState.resize(numKeys);

	// copy current keyboard state into our keyboard state
	std::copy(keyboardState, keyboardState + numKeys, m_keyboardState.begin());
	m_prevKeyboardState = m_keyboardState;

	return true;
}

void Input::Shutdown()
{
	//
}

void Input::Update()
{
	// keyboard input
	m_prevKeyboardState = m_keyboardState;
	const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
	std::copy(keyboardState, keyboardState + m_keyboardState.size(), m_keyboardState.begin());

	// mouse input
	int x, y;
	uint32_t buttonState = SDL_GetMouseState(&x, &y);
		
	m_mousePosition.x = x;
	m_mousePosition.y = y;

	SDL_GetRelativeMouseState(&x, &y);
	m_mouseRelative.x = x;
	m_mouseRelative.y = y;

	// 000 <- button state
	// 010 <- button mask
	// 000
	m_prevMouseButtonState = m_mouseButtonState;

	m_mouseButtonState[0] = buttonState & SDL_BUTTON_LMASK; 
	m_mouseButtonState[1] = buttonState & SDL_BUTTON_MMASK; 
	m_mouseButtonState[2] = buttonState & SDL_BUTTON_RMASK; 
}

void Input::SetRelativeMode(bool relative)
{
	SDL_SetRelativeMouseMode(relative ? SDL_TRUE : SDL_FALSE);
}
