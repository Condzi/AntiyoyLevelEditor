#pragma once
#include <SFML/Graphics.hpp>


class ToolTab :
	public sf::Drawable
{
private:
	void draw(sf::RenderTarget & target, sf::RenderStates state) const;
	void arrange();
	void loadTextures();

public:
	ToolTab(float_t posX = 0, float_t posY = 0);

	// Only one selected 
	// 0 - select tool
	// 1 - brush (paint) tool
	void Select(uint8_t id);

	// 0 - select tool
	// 1 - brush (paint) tool
	uint8_t WhatToolSelected();
	// Returns selected tool texture, probably 9x16
	sf::Texture & GetSelectedToolTexture();
	// 0 - select tool
	// 1 - brush (paint) tool
	// 2 - background
	sf::FloatRect GetRectangleGlobalBounds(uint8_t id);

	void SetPosition(float_t x, float_t y);
	void Move(float_t x, float_t y);

private:
	float_t m_positionX;
	float_t m_positionY;
	float_t m_scale;

	sf::RectangleShape m_background;

	// rsrc/cursor.png
	sf::RectangleShape m_toolSelect;
	// rsrc/brush.png
	sf::RectangleShape m_toolBrush;
	
	// Is ... option selected?
	
	bool m_selectSelected;
	bool m_brushSelected;

	sf::Texture m_textureSelect;
	sf::Texture m_textureBrush;

	sf::Texture m_nullTexture;
};