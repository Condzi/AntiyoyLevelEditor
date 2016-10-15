#include "ToolTab.hpp"

void ToolTab::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(m_background, state);

	target.draw(m_toolSelect, state);
	target.draw(m_toolBrush, state);
}

void ToolTab::arrange()
{
	m_background.setPosition(m_positionX, m_positionY);

	m_toolSelect.setPosition((m_positionX + 5 / m_scale) * m_scale, (m_positionY + 5 / m_scale) * m_scale);
	m_toolBrush.setPosition((m_positionX + 5 / m_scale) * m_scale, (m_positionY + 5 / m_scale) * m_scale + m_toolSelect.getGlobalBounds().height);
}

void ToolTab::loadTextures()
{
	if (m_textureSelect.loadFromFile("rsrc/cursor.png"))
	{
		m_toolSelect.setTexture(&m_textureSelect);
	}
	else
	{
		m_toolSelect.setFillColor(sf::Color::Red);
	}

	if (m_textureBrush.loadFromFile("rsrc/brush.png"))
	{
		m_toolBrush.setTexture(&m_textureBrush);
	}
	else
	{
		m_toolBrush.setFillColor(sf::Color::Red);
	}

	m_nullTexture = sf::Texture();
}

ToolTab::ToolTab(float_t posX, float_t posY)
{
	m_positionX = posX;
	m_positionY = posY;
	m_scale = 3;

	loadTextures();

	m_toolSelect.setOutlineColor(sf::Color(241, 241, 241));
	m_toolSelect.setSize(sf::Vector2f(9, 16));
	m_toolSelect.setOutlineThickness(1.f);

	m_toolBrush.setOutlineColor(sf::Color(241, 241, 241));
	m_toolBrush.setSize(sf::Vector2f(9, 16));
	m_toolBrush.setOutlineThickness(1.f);

	m_background.setPosition(m_positionX, m_positionY);
	m_background.setSize(sf::Vector2f(m_toolBrush.getGlobalBounds().width + 5 / m_scale, m_toolBrush.getGlobalBounds().height + m_toolSelect.getGlobalBounds().height + 5 / m_scale));
	m_background.setFillColor(sf::Color(30, 30, 30));

	m_background.setScale(m_scale, m_scale);
	m_toolSelect.setScale(m_scale, m_scale);
	m_toolBrush.setScale(m_scale, m_scale);

	arrange();
}

void ToolTab::Select(uint8_t id)
{
	m_selectSelected = false;
	m_brushSelected = false;

	if (id == 0)
	{
		m_selectSelected = true;
	}
	else if (id == 1)
	{
		m_brushSelected = true;
	}
}

uint8_t ToolTab::WhatToolSelected()
{
	if (m_selectSelected)
	{
		return 0;
	}

	if (m_brushSelected)
	{
		return 1;
	}
}

sf::Texture & ToolTab::GetSelectedToolTexture()
{
	if (m_selectSelected)
	{
		return m_textureSelect;
	}

	if (m_brushSelected)
	{
		return m_textureBrush;
	}

	return m_nullTexture;
}

sf::FloatRect ToolTab::GetRectangleGlobalBounds(uint8_t id)
{
	if (id == 0)
	{
		return m_toolSelect.getGlobalBounds();
	}

	if (id == 1)
	{
		return m_toolBrush.getGlobalBounds();
	}

	if (id == 2)
	{
		return m_background.getGlobalBounds();
	}

	return sf::FloatRect();
}

void ToolTab::SetPosition(float_t x, float_t y)
{
	m_positionX = x;
	m_positionY = y;
	arrange();
}

void ToolTab::Move(float_t x, float_t y)
{
	m_positionX += x;
	m_positionY += y;

	m_background.move(x, y);

	m_toolSelect.move(x, y);
	m_toolBrush.move(x, y);
}
