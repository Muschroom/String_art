#include <iostream>

#include "../../headers/ui/Button.h"

Button::Button(const sf::Vector2f& position,
               const sf::Vector2f& size,
               const std::string& info,
               const sf::Font& font,
               std::function<void()> func,
               sf::Color backgroundColor,
               sf::Color hoverColor): backgroundColor(backgroundColor), hoverColor(hoverColor)
{
        shape.setSize(size);
        shape.setPosition(position);
        shape.setFillColor(backgroundColor);
        
        callback = std::move(func);

        text.setString(info);
        text.setFont(font);
        text.setCharacterSize(14);
        text.setFillColor(sf::Color::White);
        
        centerText();
}

void Button::setPosition(const sf::Vector2f& pos){
    shape.setPosition(pos);
}

void Button::render(sf::RenderWindow& window) const{
    window.draw(shape);
    window.draw(text);
}

bool Button::mouseIn(const sf::RenderWindow& window) const{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePos);
    return shape.getGlobalBounds().contains(mouseWorldPos);
}

void Button::centerText(){
    sf::FloatRect bounds = text.getLocalBounds();
    sf::Vector2f pos = shape.getPosition();
    sf::Vector2f size = shape.getSize();

    text.setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
    text.setPosition(
        pos.x + size.x / 2,
        pos.y + size.y / 2
    );
}

void Button::handleEvent(const sf::Event& event, const sf::RenderWindow& window){
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
        if(mouseIn(window) && callback){
            callback();
        }
    }

    if(event.type == sf::Event::MouseMoved){
        if(mouseIn(window)){
            shape.setFillColor(hoverColor);
        }
        else{
            shape.setFillColor(backgroundColor);
        }
    }
}