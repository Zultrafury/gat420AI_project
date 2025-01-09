#pragma once
#include "Input.h"
#include "Renderer.h"
#include "ETime.h"
#include <SDL.h>

class Scene
{
public:
	virtual ~Scene() {}

	virtual bool Initialize() = 0;
	virtual void Update();
	virtual void Draw() = 0;

	bool IsQuit() { return m_quit; }

protected:
	Time m_time;
	Renderer m_renderer;
	Input m_input;

	bool m_quit{ false };
};
