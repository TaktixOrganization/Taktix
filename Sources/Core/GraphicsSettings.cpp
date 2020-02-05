#include <Core/GraphicsSettings.hpp>
#include <fstream>

GraphicsSettings::GraphicsSettings()
    : m_fullscreen(true)
    , m_verticalSync(false)
    , m_fps(120)
    , m_title("Undefined")
    , m_videoMode(sf::VideoMode::getDesktopMode())
{
    m_contextSettings.antialiasingLevel = 0;
}

void GraphicsSettings::serialize(const std::string& filePath)
{
    std::ofstream file(filePath);

    if (file.is_open()) {
        file << m_title;
        file << m_videoMode.width << " " << m_videoMode.height;
        file << m_fullscreen;
        file << m_fps;
        file << m_verticalSync;
        file << m_contextSettings.antialiasingLevel;
    }

    file.close();
}

void GraphicsSettings::deserialize(const std::string& filePath)
{
    std::ifstream file(filePath);

    if (file.is_open()) {
        std::getline(file, m_title);
        file >> m_videoMode.width >> m_videoMode.height;
        file >> m_fullscreen;
        file >> m_fps;
        file >> m_verticalSync;
        file >> m_contextSettings.antialiasingLevel;
    }

    file.close();
}

bool GraphicsSettings::hasFullscreen() const
{
    return m_fullscreen;
}

bool GraphicsSettings::hasVerticalSync() const
{
    return m_verticalSync;
}

unsigned int GraphicsSettings::getFps() const
{
    return m_fps;
}

sf::Uint32 GraphicsSettings::getStyle() const
{
    if (m_fullscreen) {
        return sf::Style::Fullscreen;
    }
    else {
        return sf::Style::Default;
    }
}

const std::string& GraphicsSettings::getTitle() const
{
    return m_title;
}

const sf::VideoMode& GraphicsSettings::getVideoMode() const
{
    return m_videoMode;
}

const sf::ContextSettings& GraphicsSettings::getContextSettings() const
{
    return m_contextSettings;
}
