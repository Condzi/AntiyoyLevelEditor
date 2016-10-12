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
		throw std::exception("Cannot load texture (rsrc/default.ttf) [NumBox]");
	}
	
	m_text.setString("");
	m_text.setFont(m_font);
	m_text.setCharacterSize(height - m_thickness * 2);
	m_text.setPosition(posX , posY);
	m_text.setFillColor(sf::Color(241, 241, 241));

	m_variable = nullptr;
}

sf::FloatRect NumBox::GetRectangleGlobalBounds()
{
	return m_rectangle.getGlobalBounds();
}

void NumBox::SetPosition(float_t posX, float_t posY)
{
	m_rectangle.setPosition(posX, posY);
	m_text.setPosition(posX, posY);
}

void NumBox::Move(float_t offsetX, float_t offsetY)
{
	m_rectangle.move(offsetX, offsetY);
	m_text.move(offsetX, offsetY);
}

void NumBox::SetVariablePointer(int64_t * var)
{
	m_variable = var;
	m_text.setString(std::to_string(*m_variable));
}

void NumBox::SetVariableRefrence(int64_t & var)
{
	m_variable = &var;
	m_text.setString(std::to_string(*m_variable));
}

void NumBox::Update(sf::Event & event, int64_t rangeMin, int64_t rangeMax)
{
	if (rangeMax < rangeMin)
	{
		return;
	}

	uint32_t unicodeChar = 0;
	// For some operations
	std::string helpStr = "";

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
					helpStr = m_text.getString();
					if (helpStr.size() > 0)
					{
						helpStr.erase(helpStr.end() - 1);
					}
					else
					{
						helpStr = "";
					}
					m_text.setString(helpStr);
				}
				else // 0..9
				{
					if ((m_text.getString().getSize() == 0 ||
						m_text.getString()[0] == '-') &&
						unicodeChar == 48) //if 0 is first letter
					{
						return;
					}

					m_text.setString(m_text.getString() + std::to_string(unicodeChar - 48));
				}

				if (m_text.getString().getSize())
				{
					int64_t conversion = std::stoi(std::string(m_text.getString()));

					if (conversion < rangeMin || conversion > rangeMax + 1)
					{
						//... message or something
						helpStr = m_text.getString();
						helpStr.erase(helpStr.end() - 1);
						m_text.setString(helpStr);
					}
					else
					{
						*m_variable = conversion;
					}
				}
			}
		}
	}
}
