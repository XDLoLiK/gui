#include "renderer.hpp"

Renderer::Renderer(Window* window)
{
	if (!window)
		return;

	m_realRenderer = SDL_CreateRenderer(window->getRealWindow(), -1, 
		                                SDL_RENDERER_ACCELERATED);
	if (!m_realRenderer)
		std::cout << SDL_GetError() << std::endl;
}

Renderer::~Renderer()
{
	this->destroy();
}

Renderer& Renderer::operator=(Renderer&& other)
{
	this->destroy();
	this->m_realRenderer = other.m_realRenderer;
	other.m_realRenderer = nullptr;

	return *this;
}

Renderer::Renderer(Renderer&& other)
{
	this->m_realRenderer = other.m_realRenderer;
	other.m_realRenderer = nullptr;
}

void Renderer::destroy()
{
	SDL_DestroyRenderer(m_realRenderer);
	m_realRenderer = nullptr;
}

void Renderer::clear() const
{
	SDL_SetRenderDrawColor(m_realRenderer, 255, 255, 255, 255);
	SDL_RenderClear(m_realRenderer);
}

void Renderer::present() const
{
	SDL_RenderPresent(m_realRenderer);
}

SDL_Renderer* Renderer::getRealRenderer() const
{
	return m_realRenderer;
}
