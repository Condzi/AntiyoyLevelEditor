#include "ColorTab.hpp"

void ColorTab::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(m_background, state);

	for (const sf::RectangleShape & rect : m_colorRepresentation)
	{
		target.draw(rect, state);
	}
}

void ColorTab::arrange()
{
	m_background.setPosition(m_positionX, m_positionY);

	for (uint8_t y = 0; y < 4; ++y)
	{
		for(uint8_t x = 0; x < 4; ++x)
		{
			m_colorRepresentation[x * 4 + y].setPosition(m_positionX + x * 5 + 32 * x + 5, m_positionY + 32 * y + 5 * y + 5);
		}
	}
}

ColorTab::ColorTab(float_t x, float_t y)
{
	m_positionX = x;
	m_positionY = y;

	m_background.setSize(sf::Vector2f(153, 153));
	m_background.setFillColor(sf::Color(30, 30, 30));

	for (sf::RectangleShape & rect : m_colorRepresentation)
	{
		rect.setSize(sf::Vector2f(32, 32));
		rect.setOutlineThickness(-5);
		rect.setOutlineColor(sf::Color(241, 241, 241));
	}

	arrange();
}

sf::FloatRect ColorTab::GetRectangleGlobalBounds(uint8_t id)
{
	if (id == 16)
	{
		return m_background.getGlobalBounds();
	}
	else if (id < 16)
	{
		return m_colorRepresentation[id].getGlobalBounds();
	}

	return sf::FloatRect();
}

void ColorTab::SetPosition(float_t x, float_t y)
{
	m_positionX = x;
	m_positionY = y;
	arrange();	
}

void ColorTab::SetColor(uint8_t index, const sf::Color & color)
{
	if (index > 16)
	{
		return;
	}

	m_colors[index] = color;
	m_colorRepresentation[index].setFillColor(color);
}

void ColorTab::Move(float_t x, float_t y)
{
	m_positionX += x;
	m_positionY += y;

	m_background.move(x, y);

	for (sf::RectangleShape & rect : m_colorRepresentation)
	{
		rect.move(x, y);
	}
}
