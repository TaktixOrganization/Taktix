#include <Core/Taktix.hpp>
#include <States/FirstState.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    Taktix* game = Taktix::instance();
    game->run<FirstState>();

    return EXIT_SUCCESS;
}
