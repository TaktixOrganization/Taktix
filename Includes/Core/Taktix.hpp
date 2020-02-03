#ifndef HEADER_TAKTIX_HPP
#define HEADER_TAKTIX_HPP

#include <Core/StateManager.hpp>
#include <Map/Map.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <TGUI/Gui.hpp>

class Taktix
{
public:
    Taktix();
    ~Taktix() = default;

    template <typename T>
    void run();

private:
    tgui::Gui m_gui;

    sf::RenderWindow m_renderWindow;

    Map m_currentMap;
    StateManager m_stateManager;
};

#include "Taktix.inl"

#endif  // HEADER_TAKTIX_HPP