#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Text{
private:
    sf::Text text;
public:
    Text(const sf::Vector2f& pos,
         const std::string& info,
         const sf::Font& font,
         const unsigned int size,
         sf::Color color = sf::Color::Black);
    
    void render(sf::RenderWindow& window) const;
public:
    void setPosition(const sf::Vector2f& pos);
    void setText(const std::string& info);
};