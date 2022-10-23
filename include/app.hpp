#ifndef APP_HPP
#define APP_HPP

#include "window.hpp"
#include "renderer.hpp"
#include "event_manager.hpp"

class App
{
public:
	App(const std::string& name);
	~App();

	void close();
	int run();

	const Window*   getWindow()   const;
	const Renderer* getRenderer() const;

private:
	void initGraphics()    const;
	void destroyGraphics() const;

private:
	std::string m_name = "";

	Window   m_window   = Window();
	Renderer m_renderer = Renderer();

	EventManager m_eventManager = EventManager();

	bool m_isRunning = false;
};

#endif // APP_HPP
