#ifndef BUTTON_HPP
#define BUTTON_HPP

class Button : public Widget
{
public:
	Button(const std::string& name = "", int x = 0, int y = 0, 
		                                 int w = 0, int h = 0):
		m_name(name),
		m_bounds(x, y, w, h)
	{

	}

	~Button()
	{

	}

private:
	std::string m_name = "";
	Rect m_bounds = {};

	std::vector<Widget*> m_children = {};

	bool m_isClicked = false;
};

#endif // BUTTON_HPP
