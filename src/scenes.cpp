#include "scenes.h"

namespace {

void center(game::graphics::Sprite& sprite, int x_offset=0, int y_offset=0) {
    auto bounds = sprite.getLocalBounds();
    sprite.setPosition(
        (game::graphics::WIDTH - bounds.width) / 2 + x_offset,
        (game::graphics::HEIGHT - bounds.height) / 2 + y_offset
    );
}

}

namespace px::scenes {

void SceneTitle::start() {
    std::cout << "Starting...\n";

    auto& cache = game.cache();
    auto& sprites = game.sprites();

    background.setTexture(cache.load_texture(px::system::TITLEBG));
    center(background, 0, -40);
    sprites.push_back(&background);

    auto i = 0;
    for (auto& [filename, sprite]: options) {
        auto& tex = cache.load_texture(filename);
        sprite.setTexture(tex);

        auto [width, height] = sprite.getTexture()->getSize();
        sprite.setTextureRect({0, 0, int(width / 2), int(height)});

        center(sprite, 0, 120 + i*20);

        sprites.push_back(&sprite);
        ++i;
    }

    highlight_options();

    std::cout << "Done start!\n";
}

}
