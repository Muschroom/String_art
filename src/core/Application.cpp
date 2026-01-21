#include <iostream>

#include "../../headers/core/Application.h"
#include "../../headers/ui/UIController.h"
Application::Application(): canvas(), state(), logic(canvas, state), window(sf::RenderWindow(sf::VideoMode(logic.getWindowWidth(), logic.getWindowHeight()), "string_art", sf::Style::Default)), controller(logic){
    window.setFramerateLimit(60);
}

void Application::renderWindow(){
    window.clear(sf::Color::White);

    canvas.render(window, logic.getSize(), logic.getSize());
    controller.render(window);
    window.display();
}

void Application::handleEvents(){
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == sf::Event::Resized){
            state.windowWidth = event.size.width;
            state.windowHeight = event.size.height;

            sf::View view(sf::FloatRect(0, 0, 
                static_cast<float>(event.size.width),
                static_cast<float>(event.size.height)));
            window.setView(view);

            controller.updateLayot();
        }
        controller.handleEvents(event, window);
    }
}

void Application::run(){
    while (window.isOpen()){
        handleEvents();
        logic.update();
        renderWindow(); 
    }
}