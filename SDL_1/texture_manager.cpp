#include "TextureManager.h"

#include <SDL_image.h>

texture_manager* texture_manager::s_p_instance = nullptr;

texture_manager::~texture_manager() = default;

bool texture_manager::load(std::string s_file_name, std::string s_id, SDL_Renderer* p_renderer)
{
	SDL_Surface* p_temp_surface = IMG_Load(s_file_name.c_str());

	if (p_temp_surface == nullptr)
	{
		return false;
	}

	SDL_Texture* p_texture = SDL_CreateTextureFromSurface(p_renderer, p_temp_surface);
	SDL_FreeSurface(p_temp_surface);

	if (p_texture != nullptr)
	{
		m_texture_map_[s_id] = p_texture;
		return true;
	}

	return false;
}

void texture_manager::draw(std::string s_id, int i_x_pos, int i_y_pos, int i_width, int i_height, SDL_Renderer* p_renderer, SDL_RendererFlip flip)
{
	SDL_Rect m_src_rect;
	SDL_Rect m_dest_rect;

	m_src_rect.x = 0;
	m_src_rect.y = 0;
	m_src_rect.w = m_dest_rect.w = i_width;
	m_src_rect.h = m_dest_rect.h = i_height;
	m_dest_rect.x = i_x_pos;
	m_dest_rect.y = i_y_pos;

	SDL_RenderCopyEx(p_renderer, m_texture_map_[s_id], &m_src_rect, &m_dest_rect, 0, nullptr, flip);
}


void texture_manager::draw_frame(std::string s_id, int i_x_pos, int i_y_pos, int i_width, int i_height, int i_current_row, int i_current_frame, SDL_Renderer* p_renderer, SDL_RendererFlip flip)
{
	SDL_Rect m_src_rect;
	SDL_Rect m_dest_rect;

	m_src_rect.x = i_width * i_current_frame;
	m_src_rect.y = i_height * (i_current_row - 1);
	m_src_rect.w = m_dest_rect.w = i_width;
	m_src_rect.h = m_dest_rect.h = i_height;
	m_dest_rect.x = i_x_pos;
	m_dest_rect.y = i_y_pos;

	SDL_RenderCopyEx(p_renderer, m_texture_map_[s_id], &m_src_rect, &m_dest_rect, 0, nullptr, flip);
}
