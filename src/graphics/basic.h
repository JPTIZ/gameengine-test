#ifndef PERSONA_X_GRAPHICS_BASIC_H
#define PERSONA_X_GRAPHICS_BASIC_H

#include <filesystem>

#include <SFML/Graphics.hpp>

namespace game::graphics {

class Plane: public sf::Drawable {
public:
    static Plane from_file(const std::filesystem::path&);

    void draw(sf::RenderTarget&, sf::RenderStates) const override;
private:
};

using Sprite = sf::Sprite;

}

#endif
