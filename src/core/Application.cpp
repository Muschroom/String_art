#include <iostream>

#include "../../headers/core/Application.h"
#include "../../headers/ui/UIController.h"

Application::Application(): state(), window(sf::RenderWindow(sf::VideoMode(state.windowWidth, state.windowHeight), "string_art", sf::Style::Default)), controller(state){
    window.setFramerateLimit(60);
}

void Application::render(){
    window.clear(sf::Color::White);

    canvas.render(window, state);
    controller.render(window);
    window.display();
}

void Application::listenEvents(){
    sf::Event event;

    while (window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed){
            window.close();
        }
        else if(event.type == sf::Event::Resized){
            state.windowWidth = event.size.width;
            state.windowHeight = event.size.height;
        }
        controller.handleEvents(event, window);
    }
}

void Application::run(){
    while (window.isOpen())
    {
        render();
        listenEvents(); 
    }
}