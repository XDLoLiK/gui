#include "app.hpp"
#include "widget.hpp"
#include "event_manager.hpp"


#define SLOT(slotName, args...)                          \
do {                                                     \
	for (size_t wid = 0; wid < m_widgets.size(); wid++)  \
		m_widgets[wid]->slotName(args);                  \
} while (0)


extern App* __theApp__;


EventManager::EventManager()
{

}

EventManager::~EventManager()
{

}

void EventManager::processEvent(const Event& event)
{
	const SDL_Event* realEvent = event.getRealEvent();

	switch (realEvent->type) {
		case SDL_QUIT:
			__theApp__->close();
			break;

		default:
			break;
	}

	SLOT(onTick, SDL_GetTicks());
}

void EventManager::operator+=(Widget* widget)
{
	assert(widget);
	m_widgets.push_back(widget);
}

void EventManager::operator-=(Widget* widget)
{
	auto start = std::remove(m_widgets.begin(), m_widgets.end(), widget);
	auto end   = m_widgets.end();

	m_widgets.erase(start, end);
}
