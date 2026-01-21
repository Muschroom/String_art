#pragma once
#include <SFML/Graphics.hpp>

struct AppState{
public:
    int pins = 400;
    int strings = 5000;
    int opacity = 20.f;

    unsigned int windowHeight = 720;
    unsigned int windowWidth = 1280;

    sf::Image image;

    int size = 500;

    bool is_generating = false;

};