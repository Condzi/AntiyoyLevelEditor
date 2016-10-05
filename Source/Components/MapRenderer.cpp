#include "MapRenderer.hpp"

void MapRenderer::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	for (const sf::CircleShape & cs : m_tiles)
	{
		target.draw(cs, state);
	}
}

MapRenderer::MapRenderer(const Map * mapToRender, uint16_t tileSize)
{
	m_mapToRender = mapToRender;
	m_tileSize = tileSize;
	update();
}

uint16_t MapRenderer::GetTileSize()
{
	return m_tileSize;
}

const Map & MapRenderer::GetMap()
{
	return *m_mapToRender;
}

void MapRenderer::SetMap(const Map * mapToRender)
{
	m_mapToRender = mapToRender;
	update();
}

void MapRenderer::SetTileSize(uint16_t size)
{
	m_tileSize = size;
	update();
}

void MapRenderer::update()
{
	sf::CircleShape templateCircle;
	templateCircle.setFillColor(sf::Color::Red);
	templateCircle.setOutlineColor(sf::Color::Blue);
	templateCircle.setOutlineThickness(1.f);
	templateCircle.rotate(90);
	templateCircle.setRadius(m_tileSize / 1.6f);
	templateCircle.setPointCount(6);

	m_tiles.clear();
	m_tiles.resize(m_mapToRender->GetWidth() * m_mapToRender->GetHeight());

	for (uint16_t y = 0; y < m_mapToRender->GetHeight(); ++y)
	{
		for (uint16_t x = 0; x < m_mapToRender->GetWidth(); ++x)
		{
			if (x % 2)
			{
				templateCircle.setPosition(x * m_tileSize + m_tileSize * 1.25f, (y * m_tileSize - m_tileSize / 2) + m_tileSize);
			}
			else
			{
				templateCircle.setPosition(x * m_tileSize  + m_tileSize * 1.25f, (y * m_tileSize - m_tileSize) + m_tileSize);
			}

			m_tiles.push_back(templateCircle);
		}
	}
}
