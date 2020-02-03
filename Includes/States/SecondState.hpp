#ifndef HEADER_SECONDSTATE_HPP
#define HEADER_SECONDSTATE_HPP

#include <Core/State.hpp>
#include <TGUI/TGUI.hpp>

class SecondState final : public State
{
public:
    explicit SecondState(StateManager& stateManager);

    void handleEvent(const sf::Event& event) override;
    void handleUpdate() override;
    void handleDisplay(sf::RenderWindow& renderWindow) override;

private:
    void popAndGoBack();

private:
    tgui::Gui m_gui;
};

#endif  // HEADER_SECONDSTATE_HPP