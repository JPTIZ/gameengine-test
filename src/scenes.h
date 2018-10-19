#ifndef PERSONA_X_SCENES_H
#define PERSONA_X_SCENES_H

#include <iostream>

#include "game/scene.h"
#include "graphics/basic.h"
#include "project/system.h"

namespace px::scenes {

class SceneTitle : public game::Scene {
    using Game = game::Game;
    using Sprite = game::graphics::Sprite;
public:
    SceneTitle(Game& game):
        game{game}
    {}

    ~SceneTitle() = default;

    void start() override {
        std::cout << "Starting...\n";
        if (not bgtexture.loadFromFile(px::system::TITLEBG)) {
            std::cout << "Sorry, m8\n";
            return;
        }
        std::cout << "Ayy, all right\n";
        background.setTexture(bgtexture);
        auto& sprites = game.sprites();
        sprites.push_back(&background);
    }

    void update() override {
        std::cout << "Updating...\n";
    }

    void terminate() override {
        std::cout << "Terminating...\n";
    }

private:
    game::Game& game;
    sf::Texture bgtexture;
    game::graphics::Sprite background;
};

}

#endif
