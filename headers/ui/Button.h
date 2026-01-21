#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
class Button{
private:
    sf::RectangleShape shape;
    sf::Color backgroundColor;
    sf::Color hoverColor;

    sf::Text text;

    std::function<void()> callback;

private:
    bool mouseIn(const sf::RenderWindow& window) const;
    void centerText();
public:
    Button(const sf::Vector2f& position,
           const sf::Vector2f& size,
           const std::string& text,
           const sf::Font& font,
           std::function<void()> func,
           sf::Color backgroundColor = sf::Color(70, 130, 180),
           sf::Color hoverColor = sf::Color(100, 149, 237));

    void render(sf::RenderWindow& window) const;
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);

    ~Button() = default;
public:
    void setPosition(const sf::Vector2f& pos);

    sf::Vector2f getPosition(){ return shape.getPosition();}
};