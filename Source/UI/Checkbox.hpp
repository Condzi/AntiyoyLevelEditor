#pragma once
#include <SFML/Graphics.hpp>

// Checkbox
// Can be checked / unchecked
// Default color: Dark grey / Darker grey
// Default thickness: 1
class Checkbox : 
	public sf::Drawable
{
private:
	void draw(sf::RenderTarget & target, sf::RenderStates state) const;
	// Call when state is changing
	void updateLook();

public:
	Checkbox(float_t posX = 0, float_t posY = 0, uint8_t width = 16, uint8_t height = 16);

	bool GetState();
	sf::FloatRect GetRectangleGlobalBounds();

	void SetPosition(float_t posX, float_t posY);
	void Move(float_t offsetX, float_t offsetY);
	void SetState(bool state);
	void SetFillColor(const sf::Color & color);
	void SetOutlineColor(const sf::Color & color);
	void SetThickness(float_t thickness);

	void Toggle();

private:
	bool m_state;
	sf::RectangleShape m_rectangle;

	// When selected - fill = outline 

	sf::Color m_bgColor;
	sf::Color m_fgColor;
	float_t m_thickness;
};