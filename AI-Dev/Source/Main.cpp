//#include "ExampleScene.h"
#include <memory>
#include <SDL.h>

#include "GOLScene.h"

int main(int, char**)
{
	std::unique_ptr<GOLScene> scene = std::make_unique<GOLScene>();

	scene->Initialize();
	while (!scene->IsQuit())
	{
		scene->Update();
		scene->Draw();
	}

	return 0;
}
