#include "MapRenderer.hpp"


MapRenderer::MapRenderer(const Map * mapToRender, uint16_t tileSize, float_t thickness)
{
	m_mapToRender = mapToRender;
	m_tileSize = tileSize;
	m_thickness = thickness;
	m_areaToRender = sf::FloatRect(0, 0, 1280, 720);
	
	m_manipulator.setFillColor(sf::Color::Red);
	m_manipulator.setOutlineColor(sf::Color::Blue);
	m_manipulator.setOutlineThickness(m_thickness);
	m_manipulator.rotate(90);
	m_manipulator.setRadius(m_tileSize / 2);
	m_manipulator.setPointCount(6);
	
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

void MapRenderer::SetAreaToRender(const sf::FloatRect & area)
{
	m_areaToRender = area;
}

void MapRenderer::MoveAreaToRender(float_t x, float_t y)
{
	m_areaToRender.left += x;
	m_areaToRender.top += y;
	m_areaToRender.width += x;
	m_areaToRender.height += y;
}

void MapRenderer::SetTileSize(uint16_t size)
{
	m_tileSize = size;
	update();
}

void MapRenderer::Draw(sf::RenderTarget & window)
{
	uint32_t posXbegin = abs(m_areaToRender.left) / m_tileSize;
	uint32_t posYbegin = abs(m_areaToRender.top) / m_tileSize;
	uint32_t indexBegin = posYbegin * m_mapToRender->GetWidth() + posXbegin;

	uint32_t posXend = abs(m_areaToRender.left + m_areaToRender.width) / m_tileSize;
	uint32_t posYend = abs(m_areaToRender.top + m_areaToRender.height) / m_tileSize;
	uint32_t index = 0;

	for (uint32_t y = 0; y < posYend; ++y)
	{
		for (uint32_t x = 0; x < posXend; ++x)
		{
			index = indexBegin + y * m_mapToRender->GetWidth() + x;
			m_manipulator.setPosition(m_positions[index]);
			window.draw(m_manipulator);
		}
	}
}

void MapRenderer::update()
{
	sf::Vector2f templateVector(0, 0);

	m_positions.clear();

	for (uint32_t y = 0; y < m_mapToRender->GetHeight(); ++y)
	{
		for (uint32_t x = 0; x < m_mapToRender->GetWidth(); ++x)
		{
			if (x % 2)
			{
				templateVector = sf::Vector2f(x * (m_manipulator.getGlobalBounds().width * 0.75f) + m_tileSize, y * (m_manipulator.getGlobalBounds().height) + m_tileSize / 2.5f);
			}
			else
			{
				templateVector = sf::Vector2f(x * (m_manipulator.getGlobalBounds().width * 0.75f) + m_tileSize, y * (m_manipulator.getGlobalBounds().height) - (m_manipulator.getGlobalBounds().height * 0.5f) + m_tileSize / 2.5f);
			}

			m_positions.push_back(templateVector);
		}
	}
}
