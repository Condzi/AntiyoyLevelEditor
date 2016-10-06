#include "MapRenderer.hpp"

void MapRenderer::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	for (const sf::CircleShape & cs : m_tiles)
	{
		target.draw(cs, state);
	}
}

MapRenderer::MapRenderer(const Map * mapToRender, uint16_t tileSize, float_t thickness)
{
	m_mapToRender = mapToRender;
	m_tileSize = tileSize;
	m_thickness = thickness;
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
	templateCircle.setOutlineThickness(m_thickness);
	templateCircle.rotate(90);
	templateCircle.setRadius(m_tileSize / 2);
	templateCircle.setPointCount(6);

	m_tiles.clear();
	m_tiles.resize(m_mapToRender->GetWidth() * m_mapToRender->GetHeight());

	for (uint16_t y = 0; y < m_mapToRender->GetHeight(); ++y)
	{
		for (uint16_t x = 0; x < m_mapToRender->GetWidth(); ++x)
		{
			if (x % 2)
			{
				templateCircle.setPosition(x * (templateCircle.getGlobalBounds().width * 0.75f) + m_tileSize, y * (templateCircle.getGlobalBounds().height) + m_tileSize / 2.5f);
			}
			else
			{
				templateCircle.setPosition(x * (templateCircle.getGlobalBounds().width * 0.75f) + m_tileSize, y * (templateCircle.getGlobalBounds().height) - (templateCircle.getGlobalBounds().height * 0.5f) + m_tileSize / 2.5f);
			}

			m_tiles.push_back(templateCircle);
		}
	}
}
