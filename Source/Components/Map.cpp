#include "Map.hpp"

Map::Map(uint16_t width, uint16_t height)
{
	m_width = width;
	m_height = height;

	m_map.resize(m_width * m_height);
}

uint16_t Map::GetWidth()
{
	return m_width;
}

uint16_t Map::GetHeight()
{
	return m_height;
}

void Map::SetWidth(uint16_t width)
{
	Resize(width, m_height);
}

void Map::SetHeight(uint16_t height)
{
	Resize(m_width, height);
}

void Map::Resize(uint16_t width, uint16_t height)
{
	m_width = width;
	m_height = height;

	m_map.resize(m_width * m_height);
}

Cell & Map::operator[](uint16_t index)
{
	return m_map[index];
}
