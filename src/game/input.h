#ifndef PERSONA_X_GAME_INPUT_H
#define PERSONA_X_GAME_INPUT_H

#include <map>

#include <SFML/Window.hpp>

namespace game::input {

using Key = sf::Keyboard::Key;

class Input {
public:
    Input() = default;

    void update() {
        for (auto& [key, time]: key_times) {
            if (sf::Keyboard::isKeyPressed(key)) {
                ++time;
            } else {
                time = 0;
            }
        }
    }

    auto triggered(Key key) {
        return key_times[key] == 1;
    }

    auto pressed(Key key) {
        return key_times[key] > 0;
    }

private:
    std::map<Key, int> key_times;
};

}

#endif
