#include "Game.h"
#include "DEBUG_Stuff.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include <iostream>


SDL_Window* g_p_window;
SDL_Renderer* g_p_Renderer;

int m_iXPosChange = 0;
int m_iYPosChange = 0;
int m_iXPos[5]{ 0, 192, 384, 576, 768 };
int m_iYPos[6]{ 0, 192, 384, 576, 768, 960 };
int g_current_frame = 0;
int g_current_row = 1;
texture_manager g_texture_manager;


Game::Game()
= default;

Game::~Game()
= default;

void Game::animate()
{
		DEBUG_Stuff::animations(0, 0, g_current_frame, g_current_row, true);
		if (g_current_frame == 4)
		{
			if (g_current_row < 6)
			{
				g_current_row++;
				g_current_frame = 0;
			}
			else
			{
				g_current_row = 1;
				g_current_frame = 0;
			}
		}
		else
			g_current_frame++;
}


void Game::update()
{
	animate();
}

bool Game::init(const char * title, const int xpos, const int ypos, const int width, const int height, const bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		DEBUG_Stuff::init_info(true, true);
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != nullptr)
		{
			DEBUG_Stuff::window_info(true, true);
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (m_pRenderer != nullptr)
			{
				DEBUG_Stuff::renderer_info(true, true);
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 125);
			}
			else
			{	
				DEBUG_Stuff::renderer_info(false, true);
				return false;
			}
		}
		else
		{
			DEBUG_Stuff::window_info(true, true);
			return false;
		}
	}
	else
	{
		DEBUG_Stuff::init_info(false, true);
		DEBUG_Stuff::everything_is_fine(false, true);
		return false;
	}

	DEBUG_Stuff::everything_is_fine(true, true);
	m_bRunning = true;
	g_texture_manager.load("Chaos.png", "animate", m_pRenderer);

	return true;
}

void Game::render() const
{
	SDL_RenderClear(m_pRenderer); // wyczyść renderer do koloru rysowania
	g_texture_manager.draw("animate", 0, 0, 192, 192, m_pRenderer);
	g_texture_manager.draw_frame("animate", 192, 192, 192, 192, g_current_row, g_current_frame, m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean() const
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
			
		default:
			break;
		}
	}
}



