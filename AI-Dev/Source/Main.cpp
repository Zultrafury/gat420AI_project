#include "ExampleScene.h"
#include <memory>
#include <SDL.h>

int main(int, char**)
{
	std::unique_ptr<ExampleScene> scene = std::make_unique<ExampleScene>();

	scene->Initialize();
	while (!scene->IsQuit())
	{
		scene->Update();
		scene->Draw();
	}

	return 0;
}