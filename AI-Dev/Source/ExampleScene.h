#pragma once
#include "Scene.h"
#include "Framebuffer.h"
#include <memory>
#include "Cells.h"

class ExampleScene : public Scene
{
public:
	std::unique_ptr<Framebuffer> m_framebuffer;
	std::unique_ptr<Cells<bool>> m_cells;
	
	bool Initialize() override;
	void Update() override;
	void Draw() override;
};

