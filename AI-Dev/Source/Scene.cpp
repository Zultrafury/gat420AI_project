#include "Scene.h"

void Scene::Update()
{
    m_time.Tick();
    m_input.Update();

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            m_quit = true;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
        {
            m_quit = true;
        }
    }
}
