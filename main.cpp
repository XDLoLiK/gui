#include "app.hpp"
#include "button.hpp"

int main()
{
	App app("test");

	Button* closeButton = new Button();
	closeButton->setGeometry({700, 550, 100, 50});
	closeButton->setTexture("skins/close_button.png");
	closeButton->show();

	Button* menuFrame = new Button();
	menuFrame->setGeometry({0, 0, 800, 100});
	menuFrame->setTexture("./skins/menu_frame.png");
	menuFrame->show();

	return app.run();
}
