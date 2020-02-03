#ifndef HEADER_TAKTIX_HPP
#define HEADER_TAKTIX_HPP

#include <Core/StateManager.hpp>
#include <Map/Map.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <TGUI/Gui.hpp>

class Taktix
{
public:
    ~Taktix() = default;

    template <typename T, typename std::enable_if<std::is_base_of<State, T>::value>::type*>
    void run();

    static Taktix* instance();

private:
    Taktix();
    Taktix(const Taktix&) = delete;
    Taktix& operator=(const Taktix&) = delete;

private:
    tgui::Gui m_gui;

    sf::RenderWindow m_renderWindow;

    Map m_currentMap;
    StateManager m_stateManager;
};

#include <Core/Taktix.inl>

#endif  // HEADER_TAKTIX_HPP