#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Button.h"
#include "Text.h"
#include "../headers/core/AppLogic.h"

class Application;
class UIController{
private:
    static constexpr float BUTTON_WIDTH = 100.f;
    static constexpr float BUTTON_HEIGHT = 25.f;
    static constexpr float PANEL_WIDTH = 150.f;
    static constexpr float MARGIN_TOP = 50.f;
    static constexpr float MARGIN_BETWEEN = 25.f;
private:
    AppLogic& logic;
    std::vector<Button> buttons;
    std::vector<Text> labels;
    sf::Font font;
private:
    void createMenu();
    void createControllers();
    void createParametrsInfo();

public:
    UIController(AppLogic& logic);

    void handleEvents(const sf::Event& event, const sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void updateLayot();
    void updateParametrsinfo();
};