#include <Core/State.hpp>

State::State(StateManager& stateManager, GraphicsSettings& settings)
    : m_stateManager(stateManager)
    , m_settings(settings)
    , m_renderWindow(settings.getVideoMode(), settings.getTitle(), settings.getStyle(), settings.getContextSettings())
    , m_gui(m_renderWindow)
{
    m_renderWindow.setFramerateLimit(m_settings.getFps());
    m_renderWindow.setVerticalSyncEnabled(m_settings.hasVerticalSync());
}

bool State::isRunning()
{
    return m_renderWindow.isOpen();
}