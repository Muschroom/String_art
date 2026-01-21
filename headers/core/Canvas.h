#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "../headers/data_structures/Geometry.h"


class Canvas{
private:
    std::vector<sf::Vertex> lines;
    std::vector<sf::CircleShape> pins;
public:
    Canvas() = default;
    void render(sf::RenderWindow& window, int canvasWidth, int canvasHeight);

    void setNailPositions(const std::vector<Pin>& pins);
    void addLine(const Line& line, int opacity);

    void clear();

};