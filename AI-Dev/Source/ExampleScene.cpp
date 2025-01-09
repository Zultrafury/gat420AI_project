#include "ExampleScene.h"
#include "Random.h"

const color_t white{255,255,255,255};
const color_t black{0,0,0,255};

bool ExampleScene::Initialize()
{
	m_renderer.Initialize();
	m_renderer.CreateWindow("CA", 800, 600);

	m_input.Initialize();
	m_input.Update();

	m_framebuffer = std::make_unique<Framebuffer>(m_renderer,m_renderer.m_width/2, m_renderer.m_height/2);
	m_cells = std::make_unique<Cells<bool>>(m_framebuffer->m_width, m_framebuffer->m_height);
	
	return true;
}

void ExampleScene::Update()
{
	Scene::Update();
	
	m_cells->Write(m_cells->m_width / 2, 0, true);

	int rule = 57;
	for (int j = 0; j < m_cells->m_height - 1; ++j)
	{
		for (int i = 1; i < m_cells->m_width - 1; ++i)
		{
			int a = 0; // 0 - 7
			
			a |= m_cells->Read(i,j) << 1;
			a |= m_cells->Read(i - 1,j) << 2;
			a |= m_cells->Read(i + 1,j);

			uint8_t state = (rule & 1 << a);
			m_cells->Write(i,j+1, state);
		}
	}

	m_framebuffer->Clear(color_t{ 0, 0, 0, 255 });
	
	for (int i = 0; i < m_cells->m_data.size(); ++i)
	{
		m_framebuffer->m_buffer[i] = (m_cells->m_data[i]) ? white : black;
	}
}

void ExampleScene::Draw()
{
	//m_framebuffer->Clear(color_t{ 0, 0, 0, 255 });
	
	// update framebuffer
	m_framebuffer->Update();

	// show screen
	m_renderer = *m_framebuffer;
	SDL_RenderPresent(m_renderer.m_renderer);
}
