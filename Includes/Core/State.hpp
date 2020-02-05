#ifndef HEADER_STATE_HPP
#define HEADER_STATE_HPP

#include <Core/GraphicsSettings.hpp>
#include <TGUI/TGUI.hpp>

class StateManager;

class State
{
    friend class StateManager;

public:
    virtual void handleEvent() = 0;
    virtual void handleUpdate() = 0;
    virtual void handleDisplay() = 0;

    bool isRunning();

protected:
    explicit State(StateManager& stateManager, GraphicsSettings& settings);
    ~State() = default;

protected:
    StateManager& m_stateManager;
    GraphicsSettings& m_settings;

    sf::RenderWindow m_renderWindow;

    tgui::Gui m_gui;
};

#endif  // HEADER_STATE_HPP
