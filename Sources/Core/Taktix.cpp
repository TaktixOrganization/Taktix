#include <Core/Taktix.hpp>
#include <cstdlib>
#include <fstream>

Taktix::Taktix(GraphicsSettings settings)
    : m_stateManager()
    , m_settings(settings)
{
}

Taktix* Taktix::instance()
{
    GraphicsSettings settings;
    settings.deserialize("Assets/settings.txt");

    static Taktix instance(settings);

    return &instance;
}
