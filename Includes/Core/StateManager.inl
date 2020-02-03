#ifndef HEADER_STATEMANAGER_INL
#define HEADER_STATEMANAGER_INL

template <typename T>
void StateManager::push()
{
    std::shared_ptr<State> state(new T(*this));

    m_states.push(state);
}

#endif  // HEADER_STATEMANAGER_INL