#pragma once
#include "Map.hpp"
#include <SFML/Graphics.hpp>

class MapRenderer
{
private:
	// If there was changes on map and need to be recalculated
	void update();

public:
	MapRenderer(const Map * mapToRender, uint16_t tileSize = 30, float_t thicnkess = 1.f);

	uint16_t GetTileSize();
	const Map & GetMap();

	void SetMap(const Map * mapToRender);
	void SetAreaToRender(const sf::FloatRect & area);
	void MoveAreaToRender(float_t x, float_t y);
	void SetTileSize(uint16_t size);

	void Draw(sf::RenderTarget & window);

private:
	const Map * m_mapToRender;
	uint16_t m_tileSize;
	float_t m_thickness;

	sf::FloatRect m_areaToRender;
	sf::CircleShape m_manipulator;

	std::vector< sf::Vector2f > m_positions;
};