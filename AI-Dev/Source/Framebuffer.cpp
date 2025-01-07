#include "Framebuffer.h"
#include "Renderer.h"
#include "MathUtils.h"

#include <iostream>

Framebuffer::Framebuffer(const Renderer& renderer, int width, int height)
{
	m_width = width;
	m_height = height;
	m_pitch = width * sizeof(color_t);

	m_texture = SDL_CreateTexture(renderer.m_renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, width, height);
	if (m_texture == nullptr)
	{
		std::cerr << "Error creating SDL texture: " << SDL_GetError() << std::endl;
	}

	m_buffer.resize(m_width * m_height);
	m_depth.resize(m_width * m_height);
}

Framebuffer::~Framebuffer()
{
	SDL_DestroyTexture(m_texture);
}

void Framebuffer::Update()
{
	SDL_UpdateTexture(m_texture, NULL, m_buffer.data(), m_pitch);
}

void Framebuffer::Clear(const color_t& color)
{
	std::fill(m_buffer.begin(), m_buffer.end(), color);
	std::fill(m_depth.begin(), m_depth.end(), std::numeric_limits<float>().max());
}

void Framebuffer::DrawPoint(int x, int y, const color_t& color)
{
	m_buffer[x + y * m_width] = color;
	
}
