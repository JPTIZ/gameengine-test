#ifndef PERSONA_X_GAME_H
#define PERSONA_X_GAME_H

#include "game/mainwindow.h"

namespace game {

class Game {
public:
    Game():
        _window{640, 480, "Persona X"}
    {}

    void start();
    void update();

private:

    graphics::MainWindow _window;
};

}

#endif
