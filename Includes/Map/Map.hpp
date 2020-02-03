#ifndef HEADER_MAP_HPP
#define HEADER_MAP_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>

class Map : public sf::Drawable, public sf::Transformable
{
public:
    explicit Map(const std::string& name);
    ~Map() = default;

private:
    void load(const std::string& filename);
    void build(const int* tiles);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::Vector2u m_tileSize;

    unsigned int m_mapWidth;
    unsigned int m_mapHeight;

    sf::Texture m_tileset;
    sf::VertexArray m_vertices;
};

#endif  // HEADER_MAP_HPP
