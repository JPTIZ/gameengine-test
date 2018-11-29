#include "game.h"
#include "scenes.h"

#include <tuple>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <pybind11/functional.h>

namespace py = pybind11;

using SpriteVec = std::vector<game::graphics::Sprite>;
PYBIND11_MAKE_OPAQUE(SpriteVec);

PYBIND11_MODULE(persona_x, m) {
    using namespace game;
    using namespace game::graphics;

    /**
     * STL Bindings
     */
    py::bind_vector<SpriteVec>(m, "SpriteVec");

    /**
     * SFML Bindings
     */
    py::class_<sf::Rect<float>>(m, "FloatRect")
        .def(py::init<>())
        .def_readwrite("width", &sf::Rect<float>::width)
        .def_readwrite("height", &sf::Rect<float>::height)
    ;

    py::class_<sf::IntRect>(m, "IntRect")
        .def(py::init<>())
        .def(py::init<int, int, int, int>())
    ;

    using Vec2u = sf::Vector2<unsigned>;
    py::class_<Vec2u>(m, "Vec2")
        .def_readwrite("x", &Vec2u::x)
        .def_readwrite("y", &Vec2u::y)
    ;

    py::class_<sf::Texture>(m, "Texture")
        .def(py::init<>())
        .def_property_readonly("size", &sf::Texture::getSize)
    ;

    py::class_<Sprite>(m, "Sprite")
        .def(py::init<>())
        .def(py::init([](Game& game, const std::string& filename) {
            return Sprite(game.cache().load_texture(filename));
        }))
        .def_property_readonly("texture", &Sprite::getTexture)
        .def("set_texture", &Sprite::setTexture)
        .def_property_readonly(
            "local_bounds",
            &Sprite::getLocalBounds
        )
        .def_property(
            "src_rect",
            &Sprite::getTextureRect,
            &Sprite::setTextureRect
        )
        .def_property(
            "position",
            &Sprite::getPosition,
            [](Sprite& self, py::tuple t) {
                auto [x, y] = py::cast<std::tuple<float, float>>(t);
                self.setPosition(x, y);
            }
        )
    ;

    /**
     * Game Engine bindings
     */
    py::class_<Cache>(m, "Cache")
        .def("load_texture", &Cache::load_texture)
    ;

    py::class_<Game>(m, "Game")
        .def(py::init<Game::GameLoop>())
        .def("cache", py::overload_cast<>(&Game::cache))
        .def("add_sprite", [] (Game& g, Sprite& s) {
            g.sprites().push_back(&s);
        })
        .def("clear_sprites", [] (Game& g) {
            g.sprites().clear();
        })
        .def("close", &Game::close)
        .def("display", &Game::display)
        .def("running", &Game::running)
        .def("start", &Game::start)
        .def("update", &Game::update)
    ;
}
