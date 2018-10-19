#include "game.h"
#include "graphics.h"
#include "project/vocab.h"

#include <optional>

namespace {

auto next_event(sf::RenderWindow& window) {
    auto event = sf::Event{};
    return window.pollEvent(event)
        ? std::optional{event}
        : std::nullopt;
}

}

namespace game {

void Game::start() {
    window.create(
        sf::VideoMode{
            graphics::WIDTH,
            graphics::HEIGHT
        }, px::vocab::GAME_TITLE);
    _running = true;

    _gameloop(*this);
}

void Game::close() {
    window.close();
    _running = false;
}

void Game::update() {
    while (auto _event = next_event(window)) {
        auto event = *_event;
        if (event.type == sf::Event::Closed) {
            close();
        }
    }
}

void Game::display() {
    window.clear();

    for (auto& sprite: _sprites) {
        window.draw(*sprite);
    }

    window.display();
}

}
