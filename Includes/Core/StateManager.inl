#ifndef HEADER_STATEMANAGER_INL
#define HEADER_STATEMANAGER_INL

template <typename T, typename std::enable_if<std::is_base_of<State, T>::value>::type* = nullptr>
void StateManager::push(GraphicsSettings& settings)
{
    std::shared_ptr<State> state(new T(*this, settings));

    m_states.push(state);
}

#endif  // HEADER_STATEMANAGER_INL
