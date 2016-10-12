#pragma once
#include <SFML/Graphics.hpp>


// Color Tab
// 4x4
class ColorTab :
	public sf::Drawable
{
	void draw(sf::RenderTarget & target, sf::RenderStates state) const;
	void arrange();

public:
	ColorTab(float_t x, float_t y);

	// 0 - 16
	// 16 - background
	sf::FloatRect GetRectangleGlobalBounds(uint8_t id);

	void SetPosition(float_t x, float_t y);
	// colors are in map 4x4
	// x * width + y = index
	// x + 4 + y
	void SetColor(uint8_t index, const sf::Color & color);
	void Move(float_t x, float_t y);

private:
	sf::RectangleShape m_background;

	float_t m_positionX;
	float_t m_positionY;

	sf::Color m_colors[16];

	sf::RectangleShape m_colorRepresentation[16];
};