#pragma once
#include "Map.hpp"
#include <SFML/Graphics.hpp>

class MapRenderer :
	public sf::Drawable
{
private:
	void draw(sf::RenderTarget & target, sf::RenderStates state) const;
	// If there was changes on map and need to be recalculated
	void update();

public:
	MapRenderer(const Map * mapToRender, uint16_t tileSize = 24);

	uint16_t GetTileSize();
	const Map & GetMap();

	void SetMap(const Map * mapToRender);
	void SetTileSize(uint16_t size);

private:
	const Map * m_mapToRender;
	uint16_t m_tileSize;

	std::vector< sf::CircleShape > m_tiles;
};