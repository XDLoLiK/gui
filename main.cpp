#include "app.hpp"
#include "widget.hpp"
#include "button.hpp"

int main()
{
	App app("test");

	// Button closeButton("close", 700, 0, 100, 50);
	// closeButton.onButtonClick += METHOD(App, App::close);
	// closeButton.show();

	return app.run();
}
