#pragma once
#include "Cell.hpp"
#include <vector>

// Cell container
// To get cell use []:
// Map z(10,10); z[x * z.GetWidth() + y]; 
class Map
{
public:
	Map(uint16_t width, uint16_t height);

	uint16_t GetWidth() const;
	uint16_t GetHeight() const;

	void SetWidth(uint16_t width);
	void SetHeight(uint16_t height);
	void Resize(uint16_t width, uint16_t height);

	// Usage:
	// Map::operator[y * Map::GetWidth() + x]
	Cell & operator[](uint32_t index);

	// To Do
	// bool SaveToXML(const std::string & filename);

private:
	// Allocated memory for map
	// m_map[width * height]
	// usage: m_map[x * width + y]
	std::vector< Cell > m_map;

	uint16_t m_width;
	uint16_t m_height;

	Cell m_templateCell;
};