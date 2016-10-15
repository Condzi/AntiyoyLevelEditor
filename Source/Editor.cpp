#include "Editor.hpp"

void Editor::draw()
{
	m_window.clear(sf::Color(27, 27, 27));

	m_mapRenderer->Draw(m_window);
	m_window.draw(m_propertiesTab);
	m_window.draw(m_colorTab);
	m_window.draw(m_toolTab);
	m_window.draw(m_cursorSprite);

	m_window.display();
}

void Editor::handleEvents(sf::Event & event)
{
	m_mousePositionPrevious = m_mousePositionCurrent;
	m_mousePositionCurrent = sf::Mouse::getPosition(m_window);
	m_mousePositionCurrent = (sf::Vector2i)m_window.mapPixelToCoords(m_mousePositionCurrent);

	if (event.type == sf::Event::Closed)
	{
		m_window.close();
	}
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (m_propertiesTab.GetRectangleGlobalBounds(4).contains((sf::Vector2f)m_mousePositionCurrent))
		{
			m_propertiesTab.Move(m_mousePositionCurrent.x - m_mousePositionPrevious.x, m_mousePositionCurrent.y - m_mousePositionPrevious.y);
		}

		if (m_colorTab.GetRectangleGlobalBounds(16).contains((sf::Vector2f)m_mousePositionCurrent))
		{
			m_colorTab.Move(m_mousePositionCurrent.x - m_mousePositionPrevious.x, m_mousePositionCurrent.y - m_mousePositionPrevious.y);
		}

		if (m_toolTab.GetRectangleGlobalBounds(2).contains((sf::Vector2f)m_mousePositionCurrent))
		{
			m_toolTab.Move(m_mousePositionCurrent.x - m_mousePositionPrevious.x, m_mousePositionCurrent.y - m_mousePositionPrevious.y);
		}

		if (m_mousePositionCurrent.x < m_mapRenderer->GetMap().GetWidth() &&
			m_mousePositionCurrent.y < m_mapRenderer->GetMap().GetHeight())
		{
			Cell * cell = &m_editMap->operator[]((m_mousePositionCurrent.y * m_mapRenderer->GetTileSize()) * m_editMap->GetWidth() + m_mousePositionCurrent.y);
			
			m_propertiesTab.SetCellPointer(cell);
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
	{
		m_mapView.move((m_mousePositionCurrent.x - m_mousePositionPrevious.x) / 3, (m_mousePositionCurrent.y - m_mousePositionPrevious.y) / 3);
		m_window.setView(m_mapView);

		m_propertiesTab.Move((m_mousePositionCurrent.x - m_mousePositionPrevious.x) / 3, (m_mousePositionCurrent.y - m_mousePositionPrevious.y) / 3);
		m_colorTab.Move((m_mousePositionCurrent.x - m_mousePositionPrevious.x) / 3, (m_mousePositionCurrent.y - m_mousePositionPrevious.y) / 3);
		m_toolTab.Move((m_mousePositionCurrent.x - m_mousePositionPrevious.x) / 3, (m_mousePositionCurrent.y - m_mousePositionPrevious.y) / 3);
		m_mapRenderer->MoveAreaToRender((m_mousePositionCurrent.x - m_mousePositionPrevious.x) / 3, (m_mousePositionCurrent.y - m_mousePositionPrevious.y) / 3);
	}

	if (event.type == sf::Event::MouseWheelMoved)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl))
		{
			float zoom = 1 + event.mouseWheel.delta;
			m_mapView.zoom(zoom);
			m_window.setView(m_mapView);
		}
	}
}

Editor::Editor(Map * mapToWork)
{
	m_mapToWork = mapToWork;
	m_editMap = new Map(*m_mapToWork);

	m_mapRenderer = new MapRenderer(m_editMap);

	m_window.create(sf::VideoMode(1280, 720), "Antiyoy Clone Level Editor", sf::Style::Close);
	m_window.setFramerateLimit(60);
	m_mapView = m_window.getDefaultView();
	m_window.setView(m_mapView);

	if (!m_cursorTexture.loadFromFile("rsrc/cursor.png"))
	{
		throw std::exception("cannot load cursor texture, fk, I should not be called...");
	}

	m_cursorSprite.setTexture(m_cursorTexture);

	m_mousePositionCurrent = sf::Vector2i(0, 0);
}

void Editor::Run()
{
	sf::Event event;

	while (m_window.isOpen())
	{
		while (m_window.pollEvent(event))
		{
			handleEvents(event);
		}

		draw();
	}
}
