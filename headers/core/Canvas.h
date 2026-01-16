#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "AppState.h"
#include "StringGenerator.h"

class Canvas{
private:
    std::vector<sf::Vertex> lines;
    std::vector<sf::CircleShape> nails;

    mutable sf::Texture imageTexture;

public:
    void render(sf::RenderWindow& window, const AppState& state) const;
};