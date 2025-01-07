#pragma once
#include "Scene.h"
#include "Framebuffer.h"
#include <memory>
#include "Agent.h"

class ExampleScene : public Scene
{
public:
	std::unique_ptr<Framebuffer> m_framebuffer;
	std::vector<Agent> m_agents;
	
	bool Initialize() override;
	void Update() override;
	void Draw() override;
};

