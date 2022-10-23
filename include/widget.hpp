#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "gvec.hpp"
#include "slot.hpp"
#include "rect.hpp"

class Widget
{
using Time = uint32_t;

public:
	Widget(Widget* parent = nullptr);
	virtual ~Widget();

	void show();

	virtual void draw(Time time)               = 0;
	virtual Rect& bounds()                     = 0;
	virtual bool intersects(const Vec2& point) = 0;

	virtual void addChild   (Widget* child) = 0;
	virtual void removeChild(Widget* child) = 0;

	virtual const std::vector<Widget*>& getChildren() = 0;
	virtual Widget* getParent()                       = 0;

public:
	Slot<Vec2> onMouseMove = {};

	Slot<Vec2, MouseButton> onButtonClick   = {};
	Slot<Vec2, MouseButton> onButtonRelease = {};

	Slot<Key> onKeyPress   = {};
	Slot<Key> onKeyRelease = {};

	Slot<Time> onTick = {};

protected:
	Widget*         m_parent   = nullptr;
	const Renderer* m_renderer = nullptr;
};

#endif // WIDGET_HPP
