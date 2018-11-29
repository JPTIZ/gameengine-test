#include "cache.h"

namespace game::graphics {

sf::Texture& Cache::load_texture(const std::string& filename) {
    {
        auto cached = _textures.find(filename);
        if (cached != _textures.end()) {
            return cached->second;
        }
    }

    auto tex = sf::Texture{};

    if (not tex.loadFromFile(filename)) {
        throw FileNotFound(filename);
    }

    _textures.emplace(std::make_pair(filename, tex));

    return _textures[filename];
}

}
