#include <Core/StateManager.hpp>
#include <States/SplashScreenState.hpp>
#include <iostream>

SplashScreenState::SplashScreenState(StateManager& stateManager, GraphicsSettings& settings)
    : State(stateManager, settings)
{
    this->initializeGui();
}

void SplashScreenState::handleEvent()
{
    sf::Event event;

    while (m_renderWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                m_renderWindow.close();
                break;
            default:
                break;
        }
    }

    m_gui.handleEvent(event);
}

void SplashScreenState::handleUpdate()
{
    int x = m_gui.get<tgui::Picture>("background")->getPosition().x;
    int y = m_gui.get<tgui::Picture>("background")->getPosition().y;

    if (y == -600.0f) {
        m_gui.get<tgui::Button>("btnNew")->setVisible(true);
    }
    else if (y == -550.0f) {
        m_gui.get<tgui::Button>("btnLoad")->setVisible(true);
    }
    else if (y == -500.0f) {
        m_gui.get<tgui::Button>("btnExit")->setVisible(true);
    }

    if (y < 0.0f) {
        m_gui.get<tgui::Picture>("background")->setPosition(x, y + 1);
    }
}

void SplashScreenState::handleDisplay()
{
    m_renderWindow.clear();
    m_gui.draw();
    m_renderWindow.display();
}

void SplashScreenState::initializeGui()
{
    m_gui.setTarget(m_renderWindow);

    m_gui.add(tgui::Picture::create("Assets/Textures/Parallaxs/splashscreen.jpg"), "background");

    sf::Vector2u windowSize = m_renderWindow.getSize();
    sf::Vector2f pictureSize = m_gui.get<tgui::Picture>("background")->getSize();

    m_gui.get<tgui::Picture>("background")->setPosition(-std::abs(pictureSize.x - windowSize.x) / 2.0f, -std::abs(pictureSize.y - windowSize.y));

    m_gui.add(tgui::Button::create("New"), "btnNew");
    m_gui.add(tgui::Button::create("Load"), "btnLoad");
    m_gui.add(tgui::Button::create("Exit"), "btnExit");

    sf::Vector2f buttonSize(150.0f, 75.0f);
    m_gui.get<tgui::Button>("btnNew")->setSize(buttonSize);
    m_gui.get<tgui::Button>("btnLoad")->setSize(buttonSize);
    m_gui.get<tgui::Button>("btnExit")->setSize(buttonSize);

    m_gui.get<tgui::Button>("btnLoad")->setPosition((windowSize.x - buttonSize.x) / 2.0f, 500.0f);
    sf::Vector2f buttonPosition = m_gui.get<tgui::Button>("btnLoad")->getPosition();
    m_gui.get<tgui::Button>("btnExit")->setPosition(buttonPosition.x + 1.5f * buttonSize.x, 500.0f);
    m_gui.get<tgui::Button>("btnNew")->setPosition(buttonPosition.x - 1.5f * buttonSize.x, 500.0f);

    m_gui.get<tgui::Button>("btnNew")->setVisible(false);
    m_gui.get<tgui::Button>("btnLoad")->setVisible(false);
    m_gui.get<tgui::Button>("btnExit")->setVisible(false);
}
