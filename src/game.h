#ifndef PERSONA_X_GAME_H
#define PERSONA_X_GAME_H

#include <functional>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "game/input.h"
#include "graphics/cache.h"

namespace game {

class Game {
public:
    using GameLoop = std::function<void(Game&)>;
    Game(GameLoop gameloop):
        _gameloop{gameloop},
        window{}
    {}

    auto running() const {
        return _running;
    }

    auto& sprites() {
        return _sprites;
    }

    const auto& sprites() const {
        return _sprites;
    }

    auto& cache() {
        return _cache;
    }

    const auto& cache() const {
        return _cache;
    }

    auto& input() {
        return _input;
    }

    const auto& input() const {
        return _input;
    }

    void start();
    void update();
    void close();

    void display();

private:
    bool _running = false;
    GameLoop _gameloop;
    sf::RenderWindow window;
    std::vector<sf::Sprite*> _sprites;
    graphics::Cache _cache;
    input::Input _input;
};

}

#endif
