#include "UI/Checkbox.hpp"
#include "UI/Textbox.hpp"
#include "Components/Map.hpp"
#include <iostream>

int main()
{
	try
	{
		sf::RenderWindow win(sf::VideoMode(800, 600), "Antiyoy Level Editor", sf::Style::Close);

		Checkbox box(100, 100);
		NumBox nb(200, 200);
		int64_t x = 0;
		nb.SetVariablePointer(&x);

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
				else if (ev.key.code == sf::Keyboard::Key::S)
				{
					box.SetState(false);
				}
				nb.Update(ev, -10, 10);
			}

			win.clear();
			win.draw(box);
			win.draw(nb);
			win.display();
		}

	}

	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
		std::cin.get();
	}
}

