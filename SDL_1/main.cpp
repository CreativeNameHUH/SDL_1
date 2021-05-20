#include <SDL.h>
#include <cstdio>
#include <Windows.h>
#include "Game.h"
#include "DEBUG_Stuff.h"

SDL_Window* g_pWindow = nullptr;
SDL_Renderer* g_pRenderer = nullptr;

// Game object

Game* g_game = nullptr;

int main(int argc, char* argv[])
{
	DEBUG_Stuff::console_enabled(true);
	
	g_game = new Game();
	g_game->init("TEST", 100, 100, 640, 480, false);
	const int i_start_ticks = static_cast<int>(SDL_GetTicks());
	while (g_game->running())
	{
		g_game->handleEvents();
		if (((static_cast<int>(SDL_GetTicks()) - i_start_ticks) % 17) == 0)
		{
			g_game->update();
			g_game->render();
		}
		
	}
	g_game->clean();
	return 0;
}