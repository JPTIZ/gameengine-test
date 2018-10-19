#ifndef PERSONA_X_GAME_H
#define PERSONA_X_GAME_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>
#include <vector>

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

    void start();
    void update();
    void close();

    void display();

private:
    bool _running = false;
    sf::RenderWindow window;
    GameLoop _gameloop;
    std::vector<sf::Sprite*> _sprites;
};

}

#endif
