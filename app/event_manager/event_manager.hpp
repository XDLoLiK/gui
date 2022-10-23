#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <vector>
#include <cassert>

#include "event.hpp"

class Widget;

class EventManager
{
public:
	EventManager();
	~EventManager();

	void processEvent(const Event& event);

	void operator+=(Widget* widget);
	void operator-=(Widget* widget);

private:
	std::vector<Widget*> m_widgets = {};
};

#endif // EVENT_MANAGER_HPP
