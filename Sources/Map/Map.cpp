#include <Map/Map.hpp>
#include <cstdlib>
#include <fstream>
#include <iostream>

Map::Map(const std::string& name)
{
    this->load("Assets/Maps/" + name + ".map");
}

void Map::load(const std::string& filename)
{
    std::string line;
    std::ifstream file(filename);

    std::getline(file, line);  // Map width
    m_mapWidth = std::atoi(line.c_str());
    std::getline(file, line);  // Map height
    m_mapHeight = std::atoi(line.c_str());
    std::getline(file, line);  // Tile width
    m_tileSize.x = std::atoi(line.c_str());
    std::getline(file, line);  // Tile height
    m_tileSize.y = std::atoi(line.c_str());

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(m_mapWidth * m_mapHeight * 4);

    std::getline(file, line);  // Tileset filename (without path)
    std::string tilesetPath = "Assets/Textures/Tilesets/" + line;
    m_tileset.loadFromFile(tilesetPath);

    int* tiles = new int[m_mapWidth * m_mapHeight];
    for (int i = 0; i < m_mapWidth * m_mapHeight; ++i) {
        std::getline(file, line, ',');  // Tile number
        tiles[i] = std::atoi(line.c_str());
    }

    this->build(tiles);
    delete[] tiles;
}

void Map::build(const int* tiles)
{
    for (unsigned int i = 0; i < m_mapWidth; ++i) {
        for (unsigned int j = 0; j < m_mapHeight; ++j) {
            int tileNumber = tiles[i + j * m_mapWidth];

            int tu = tileNumber % (m_tileset.getSize().x / m_tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / m_tileSize.x);

            sf::Vertex* quad = &m_vertices[(i + j * m_mapWidth) * 4];

            quad[0].position = sf::Vector2f(i * m_tileSize.x, j * m_tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * m_tileSize.x, j * m_tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * m_tileSize.x, (j + 1) * m_tileSize.y);
            quad[3].position = sf::Vector2f(i * m_tileSize.x, (j + 1) * m_tileSize.y);

            quad[0].texCoords = sf::Vector2f(tu * m_tileSize.x, tv * m_tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, tv * m_tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, (tv + 1) * m_tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * m_tileSize.x, (tv + 1) * m_tileSize.y);
        }
    }
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_tileset;

    target.draw(m_vertices, states);
}
