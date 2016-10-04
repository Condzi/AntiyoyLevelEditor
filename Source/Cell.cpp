#include "Cell.hpp"

Cell::Cell()
{
	m_isAlive = false;
	m_ownerID = 0;
	m_difficulty = 0;
	m_income = 0;
}

bool Cell::GetIsAlive()
{
	return m_isAlive;
}

uint8_t Cell::GetOwnerID()
{
	return m_ownerID;
}

uint8_t Cell::GetDifficulty()
{
	return m_difficulty;
}

uint16_t Cell::GetIncome()
{
	return m_income;
}

void Cell::SetIsAlive(bool isAlive)
{
	m_isAlive = isAlive;
}

void Cell::SetOwnerID(uint8_t ownerID)
{
	m_ownerID = ownerID;
}

void Cell::SetDifficulty(uint8_t difficulty)
{
	m_difficulty = difficulty;
}

void Cell::SetIncome(uint16_t income)
{
	m_income = income;
}
