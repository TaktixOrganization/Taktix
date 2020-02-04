#include <Core/Taktix.hpp>
#include <States/SplashScreenState.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    Taktix* game = Taktix::instance();
    game->run<SplashScreenState>();

    return EXIT_SUCCESS;
}
