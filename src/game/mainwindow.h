#ifndef PERSONA_X_GAME_MAINWINDOW_H
#define PERSONA_X_GAME_MAINWINDOW_H

#include <string>

#include <SFML/Graphics.hpp>

namespace game::graphics {

class MainWindow {
public:
    MainWindow(int width, int height, const std::string& title):
        _window{
            sf::VideoMode{
                unsigned(width),
                unsigned(height)},
            title}
    {}

    void show();
    void update();

private:
    sf::RenderWindow _window;
};

}

#endif
