#include <Core/Taktix.hpp>
#include <cstdlib>
#include <fstream>

Taktix::Taktix(GraphicsSettings settings)
    : m_gui(m_renderWindow)
    , m_renderWindow(settings.getVideoMode(), settings.getTitle(), settings.getStyle(), settings.getContextSettings())
    , m_currentMap("lake")
    , m_stateManager(m_renderWindow)
{
    m_renderWindow.setFramerateLimit(settings.getFps());
    m_renderWindow.setVerticalSyncEnabled(settings.hasVerticalSync());
}

Taktix* Taktix::instance()
{
    GraphicsSettings settings;
    settings.deserialize("Assets/settings.txt");

    static Taktix instance(settings);

    return &instance;
}
