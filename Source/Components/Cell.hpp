#pragma once
#include <cstdint>

// Logic part of hexagon representation on the map
// (no render here)
class Cell
{
public:
	Cell();

	bool GetIsAlive();
	uint8_t GetOwnerID();
	uint8_t GetDifficulty();
	uint16_t GetIncome();

	void SetIsAlive(bool isAlive);
	void SetOwnerID(uint8_t ownerID);
	void SetDifficulty(uint8_t difficulty);
	void SetIncome(uint16_t income);

private:
	// Is alive or dead? [active / unactive]
	bool m_isAlive;
	// Probably there won't be more than 255 players [owners]
	// So we don't need bigger variable
	uint8_t m_ownerID;
	// How hard is to take cell
	uint8_t m_difficulty;
	// How many income generates per round
	uint16_t m_income;

};