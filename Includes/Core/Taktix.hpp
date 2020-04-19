#ifndef HEADER_TAKTIX_HPP
#define HEADER_TAKTIX_HPP

#include <Core/GraphicsSettings.hpp>
#include <Core/StateManager.hpp>
#include <type_traits>

class Taktix
{
public:
    ~Taktix() = default;

    template <typename T>
    void run();

    static Taktix* instance();

private:
    Taktix(GraphicsSettings settings);
    Taktix(const Taktix&) = delete;
    Taktix& operator=(const Taktix&) = delete;

private:
    StateManager m_stateManager;
    GraphicsSettings m_settings;
};

#include <Core/Taktix.inl>

#endif  // HEADER_TAKTIX_HPP
