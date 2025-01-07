#include "ExampleScene.h"

#include <vector>

bool ExampleScene::Initialize()
{
	m_renderer.Initialize();
	m_renderer.CreateWindow("Example", 800, 600);

	m_input.Initialize();
	m_input.Update();

	m_framebuffer = std::make_unique<Framebuffer>(m_renderer, m_renderer.m_width/2, m_renderer.m_height/2);
	
	m_agents.emplace_back(20,20);
	
	return true;
}

void ExampleScene::Update()
{
	m_time.Tick();
	m_input.Update();

	for (Agent agent : m_agents)
	{
		agent.Update();
	}

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

void ExampleScene::Draw()
{
	m_framebuffer->Clear(color_t{ 0, 0, 0, 255 });

	for (Agent agent : m_agents)
	{
		m_framebuffer->DrawPoint(agent.x, agent.y, color_t{255,255,255,255});
	}

	// update framebuffer
	m_framebuffer->Update();

	// show screen
	m_renderer = *m_framebuffer;
	SDL_RenderPresent(m_renderer.m_renderer);
}
