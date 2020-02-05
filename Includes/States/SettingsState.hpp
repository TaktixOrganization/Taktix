#ifndef HEADER_SETTINGSSTATE_HPP
#define HEADER_SETTINGSSTATE_HPP

#include <Core/State.hpp>
#include <TGUI/TGUI.hpp>

class SettingsState : public State
{
public:
    explicit SettingsState(StateManager& stateManager, GraphicsSettings& settings);

    void handleEvent() override;
    void handleUpdate() override;
    void handleDisplay() override;

    void initializeGui();

private:
    tgui::Gui m_gui;
};

#endif  // HEADER_SETTINGSSTATE_HPP