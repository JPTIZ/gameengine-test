#ifndef PERSONA_X_SCENES_H
#define PERSONA_X_SCENES_H

#include <iostream>

#include "game/scene.h"
#include "game/input.h"
#include "graphics.h"
#include "graphics/basic.h"
#include "project/system.h"

namespace px::scenes {

struct Option {
    std::string filename;
    game::graphics::Sprite sprite;
};

class SceneTitle : public game::Scene {
    using Game = game::Game;
    using Sprite = game::graphics::Sprite;
public:
    SceneTitle(Game& game):
        game{game}
    {}

    ~SceneTitle() {
        game.sprites().clear();
    }

    void start() override;

    void update() override {
        using Key = game::input::Key;
        if (game.input().triggered(Key::Up)) {
            --option;
        } else if (game.input().triggered(Key::Down)) {
            ++option;
        }

        option = option % options.size();

        highlight_options();
    }

    void highlight_options() {
        auto i = 0;
        for (auto& [_, sprite]: options) {
            auto [width, height] = sprite.getTexture()->getSize();
            auto half = int(width / 2);
            sprite.setTextureRect({
                half * (i == option),
                0,
                half,
                int(height)
            });

            ++i;
        }
    }

    void terminate() override {
        std::cout << "Terminating...\n";
    }

private:
    game::Game& game;
    game::graphics::Sprite background;

    int option = 0;

    std::vector<Option> options = {
        {"res/system/newgame.png", {}},
        {"res/system/loadgame.png", {}},
    };
};

}

#endif
