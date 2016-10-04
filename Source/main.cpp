#include "UI/Checkbox.hpp"

int main()
{
	sf::RenderWindow win(sf::VideoMode(800, 600), "Antiyoy Level Editor", sf::Style::Close);
	win.setFramerateLimit(31);
	
	Checkbox box(100, 100);

	sf::Event ev;

	while (win.isOpen())
	{
		while (win.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				win.close();
			}
			if (ev.key.code == sf::Keyboard::Key::A)
			{
				box.SetState(true);
			}
			if (ev.key.code == sf::Keyboard::Key::S)
			{
				box.SetState(false);
			}
		}

		win.clear();
		win.draw(box);
		win.display();
	}
}