#ifndef HEADER_STATE_HPP
#define HEADER_STATE_HPP

#include <SFML/Graphics/RenderWindow.hpp>

class StateManager;

class State
{
    friend class StateManager;

public:
    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void handleUpdate() = 0;
    virtual void handleDisplay(sf::RenderWindow& renderWindow) = 0;

protected:
    explicit State(StateManager& stateManager);
    ~State() = default;

protected:
    StateManager& m_stateManager;
};

#endif  // HEADER_STATE_HPP
