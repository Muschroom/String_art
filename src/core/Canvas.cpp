#include "../../headers/core/Canvas.h"

void Canvas::render(sf::RenderWindow& window, const AppState& state) const{
    if(imageTexture.getSize().x > 0){
        sf::Sprite sprite(imageTexture);
        sf::Vector2f pos = {
            (static_cast<float>(window.getSize().x ) - static_cast<float>(state.canvasWidth)) / 2.0f,
            (static_cast<float>(window.getSize().y ) - static_cast<float>(state.canvasHeight)) / 2.0f 
        };
        sprite.setPosition(pos);
        window.draw(sprite);
    }

    if (!lines.empty()){
        window.draw(lines.data(), lines.size(), sf::Lines);
    }

    for (const auto& nail : nails){
        window.draw(nail);
    }
}
