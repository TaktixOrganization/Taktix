#ifndef HEADER_STATEMANAGER_HPP
#define HEADER_STATEMANAGER_HPP

#include <Core/State.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <stack>

class StateManager
{
public:
    explicit StateManager(sf::RenderWindow& renderWindow);
    ~StateManager() = default;

    void pop();

    template <typename T, typename std::enable_if<std::is_base_of<State, T>::value>::type*>
    void push();

    void handleEvent();
    void handleUpdate();
    void handleDisplay();

    bool empty();

    State& currentState();

private:
    sf::RenderWindow& m_renderWindow;

    std::stack<std::shared_ptr<State>> m_states;
};

#include <Core/StateManager.inl>

#endif  // HEADER_STATEMANAGER_HPP