#include "../../headers/ui/Text.h"

Text::Text(const sf::Vector2f& pos,
         const std::string& info,
         const sf::Font& font,
         const unsigned int size,
         sf::Color color)
{
    text.setPosition(pos);
    text.setString(info);
    text.setFont(font);
    text.setCharacterSize(size);
    text.setFillColor(color);
}

void Text::render(sf::RenderWindow& window) const{
    window.draw(text);
}

void Text::setPosition(const sf::Vector2f& pos){
    text.setPosition(pos);
}

void Text::setText(const std::string& info){
    text.setString(info);
}