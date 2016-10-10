#include "UI/Checkbox.hpp"
#include "UI/Textbox.hpp"
#include "UI/PropertiesTab.hpp"
#include "Components/MapRenderer.hpp"
#include "Components/Map.hpp"
#include <iostream>

int main()
{
	try
	{
		sf::RenderWindow win(sf::VideoMode(1280, 720), "Antiyoy Level Editor");

		Map map(10, 10);
		MapRenderer mapRenderer(&map, 50);
		PropertiesTab prop(100, 100);
		sf::Vector2i mousePos(0,0);
		sf::Vector2i mousePosPrev;

		map[20].SetDifficulty(10);
		map[20].SetIsAlive(true);
		map[20].SetOwnerID(66);
		map[20].SetIncome(666);
		prop.SetCellPointer(&map[20]);

		sf::Event ev;

		while (win.isOpen())
		{
			mousePosPrev = mousePos;
			mousePos = sf::Mouse::getPosition(win);
			while (win.pollEvent(ev))
			{
				if (ev.type == sf::Event::Closed)
				{
					win.close();
				}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (prop.GetRectangleGlobalBounds(4).contains((sf::Vector2f)mousePos))
					{
						prop.Move(mousePos.x - mousePosPrev.x, mousePos.y - mousePosPrev.y);
					}
				}
				
			}

			win.clear(sf::Color::Cyan);
			win.draw(mapRenderer);
			win.draw(prop);
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

