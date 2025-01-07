#pragma once
#include <SDL.h>
#include <string>

class Renderer
{
public:
	Renderer() = default;
	~Renderer();

	bool Initialize();
	bool CreateWindow(const std::string& name, int width, int height);
	void CopyFramebuffer(const class Framebuffer& framebuffer);

	void operator = (const class Framebuffer& framebuffer);

public:
	int m_width{ 0 };
	int m_height{ 0 };

	SDL_Window* m_window{ nullptr };
	SDL_Renderer* m_renderer{ nullptr };
};