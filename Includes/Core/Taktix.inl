#ifndef HEADER_TAKTIX_INL
#define HEADER_TAKTIX_INL

template <typename T>
void Taktix::run()
{
    m_stateManager.push<T>();

    while (m_renderWindow.isOpen() && !m_stateManager.empty()) {
        m_stateManager.handleEvent();
        m_stateManager.handleUpdate();
        m_stateManager.handleDisplay();
    }
}

#endif  // HEADER_TAKTIX_INL