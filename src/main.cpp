#include <iostream>

#include "game.h"
#include "scenes.h"

void scene_loop(game::Game& game) {
    using namespace px::scenes;
    auto scene = std::make_unique<SceneTitle>(game);
    scene->start();

    while (game.running()) {
        game.update();

        scene->update();

        game.display();
    }

    scene->terminate();
}

int main() {
    using namespace game;
    using namespace px;

    std::cout << "Hello, world!\n";

    Game{scene_loop}.start();

    std::cout << "Goodbye, world!\n";
}
