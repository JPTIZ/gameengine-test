#ifndef PERSONA_X_GAME_SCENE_H
#define PERSONA_X_GAME_SCENE_H

#include "../game.h"

namespace game {

class Scene {
public:
    virtual ~Scene() {}

    virtual void start() = 0;
    virtual void update() = 0;
    virtual void terminate() = 0;
};

}

#endif
