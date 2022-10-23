#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>

#include "window.hpp"

class Renderer
{
public:
	Renderer(Window* window = nullptr);
	~Renderer();

	Renderer& operator=(const Renderer& other) = delete;
	Renderer(const Renderer& other)            = delete;

	Renderer& operator=(Renderer&& other);
	Renderer(Renderer&& other);

	void destroy();

	void clear()   const;
	void present() const;

	SDL_Renderer* getRealRenderer() const;

private:
	SDL_Renderer* m_realRenderer = nullptr;
};

#endif // RENDERER_HPP
