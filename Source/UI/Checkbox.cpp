#include "Checkbox.hpp"

void Checkbox::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(m_rectangle, state);
}

void Checkbox::updateLook()
{
	if (m_state)
	{
		m_rectangle.setFillColor(m_outlineColor);
		m_rectangle.setOutlineColor(m_fillColor);
		m_rectangle.setOutlineThickness(m_thickness);
	}
	else
	{
		m_rectangle.setFillColor(m_fillColor);
		m_rectangle.setOutlineThickness(0);
	}
}

Checkbox::Checkbox(float_t posX, float_t posY, uint8_t width, uint8_t height)
{
	m_state = false;

	m_rectangle.setPosition(posX, posY);
	m_rectangle.setSize(sf::Vector2f(width, height));

	m_fillColor = sf::Color(104, 104, 104);
	m_outlineColor = sf::Color(62, 62, 66);
	m_thickness = 1.f;

	m_rectangle.setFillColor(m_fillColor);
	m_rectangle.setOutlineColor(m_outlineColor);
	m_rectangle.setOutlineThickness(m_thickness);
}

bool Checkbox::GetState()
{
	return m_state;
}

void Checkbox::SetState(bool state)
{
	m_state = state;
	updateLook();
}

void Checkbox::SetFillColor(const sf::Color & color)
{
	m_fillColor = color;
	m_rectangle.setFillColor(m_fillColor);
}

void Checkbox::SetOutlineColor(const sf::Color & color)
{
	m_outlineColor = color;
	m_rectangle.setOutlineColor(m_outlineColor);
}

void Checkbox::SetThickness(float_t thickness)
{
	m_thickness = thickness;
}

void Checkbox::Toggle()
{
	m_state = !m_state;
	updateLook();
}
