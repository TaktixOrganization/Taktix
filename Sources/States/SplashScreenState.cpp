#include <Core/StateManager.hpp>
#include <States/SplashScreenState.hpp>
#include <iostream>

SplashScreenState::SplashScreenState(StateManager& stateManager)
    : State(stateManager)
{
    this->initializeGui();
}

void SplashScreenState::handleEvent(const sf::Event& event)
{
    m_gui.handleEvent(event);
}

void SplashScreenState::handleUpdate()
{
    int x = m_gui.get<tgui::Picture>("background")->getPosition().x;
    int y = m_gui.get<tgui::Picture>("background")->getPosition().y;

    if (y < 0.0f) {
        m_gui.get<tgui::Picture>("background")->setPosition(x, y + 1);
    }
}

void SplashScreenState::handleDisplay(sf::RenderWindow& renderWindow)
{
    m_gui.setTarget(renderWindow);
    m_gui.draw();
}

void SplashScreenState::initializeGui()
{
    m_gui.add(tgui::Picture::create("Assets/Textures/Parallaxs/splashscreen.jpg"), "background");

    sf::Vector2u windowSize = m_stateManager.getRenderWindow().getSize();
    sf::Vector2f pictureSize = m_gui.get<tgui::Picture>("background")->getSize();

    m_gui.get<tgui::Picture>("background")->setPosition(-std::abs(pictureSize.x - windowSize.x) / 2.0f, -std::abs(pictureSize.y - windowSize.y));
}
