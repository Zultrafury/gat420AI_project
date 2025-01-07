#pragma once
#include "Color.h"

#include <SDL.h>
#include <vector>

class Framebuffer
{
public:
	Framebuffer(const class Renderer& renderer, int width, int height);
	~Framebuffer();

	void Update();
	void Clear(const color_t& color);

	void DrawPoint(int x, int y, const color_t& color);

	std::vector<color_t>& GetBuffer() { return m_buffer; }

public:
	int m_width{ 0 };
	int m_height{ 0 };
	int m_pitch{ 0 };

	SDL_Texture* m_texture{ nullptr };
	std::vector<color_t> m_buffer;
	std::vector<float> m_depth;
};