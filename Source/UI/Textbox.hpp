#pragma once
#include <SFML/Graphics.hpp>

// NumBox class
// Default font: rscr/default.ttf
// Default color: Dark grey / Darker grey
// Default text color: Light grey
// Default thickness: 1
class NumBox :
	public sf::Drawable
{
private:
	void draw(sf::RenderTarget & target, sf::RenderStates state) const;

public:
	NumBox(float_t posX = 0, float_t posY = 0, uint8_t width = 64, uint8_t height = 24);

	sf::FloatRect GetRectangleGlobalBounds();

	void SetPosition(float_t posX, float_t posY);
	void Move(float_t offsetX, float_t offsetY);
	void SetVariablePointer(int64_t * var);
	void SetVariableRefrence(int64_t & var);

	void Update(sf::Event & event, int64_t rangeMin, int64_t rangeMax);

private:
	int64_t * m_variable;
	sf::RectangleShape m_rectangle;
	sf::Font m_font;
	sf::Text m_text;

	sf::Color m_fillColor;
	sf::Color m_outlineColor;
	float_t m_thickness;
};