#pragma once
#include <SFML/Graphics.hpp> 

#include "../headers/ui/UIController.h"
#include "AppLogic.h"
#include "AppState.h"
#include "Canvas.h"
class Application{
private:
    Canvas canvas;
    AppState state;
    AppLogic logic;
    sf::RenderWindow window;
    UIController controller;
protected:
    void handleEvents();
    void renderWindow();
public:
    Application();

    void run();

};