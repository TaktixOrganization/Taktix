#ifndef HEADER_GRAPHICSSETTINGS_HPP
#define HEADER_GRAPHICSSETTINGS_HPP

#include <SFML/Graphics.hpp>

class GraphicsSettings
{
public:
    GraphicsSettings();
    ~GraphicsSettings() = default;

    void serialize(const std::string& filePath);
    void deserialize(const std::string& filePath);

    bool hasFullscreen() const;
    bool hasVerticalSync() const;

    unsigned int getFps() const;

    sf::Uint32 getStyle() const;

    const std::string& getTitle() const;

    const sf::VideoMode& getVideoMode() const;
    const sf::ContextSettings& getContextSettings() const;

private:
    bool m_fullscreen;
    bool m_verticalSync;

    unsigned int m_fps;

    std::string m_title;

    sf::VideoMode m_videoMode;
    sf::ContextSettings m_contextSettings;
};

#endif  // HEADER_GRAPHICSSETTINGS_HPP