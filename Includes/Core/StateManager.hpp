#ifndef HEADER_STATEMANAGER_HPP
#define HEADER_STATEMANAGER_HPP

#include <Core/State.hpp>
#include <memory>
#include <stack>

class StateManager
{
public:
    explicit StateManager();
    ~StateManager() = default;

    void pop();

    template <typename T, typename std::enable_if<std::is_base_of<State, T>::value>::type*>
    void push(GraphicsSettings& settings);

    void handleEvent();
    void handleUpdate();
    void handleDisplay();

    bool empty();

    State& currentState();

private:
    std::stack<std::shared_ptr<State>> m_states;
};

#include <Core/StateManager.inl>

#endif  // HEADER_STATEMANAGER_HPP
