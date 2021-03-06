#include "Checkbox.hpp"

void Checkbox::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(m_rectangle, state);
}

void Checkbox::updateLook()
{
	if (m_state)
	{
		m_rectangle.setFillColor(m_fgColor);
		m_rectangle.setOutlineColor(m_bgColor);
		m_rectangle.setOutlineThickness(m_thickness);
	}
	else
	{
		m_rectangle.setFillColor(m_bgColor);
		m_rectangle.setOutlineThickness(0);
	}
}

Checkbox::Checkbox(float_t posX, float_t posY)
{
	m_state = false;

	m_rectangle.setPosition(posX, posY);
	m_rectangle.setSize(sf::Vector2f(16, 16));

	m_bgColor = sf::Color(104, 104, 104);
	m_fgColor = sf::Color(62, 62, 66);
	m_thickness = -1.f;

	m_rectangle.setFillColor(m_bgColor);
	m_rectangle.setOutlineColor(m_fgColor);
	m_rectangle.setOutlineThickness(m_thickness);
}

bool Checkbox::GetState()
{
	return m_state;
}

sf::FloatRect Checkbox::GetRectangleGlobalBounds()
{
	return m_rectangle.getGlobalBounds();
}

void Checkbox::SetPosition(float_t posX, float_t posY)
{
	m_rectangle.setPosition(posX, posY);
}

void Checkbox::Move(float_t offsetX, float_t offsetY)
{
	m_rectangle.move(offsetX, offsetY);
}

void Checkbox::SetState(bool state)
{
	m_state = state;
	updateLook();
}

void Checkbox::Toggle()
{
	m_state = !m_state;
	updateLook();
}
