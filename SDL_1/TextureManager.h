#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <map>
#include <SDL_render.h>
#include <string>

class texture_manager
{
public:
	static texture_manager* s_p_instance;
	static texture_manager* instance()
	{
		if (s_p_instance == nullptr)
		{
			s_p_instance = new texture_manager();
			return s_p_instance;
		}
		return s_p_instance;
	}

	~texture_manager();
	bool load(std::string s_file_name, std::string s_id, SDL_Renderer* p_renderer);
	void draw(std::string s_id, int i_x_pos, int i_y_pos, int i_width, int i_height, SDL_Renderer* p_renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void draw_frame(std::string s_id, int i_x_pos, int i_y_pos, int i_width, int i_height, int i_current_row, int i_current_frame,
		SDL_Renderer* p_renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	std::map<std::string, SDL_Texture*> m_texture_map_;
	texture_manager() = default;
};
#endif // TEXTURE_MANAGER_H
