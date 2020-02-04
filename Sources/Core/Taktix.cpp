#include <Core/Taktix.hpp>
#include <cstdlib>
#include <fstream>

Taktix::Taktix(sf::VideoMode videoMode, const std::string& title, sf::Uint32 style)
    : m_gui(m_renderWindow)
    , m_renderWindow(videoMode, title, style)
    , m_currentMap("lake")
    , m_stateManager(m_renderWindow)
{
    m_renderWindow.setFramerateLimit(60);
    m_renderWindow.setVerticalSyncEnabled(false);
}

Taktix* Taktix::instance()
{
    auto settings = Taktix::loadSettings("Assets/settings.txt");

    static Taktix instance(sf::VideoMode(settings._width, settings._height), "Taktix", settings._style);

    return &instance;
}

WindowSettings Taktix::loadSettings(const std::string& filename)
{
    std::string line;
    std::ifstream file(filename);

    WindowSettings settings;

    std::getline(file, line);  // Window width
    settings._width = std::atoi(line.c_str());
    std::getline(file, line);  // Window height
    settings._height = std::atoi(line.c_str());
    std::getline(file, line);  // Window style
    settings._style = std::atoi(line.c_str());

    return settings;
}
