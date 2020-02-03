#include <Core/Taktix.hpp>

Taktix::Taktix()
    : m_gui(m_renderWindow)
    , m_renderWindow(sf::VideoMode(640, 480), "Taktix")
    , m_currentMap("lake")
    , m_stateManager(m_renderWindow)
{
    m_renderWindow.setFramerateLimit(60);
    m_renderWindow.setVerticalSyncEnabled(false);
}
