#include <iostream>
#include "Game.hpp"

int main(void)
{
    try {
        Game _game;

        _game.Loop();
    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}