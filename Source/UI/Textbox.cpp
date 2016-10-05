#include "Textbox.hpp"
#include <iostream>

void NumBox::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(m_rectangle, state);
	target.draw(m_text, state);
}

NumBox::NumBox(float_t posX, float_t posY, uint8_t width, uint8_t height)
{
	m_rectangle.setPosition(posX, posY);
	m_rectangle.setSize(sf::Vector2f(width, height));

	m_fillColor = sf::Color(104, 104, 104);
	m_outlineColor = sf::Color(62, 62, 66);
	m_thickness = 1.f;

	m_rectangle.setFillColor(m_fillColor);
	m_rectangle.setOutlineColor(m_outlineColor);
	m_rectangle.setOutlineThickness(m_thickness);

	if (!m_font.loadFromFile("rsrc/default.ttf"))
	{
		throw std::exception("Cannot load texture (rsrc/default.ttf)");
	}

	m_text.setFont(m_font);
	m_text.setPosition(posX + m_thickness, posY + m_thickness);
	m_text.setCharacterSize(height - m_thickness * 2);
	m_text.setFillColor(sf::Color(241, 241, 241));

	m_variable = nullptr;
}

void NumBox::SetVariablePointer(int64_t * var)
{
	m_variable = var;
}

void NumBox::SetFillColor(const sf::Color & color)
{
	m_fillColor = color;
	m_rectangle.setFillColor(color);
}

void NumBox::SetOutlineColor(const sf::Color & color)
{
	m_outlineColor = color;
	m_rectangle.setOutlineColor(color);
}

void NumBox::SetTextColor(const sf::Color & color)
{
	m_text.setFillColor(color);
}

void NumBox::SetTextSize(uint8_t size)
{
	m_text.setCharacterSize(size);
}

void NumBox::SetThickness(float_t thickness)
{
	m_thickness = thickness;
	m_rectangle.setOutlineThickness(m_thickness);
}

void NumBox::Update(sf::Event & event, int64_t rangeMin, int64_t rangeMax)
{
	if (rangeMax < rangeMin)
	{
		return;
	}

	uint32_t unicodeChar = 0;

	if (event.type == sf::Event::TextEntered)
	{
		unicodeChar = event.text.unicode;

		if (unicodeChar > 47 && // 0...
			unicodeChar < 58 || // ...9
			unicodeChar == 8 || // backspace
			(rangeMin < 0 &&
				!m_text.getString().getSize() && //if it is beginnig of the word
				unicodeChar == 45)) // minus
		{
			if (unicodeChar == 45) // Minus
			{
				m_text.setString("-");
			}
			else
			{
				if (unicodeChar == 8) // Backspace
				{
					std::string str = m_text.getString();
					if (str.size() > 0)
					{
						str.erase(str.end() - 1);
					}
					else
					{
						str = "";
					}
					m_text.setString(str);
				}
				else // 0..9
				{
					m_text.setString(m_text.getString() + std::to_string(unicodeChar - 48));
				}

				if (m_text.getString().getSize())
				{
					*m_variable = std::stoi(std::string(m_text.getString()));
				}

				std::cout << m_text.getPosition().x << ", " << m_text.getPosition().y << "\n";
				std::cout << m_text.getCharacterSize() << "\n";
				std::cout << (std::string)m_text.getString() << "\n=====\n";
			}
		}
	}
}
