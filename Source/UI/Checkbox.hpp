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
	Checkbox(float_t posX, float_t posY, uint8_t width = 16, uint8_t height = 16);

	bool GetState();

	void SetState(bool state);
	void SetFillColor(const sf::Color & color);
	void SetOutlineColor(const sf::Color & color);
	void SetThickness(float_t thickness);

	void Toggle();

private:
	bool m_state;
	sf::RectangleShape m_rectangle;

	// When selected - fill = outline 

	sf::Color m_fillColor;
	sf::Color m_outlineColor;
	float_t m_thickness;
};