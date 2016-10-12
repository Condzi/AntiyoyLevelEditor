#include "PropertiesTab.hpp"

void PropertiesTab::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(m_background, state);

	if (m_cellPtr == nullptr)
	{
		target.draw(m_cellNotSelectedText);
		return;
	}

	target.draw(m_isAliveText, state);
	target.draw(m_ownerIdText, state);
	target.draw(m_difficultyText, state);
	target.draw(m_incomeText);

	target.draw(m_isAliveCheckbox, state);
	target.draw(m_ownerIdNumBox, state);
	target.draw(m_difficultyNumBox, state);
	target.draw(m_incomeNumBox, state);
}

void PropertiesTab::arrange()
{
	m_background.setPosition(m_positionX, m_positionY);

	m_cellNotSelectedText.setPosition(m_positionX + m_background.getGlobalBounds().width / 2 - m_cellNotSelectedText.getGlobalBounds().width / 2,
		m_positionY + m_background.getGlobalBounds().height / 2 - m_cellNotSelectedText.getGlobalBounds().height);

	m_isAliveCheckbox.SetPosition(m_positionX + 10, m_positionY + 10);
	m_isAliveText.setPosition(m_isAliveCheckbox.GetRectangleGlobalBounds().left + m_isAliveCheckbox.GetRectangleGlobalBounds().width + 10, m_isAliveCheckbox.GetRectangleGlobalBounds().top - m_isAliveText.getGlobalBounds().height / 4);

	m_ownerIdNumBox.SetPosition(m_isAliveCheckbox.GetRectangleGlobalBounds().left, m_isAliveCheckbox.GetRectangleGlobalBounds().top + m_isAliveCheckbox.GetRectangleGlobalBounds().height + 20);
	m_ownerIdText.setPosition(m_ownerIdNumBox.GetRectangleGlobalBounds().left + m_ownerIdNumBox.GetRectangleGlobalBounds().width + 10, m_ownerIdNumBox.GetRectangleGlobalBounds().top - m_ownerIdText.getGlobalBounds().height / 4);

	m_difficultyNumBox.SetPosition(m_ownerIdNumBox.GetRectangleGlobalBounds().left, m_ownerIdNumBox.GetRectangleGlobalBounds().top + m_ownerIdNumBox.GetRectangleGlobalBounds().height + 20);
	m_difficultyText.setPosition(m_difficultyNumBox.GetRectangleGlobalBounds().left + m_difficultyNumBox.GetRectangleGlobalBounds().width + 10, m_difficultyNumBox.GetRectangleGlobalBounds().top - m_difficultyText.getGlobalBounds().height / 4);

	m_incomeNumBox.SetPosition(m_difficultyNumBox.GetRectangleGlobalBounds().left, m_difficultyNumBox.GetRectangleGlobalBounds().top + m_difficultyNumBox.GetRectangleGlobalBounds().height + 20);
	m_incomeText.setPosition(m_incomeNumBox.GetRectangleGlobalBounds().left + m_incomeNumBox.GetRectangleGlobalBounds().width + 10, m_incomeNumBox.GetRectangleGlobalBounds().top - m_incomeText.getGlobalBounds().height / 4);

}

PropertiesTab::PropertiesTab(float_t posX, float_t posY)
{
	m_cellPtr = nullptr;
	m_positionX = posX;
	m_positionY = posY;

	m_bgColor = sf::Color(30, 30, 30);
	m_background.setFillColor(m_bgColor);
	m_background.setSize(sf::Vector2f(250, 170));

	if (!m_font.loadFromFile("rsrc/default.ttf"))
	{
		throw std::exception("Cannot load texture (rsrc/default.ttf) [PropertiesTab]");
	}
	m_textColor = sf::Color(241, 241, 241);

	m_isAliveText = sf::Text("Is Alive", m_font);
	m_ownerIdText = sf::Text("Owner ID", m_font);
	m_difficultyText = sf::Text("Difficulty", m_font);
	m_incomeText = sf::Text("Income", m_font);
	m_cellNotSelectedText = sf::Text("Nothing selected", m_font);

	m_isAliveText.setFillColor(m_textColor);
	m_ownerIdText.setFillColor(m_textColor);
	m_difficultyText.setFillColor(m_textColor);
	m_incomeText.setFillColor(m_textColor);
	m_cellNotSelectedText.setFillColor(m_textColor);

	m_isAliveSeleced = false;
	m_ownerIdSelected = false;
	m_difficultySelected = false;
	m_incomeSelected = false;

	arrange();
}

sf::FloatRect PropertiesTab::GetRectangleGlobalBounds(uint8_t id)
{
	if (id == 0)
		return m_isAliveCheckbox.GetRectangleGlobalBounds();
	else if (id == 1)
		return m_ownerIdNumBox.GetRectangleGlobalBounds();
	else if (id == 2)
		return m_difficultyNumBox.GetRectangleGlobalBounds();
	else if (id == 3)
		return m_incomeNumBox.GetRectangleGlobalBounds();
	else if (id == 4)
		return m_background.getGlobalBounds();

	return sf::FloatRect();
}

void PropertiesTab::SetCellPointer(Cell * cellPtr)
{
	m_cellPtr = cellPtr;

	m_ownerIdHolder = m_cellPtr->GetOwnerID();
	m_difficultyHolder = m_cellPtr->GetDifficulty();
	m_incomeHolder = m_cellPtr->GetIncome();

	m_isAliveCheckbox.SetState(m_cellPtr->GetIsAlive());
	m_ownerIdNumBox.SetVariableRefrence(m_ownerIdHolder);
	m_difficultyNumBox.SetVariableRefrence(m_difficultyHolder);
	m_incomeNumBox.SetVariableRefrence(m_incomeHolder);
}

void PropertiesTab::UnsetCellPointer()
{
	m_cellPtr = nullptr;
}

void PropertiesTab::SetActiveBox(uint8_t id)
{
	if (id == 0)
		m_isAliveSeleced = true;
	else if (id == 1)
		m_ownerIdSelected = true;
	else if (id == 2)
		m_difficultySelected = true;
	else if (id == 3)
		m_incomeSelected = true;
}

void PropertiesTab::SetPosition(float_t x, float_t y)
{
	m_positionX = x;
	m_positionY = y;
	arrange();
}

void PropertiesTab::Move(float_t x, float_t y)
{
	m_positionX += x;
	m_positionY += y;

	m_background.move(x, y);

	m_isAliveText.move(x, y);
	m_ownerIdText.move(x, y);
	m_difficultyText.move(x, y);
	m_incomeText.move(x, y);

	m_cellNotSelectedText.move(x, y);

	m_isAliveCheckbox.Move(x, y);
	m_ownerIdNumBox.Move(x, y);
	m_difficultyNumBox.Move(x, y);
	m_incomeNumBox.Move(x, y);
}
