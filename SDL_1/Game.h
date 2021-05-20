#ifndef GAME_H
#define GAME_H
#include "SDL.h"


class Game {
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render() const;
	void update();
	void handleEvents();
	void clean() const;
	bool running() const { return m_bRunning; } // funkcja dostępu do prywatnej zmiennej running

private:
	SDL_Window * m_pWindow{};
	SDL_Renderer* m_pRenderer{};

	void animate();
	bool m_bRunning{};
};
#endif // GAME_H
