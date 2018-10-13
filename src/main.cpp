#include <iostream>

#include "game.h"

int main() {
    using namespace game;
    std::cout << "Hello, world!\n";

    auto game = Game{};
    game.start();
}
