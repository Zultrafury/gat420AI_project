#pragma once
#include "Scene.h"
#include "Framebuffer.h"
#include <memory>
#include "Cells.h"

class GOLScene : public Scene
{
public:
	std::unique_ptr<Framebuffer> m_framebuffer;
	std::unique_ptr<Cells<uint8_t>> m_cellsA;
	std::unique_ptr<Cells<uint8_t>> m_cellsB;
	int m_frame;
	
	bool Initialize() override;
	void Update() override;
	void Draw() override;
};