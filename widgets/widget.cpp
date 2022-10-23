#include "app.hpp"
#include "widget.hpp"


extern App* __theApp__;


Widget::Widget(Widget* parent)
{
	onTick += METHOD(*this, Widget::draw);

	m_parent   = parent;
	m_renderer = __theApp__->getRenderer();
}

Widget::~Widget()
{

}

void Widget::show()
{
	// __theApp__->getEventManager().tie(this);
}
