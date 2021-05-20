#include "DEBUG_Stuff.h"
#include "color.hpp"
#include <cstdio>
#include <iostream>
#include <Windows.h>

int m_iRenderedFrames = 0;

DEBUG_Stuff::DEBUG_Stuff()
= default;

DEBUG_Stuff::~DEBUG_Stuff()
= default;

void DEBUG_Stuff::animations(const int x_pos, const int y_pos, const int x_pos_change, const int y_pos_change, const bool f_enabled)
{
	if (f_enabled)
	{
		m_iRenderedFrames++;
		std::cout << dye::aqua("\n*****FRAME = ") << dye::aqua(y_pos_change) << dye::aqua("x") << dye::aqua(x_pos_change) << dye::aqua("*****");
		std::cout << "\n  XPos = " << x_pos;
		std::cout << "\n  XPosChange = " << x_pos_change;
		std::cout << "\n  YPos = " << y_pos;
		std::cout << "\n  YPosChange = " << y_pos_change;
		std::cout << "\n  RenderedFrames = " << m_iRenderedFrames;
		std::cout << dye::aqua("\n*********************\n");		
	}
}

void DEBUG_Stuff::console_enabled(const bool f_enabled)
{
	if (f_enabled)
	{
		AllocConsole();
		std::freopen("CON", "w", stdout);	
	}
}

void DEBUG_Stuff::init_info(const bool b_success, const bool f_enabled)
{
	if (f_enabled)
	{
		std::cout << dye::aqua("\n********SDL_Init********");

		if (b_success)
		{
			std::cout << dye::green("\n  SDL_Init  successful");
		}
		else
		{
			std::cout << dye::red("\n  SDL_Init failed");
		}

		std::cout << dye::aqua("\n************************\n");
		
	}
}

void DEBUG_Stuff::renderer_info(const bool b_success, const bool f_enabled)
{
	if (f_enabled)
	{
		std::cout << dye::aqua("\n***********SDL_Renderer***********");

		if (b_success)
		{
			std::cout <<  dye::green("\n  SDL_CreateRenderer  successful");
		}
		else
		{
			
			std::cout << dye::red("\n  SDL_CreateRenderer failed");
		}
		std::cout << dye::aqua("\n**********************************\n");
	}
}

void DEBUG_Stuff::window_info(const bool b_success, const bool f_enabled)
{
	if (f_enabled)
	{
		std::cout << dye::aqua("\n***********SDL_Window***********");

		if (b_success)
		{
			std::cout <<  dye::green("\n  SDL_CreateWindow  successful");
		}
		else
		{
			
			std::cout << dye::red("\n  SDL_CreateWindow failed");
		}
		std::cout << dye::aqua("\n********************************\n");
	}	
}

void DEBUG_Stuff::everything_is_fine(const bool b_success, const bool f_enabled)
{
	if (f_enabled)
	{
		std::cout << dye::aqua("\n*************INIT*************");
		if (b_success)
		{
			std::cout <<  dye::green("\n  Everything works fantastic");
		}
		else
		{
			std::cout <<  dye::green("\n  Bad :(");
		}
		std::cout << dye::aqua("\n******************************\n");
		
	}
}




