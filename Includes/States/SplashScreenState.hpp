#ifndef HEADER_SPLASHSCREENSTATE_HPP
#define HEADER_SPLASHSCREENSTATE_HPP

#include <Core/State.hpp>
#include <TGUI/TGUI.hpp>

class SplashScreenState final : public State
{
public:
    explicit SplashScreenState(StateManager& stateManager, GraphicsSettings& settings);

    void handleEvent() override;
    void handleUpdate() override;
    void handleDisplay() override;

    void initializeGui();

private:
    tgui::Gui m_gui;
};

#endif  // HEADER_SPLASHSCREENSTATE_HPP
