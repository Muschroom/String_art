#include "../../headers/core/Canvas.h"

#include <iostream>

void Canvas::setNailPositions(const std::vector<Pin>& _pins){
    pins.clear();
    pins.reserve(_pins.size());

    for(const auto& pin: _pins){
        sf::CircleShape new_pin(1.0f);
        new_pin.setFillColor(sf::Color::Black);
        new_pin.setPosition(pin.x, pin.y);
        pins.push_back(std::move(new_pin));
    }
}

void Canvas::addLine(const Line& line, int opacity){
    if (line.start < 0 || line.end < 0 ||
        static_cast<size_t>(line.start) >= pins.size() ||
        static_cast<size_t>(line.end) >= pins.size()){
        return;
    }

    sf::Vector2f start = pins[line.start].getPosition();
    sf::Vector2f end = pins[line.end].getPosition();

    uint8_t alpha = static_cast<uint8_t>(std::clamp(0, opacity, 100) * 2.55f);

    lines.emplace_back(start, sf::Color(0, 0, 0, alpha));
    lines.emplace_back(end, sf::Color(0, 0 ,0, alpha));
}

void Canvas::clear(){
    lines.clear();
    pins.clear();
}

void Canvas::render(sf::RenderWindow& window, int canvasWidth, int canvasHeight){
    sf::Vector2f offset = {
        (window.getSize().x - canvasWidth) / 2.0f,
        (window.getSize().y - canvasHeight) / 2.0f
    };
    if (!lines.empty()){
        std::vector<sf::Vertex> newLines = lines;
        for (auto& vertex : newLines){
            vertex.position += offset;
        }
        window.draw(newLines.data(), newLines.size(), sf::Lines);
    }

    for (auto& pin : pins){
        sf::CircleShape newNail = pin;
        newNail.move(offset);
        window.draw(newNail);
    }
}