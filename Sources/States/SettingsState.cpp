#include <Core/StateManager.hpp>
#include <States/SettingsState.hpp>
#include <iostream>

SettingsState::SettingsState(StateManager& stateManager, GraphicsSettings& settings)
    : State(stateManager, settings)
{
    this->initializeGui();
}

void SettingsState::handleEvent()
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

void SettingsState::handleUpdate() {}

void SettingsState::handleDisplay()
{
    m_renderWindow.clear();
    m_gui.draw();
    m_renderWindow.display();
}

void SettingsState::initializeGui() {}
