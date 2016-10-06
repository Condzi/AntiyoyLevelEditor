#include "UI/Checkbox.hpp"
#include "UI/Textbox.hpp"
#include "Components/MapRenderer.hpp"
#include "Components/Map.hpp"
#include <iostream>

int main()
{
	try
	{
		sf::RenderWindow win(sf::VideoMode(800, 600), "Antiyoy Level Editor");

		Map map(10, 10);
		MapRenderer mapRenderer(&map, 50);
		NumBox nb(200, 200, 200, 100);
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
				nb.Update(ev, -1, 100);
			}

			win.clear(sf::Color::Cyan);
			win.draw(mapRenderer);
			win.draw(nb);
			win.display();
		}

	}

	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
		std::cin.get();

		return 1;
	}

	return 0;
}

