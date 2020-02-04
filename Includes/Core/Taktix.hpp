#ifndef HEADER_TAKTIX_HPP
#define HEADER_TAKTIX_HPP

#include <Core/StateManager.hpp>
#include <Map/Map.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <TGUI/Gui.hpp>

struct WindowSettings
{
    int _width;
    int _height;
    sf::Uint32 _style;
};

class Taktix
{
public:
    ~Taktix() = default;

    template <typename T, typename std::enable_if<std::is_base_of<State, T>::value>::type*>
    void run();

    static Taktix* instance();

private:
    Taktix(sf::VideoMode videoMode, const std::string& title, sf::Uint32 style);
    Taktix(const Taktix&) = delete;
    Taktix& operator=(const Taktix&) = delete;

    static WindowSettings loadSettings(const std::string& filename);

private:
    tgui::Gui m_gui;

    sf::RenderWindow m_renderWindow;

    Map m_currentMap;
    StateManager m_stateManager;
};

#include <Core/Taktix.inl>

#endif  // HEADER_TAKTIX_HPP
