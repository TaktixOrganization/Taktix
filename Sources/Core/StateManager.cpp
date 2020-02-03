#include <Core/StateManager.hpp>
#include <SFML/Window/Event.hpp>

StateManager::StateManager(sf::RenderWindow& renderWindow)
    : m_renderWindow(renderWindow)
{
}

void StateManager::pop()
{
    if (!m_states.empty()) {
        m_states.pop();
    }
}

void StateManager::handleEvent()
{
    sf::Event event;

    while (m_renderWindow.pollEvent(event)) {
        this->currentState().handleEvent(event);

        switch (event.type) {
            case sf::Event::Closed:
                m_renderWindow.close();
                break;
            default:
                break;
        }
    }
}

void StateManager::handleUpdate()
{
    this->currentState().handleUpdate();
}

void StateManager::handleDisplay()
{
    m_renderWindow.clear();

    this->currentState().handleDisplay(m_renderWindow);

    m_renderWindow.display();
}

bool StateManager::empty()
{
    return m_states.empty();
}

State& StateManager::currentState()
{
    return *(m_states.top());
}
