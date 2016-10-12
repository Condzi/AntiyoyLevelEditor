#include <string>
#include "Textbox.hpp"
#include "Checkbox.hpp"
#include "../Components/Cell.hpp"


// Properties Tab
// Using pointer to Cell (if nullptr - tab is not displaying anything) 
// Probably unneeded m_bgColor
class PropertiesTab :
	public sf::Drawable
{
	void draw(sf::RenderTarget & target, sf::RenderStates state) const;
	void arrange();

public:
	PropertiesTab(float_t posX, float_t posY);

	// 0 - isAlive 
	// 1 - ownerId
	// 2 - difficulty
	// 3 - income
	// 4 - background
	sf::FloatRect GetRectangleGlobalBounds(uint8_t id);

	void SetCellPointer(Cell * cellPtr);
	void UnsetCellPointer();

	// set active NumBox (only 1 can be active for a moment)
	// 0 - isAlive (if selected - it toggle, then auto-unselected)
	// 1 - ownerId
	// 2 - difficulty
	// 3 - income
	void SetActiveBox(uint8_t id);
	void SetPosition(float_t x, float_t y);

	void Move(float_t x, float_t y);

private:
	Cell * m_cellPtr;
	float_t m_positionX;
	float_t m_positionY;

	sf::RectangleShape m_background;
	// 30,30,30,250
	sf::Color m_bgColor;

	// rsrc/default.ttf
	sf::Font m_font;
	// 241,241,241
	sf::Color m_textColor;

	// Texts that are displayed above settings

	sf::Text m_isAliveText;
	sf::Text m_ownerIdText;
	sf::Text m_difficultyText;
	sf::Text m_incomeText;

	sf::Text m_cellNotSelectedText;

	// Settings

	Checkbox m_isAliveCheckbox;
	NumBox m_ownerIdNumBox;
	NumBox m_difficultyNumBox;
	NumBox m_incomeNumBox;

	// What settings are selected (1 / moment)

	bool m_isAliveSeleced;
	bool m_ownerIdSelected;
	bool m_difficultySelected;
	bool m_incomeSelected;

	int64_t m_ownerIdHolder;
	int64_t m_difficultyHolder;
	int64_t m_incomeHolder;
};