#ifndef PERSONA_X_GRAPHICS_CACHE_H
#define PERSONA_X_GRAPHICS_CACHE_H

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

namespace game::graphics {

class FileNotFound: public std::exception {
public:
    FileNotFound(std::string filename):
        filename{filename + " not found"}
    {}

    const char* what() const noexcept override {
        return filename.c_str();
    }

private:
    std::string filename;
};

class Cache {
public:
    Cache() = default;

    sf::Texture& load_texture(const std::string&);

    auto& textures() {
        return _textures;
    }

    const auto& textures() const {
        return _textures;
    }

private:
    std::map<std::string, sf::Texture> _textures;
};

}

#endif
