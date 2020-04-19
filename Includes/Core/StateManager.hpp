#ifndef HEADER_STATEMANAGER_HPP
#define HEADER_STATEMANAGER_HPP

#include <Core/State.hpp>
#include <memory>
#include <stack>
#include <type_traits>

class StateManager
{
public:
    explicit StateManager();
    ~StateManager() = default;

    void pop();

    template <typename T>
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
