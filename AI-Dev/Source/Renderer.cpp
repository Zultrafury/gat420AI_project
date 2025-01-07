#include "Renderer.h"
#include "Framebuffer.h"
#include <iostream>

Renderer::~Renderer()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
}

bool Renderer::Initialize()
{
    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

bool Renderer::CreateWindow(const std::string& name, int width, int height)
{
    m_width = width;
    m_height = height;

    // create window
    // returns pointer to window if successful or nullptr if failed
    m_window = SDL_CreateWindow(name.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_SHOWN);
    if (m_window == nullptr)
    {
        std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    
    // create renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    if (m_renderer == nullptr)
    {
        std::cerr << "Error creating SDL renderer: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    return true;
}

void Renderer::CopyFramebuffer(const Framebuffer& framebuffer)
{
    SDL_RenderCopy(m_renderer, framebuffer.m_texture, NULL, NULL);
}

void Renderer::operator=(const Framebuffer& framebuffer)
{
    SDL_RenderCopy(m_renderer, framebuffer.m_texture, NULL, NULL);
}
