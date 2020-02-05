#include <Core/StateManager.hpp>
#include <SFML/Window/Event.hpp>

StateManager::StateManager() {}

void StateManager::pop()
{
    if (!m_states.empty()) {
        m_states.pop();
    }
}

void StateManager::handleEvent()
{
    this->currentState().handleEvent();
}

void StateManager::handleUpdate()
{
    this->currentState().handleUpdate();
}

void StateManager::handleDisplay()
{
    this->currentState().handleDisplay();
}

bool StateManager::empty()
{
    return m_states.empty();
}

State& StateManager::currentState()
{
    return *(m_states.top());
}