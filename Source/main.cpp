#include "UI/Checkbox.hpp"
#include "UI/Textbox.hpp"
#include "Components/MapRenderer.hpp"
#include "Components/Map.hpp"
#include <iostream>

int main()
{
	try
	{
		sf::RenderWindow win(sf::VideoMode(800, 600), "Antiyoy Level Editor", sf::Style::Close);

		Map map(20, 20);
		MapRenderer mapRenderer(&map);

		sf::Event ev;

		while (win.isOpen())
		{
			while (win.pollEvent(ev))
			{
				if (ev.type == sf::Event::Closed)
				{
					win.close();
				}
			}

			win.clear();
			win.draw(mapRenderer);
			win.display();
		}

	}

	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
		std::cin.get();
	}
}

