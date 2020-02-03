#include <Core/StateManager.hpp>
#include <States/SecondState.hpp>
#include <iostream>

SecondState::SecondState(StateManager& stateManager)
    : State(stateManager)
{
    tgui::Button::Ptr button = tgui::Button::create("Super button");
    button->setSize(200, 80);
    button->setPosition(100, 100);
    button->connect("pressed", &SecondState::popAndGoBack, this);
    m_gui.add(button);
}

void SecondState::handleEvent(const sf::Event& event)
{
    m_gui.handleEvent(event);
}

void SecondState::handleUpdate() {}

void SecondState::handleDisplay(sf::RenderWindow& renderWindow)
{
    renderWindow.clear(sf::Color::Green);

    m_gui.setTarget(renderWindow);
    m_gui.draw();
}

void SecondState::popAndGoBack()
{
    std::cout << "Going back to first state !" << std::endl;
    m_stateManager.pop();
}
