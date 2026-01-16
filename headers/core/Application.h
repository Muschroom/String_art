#pragma once
#include <SFML/Graphics.hpp> 

#include "../headers/ui/UIController.h"
#include "../headers/core/Canvas.h"
#include "AppState.h"

class Application{
private:
    AppState state;
    sf::RenderWindow window;
    UIController controller;
    Canvas canvas;

protected:
    void listenEvents();
    void render();
public:
    Application();

    void run();

    ~Application() = default;
};