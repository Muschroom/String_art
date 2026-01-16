#pragma once
#include <SFML/Graphics.hpp>

struct AppState{
public:
    int pins = 200;
    int strings = 1000;
    int opacity = 10;

    unsigned int windowHeight = 720;
    unsigned int windowWidth = 1280;

    sf::Image originalImage;
    sf::Image processedImage;

    int canvasHeight = 300;
    int canvasWidth = 300;

    bool imageUpdated = false;
public:
    void setImage(const sf::Image& image);
};