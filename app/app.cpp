#include "app.hpp"


App* __theApp__ = nullptr;


App::App(const std::string& name):
	m_name(name)
{
	if (__theApp__ != nullptr)
		return;

	this->initGraphics();

	const int width  = 800;
	const int height = 600;

	m_window = Window(m_name, width, height);
	__theApp__ = this;
}

App::~App()
{
	this->close();
	this->destroyGraphics();
}

void App::close()
{
	m_window.close();
	m_renderer.destroy();

	m_name = "";
	m_isRunning = false;
}

int App::run()
{
	m_window.open();
	m_renderer = Renderer(&m_window);

	m_isRunning = true;

	while (m_isRunning) {
		m_renderer.clear();

		Event event = {};
		int res = event.poll();

		if (res)
			m_eventManager.processEvent(event);

		m_renderer.present();
	}

	return 0;
}

const Window* App::getWindow() const
{
	return &m_window;
}

const Renderer* App::getRenderer() const
{
	return &m_renderer;
}

void App::initGraphics() const
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		std::cout << SDL_GetError() << std::endl;
}

void App::destroyGraphics() const
{
	SDL_Quit();
}
