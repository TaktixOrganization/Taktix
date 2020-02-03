#include <Core/StateManager.hpp>
#include <States/FirstState.hpp>
#include <States/SecondState.hpp>
#include <iostream>

FirstState::FirstState(StateManager& stateManager)
    : State(stateManager)
{
    tgui::Button::Ptr button = tgui::Button::create("Access second state !");
    button->setSize(480, 200);
    button->setPosition(100, 100);
    button->connect("pressed", &FirstState::goToSecondState, this);
    m_gui.add(button);
}

void FirstState::handleEvent(const sf::Event& event)
{
    m_gui.handleEvent(event);
}

void FirstState::handleUpdate() {}

void FirstState::handleDisplay(sf::RenderWindow& renderWindow)
{
    m_gui.setTarget(renderWindow);
    m_gui.draw();
}

void FirstState::goToSecondState()
{
    std::cout << "Going to second state !" << std::endl;
    m_stateManager.push<SecondState>();
}
