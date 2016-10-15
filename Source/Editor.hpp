#pragma once
#include "Components/MapRenderer.hpp"

#include "UI/PropertiesTab.hpp"
#include "UI/ColorTab.hpp"
#include "UI/ToolTab.hpp"

#include <thread>

class Editor
{
private:
	void draw();
	void handleEvents(sf::Event & event);

public:
	Editor(Map * mapToWork);

	void Run();

private:
	const Map * m_mapToWork;
	Map * m_editMap;
	MapRenderer * m_mapRenderer;

	PropertiesTab m_propertiesTab;
	ColorTab m_colorTab;
	ToolTab m_toolTab;

	sf::RenderWindow m_window;
	sf::View m_mapView;

	sf::Texture m_cursorTexture;
	sf::Sprite m_cursorSprite;

	sf::Vector2i m_mousePositionCurrent;
	sf::Vector2i m_mousePositionPrevious;
};