#ifndef HEADER_FIRSTSTATE_HPP
#define HEADER_FIRSTSTATE_HPP

#include <Core/State.hpp>
#include <TGUI/TGUI.hpp>

class FirstState : public State
{
public:
    explicit FirstState(StateManager& stateManager);

    void handleEvent(const sf::Event& event) override;
    void handleUpdate() override;
    void handleDisplay(sf::RenderWindow& renderWindow) override;

private:
    void goToSecondState();

private:
    tgui::Gui m_gui;
};

#endif  // HEADER_FIRSTSTATE_HPP