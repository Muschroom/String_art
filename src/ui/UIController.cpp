#include "../../headers/ui/UIController.h"
#include "../../headers/core/AppLogic.h"
#include <iostream>

UIController::UIController(AppLogic& logic): logic(logic){
    font.loadFromFile("resources/fonts/myFont.ttf");
    createMenu();
}

void UIController::createMenu(){
    createParametrsInfo();
    createControllers();
}

void UIController::updateLayot(){
    buttons.clear();
    labels.clear();
    createMenu();
}

void UIController::updateParametrsinfo(){
    labels[0].setText("Pins: " + std::to_string(logic.getPins()));
    labels[1].setText("Strings: " + std::to_string(logic.getStrings()));
    labels[2].setText("Opacity: " + std::to_string(logic.getOpacity()));
    labels[3].setText("Size: " + std::to_string(logic.getSize()));
}

void UIController::createControllers(){
    buttons.emplace_back(sf::Vector2f(logic.getWindowWidth()- PANEL_WIDTH, MARGIN_TOP * 2 + MARGIN_BETWEEN * labels.size()),
                         sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), "Load Image", font, [this]{logic.loadImage();});
    buttons.emplace_back(sf::Vector2f(logic.getWindowWidth()- PANEL_WIDTH, MARGIN_TOP * 2 + MARGIN_BETWEEN * (labels.size() + 1)),
                         sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), "Generate", font, [this]{logic.startGeneration();});

    buttons.emplace_back(sf::Vector2f(logic.getWindowWidth()- PANEL_WIDTH, MARGIN_TOP * 3 + MARGIN_BETWEEN * labels.size()),
                         sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT), "+50", font, [this]{logic.addPins(50);updateParametrsinfo();});
    buttons.emplace_back(sf::Vector2f(logic.getWindowWidth()- PANEL_WIDTH + BUTTON_WIDTH / 2, MARGIN_TOP * 3 + MARGIN_BETWEEN * (labels.size())),
                         sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT), "-50", font, [this]{logic.addPins(-50);updateParametrsinfo();});

    buttons.emplace_back(sf::Vector2f(logic.getWindowWidth()- PANEL_WIDTH, MARGIN_TOP * 3.5 + MARGIN_BETWEEN * labels.size()),
                         sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT), "+500", font, [this]{logic.addStrings(500);updateParametrsinfo();});
    buttons.emplace_back(sf::Vector2f(logic.getWindowWidth()- PANEL_WIDTH + BUTTON_WIDTH / 2, MARGIN_TOP * 3.5 + MARGIN_BETWEEN * (labels.size())),
                         sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT), "-500", font, [this]{logic.addStrings(-500);updateParametrsinfo();});

    buttons.emplace_back(sf::Vector2f(logic.getWindowWidth()- PANEL_WIDTH, MARGIN_TOP * 4 + MARGIN_BETWEEN * labels.size()),
                         sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT), "+5", font, [this]{logic.addOpacity(5);updateParametrsinfo();});
    buttons.emplace_back(sf::Vector2f(logic.getWindowWidth()- PANEL_WIDTH + BUTTON_WIDTH / 2, MARGIN_TOP * 4 + MARGIN_BETWEEN * (labels.size())),
                         sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT), "-5", font, [this]{logic.addOpacity(-5);updateParametrsinfo();});
    
    buttons.emplace_back(sf::Vector2f(logic.getWindowWidth()- PANEL_WIDTH, MARGIN_TOP * 4.5 + MARGIN_BETWEEN * labels.size()),
                         sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT), "+50", font, [this]{logic.addSize(50);updateParametrsinfo();});
    buttons.emplace_back(sf::Vector2f(logic.getWindowWidth()- PANEL_WIDTH + BUTTON_WIDTH / 2, MARGIN_TOP * 4.5 + MARGIN_BETWEEN * (labels.size())),
                         sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT), "-50", font, [this]{logic.addSize(-50);updateParametrsinfo();});
    buttons.emplace_back(sf::Vector2f(logic.getWindowWidth()- PANEL_WIDTH, MARGIN_TOP * 5 + MARGIN_BETWEEN * (labels.size() + 1)),
                         sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), "Reset", font, [this]{logic.reset();});
    
}

void UIController::createParametrsInfo(){
    labels.emplace_back(sf::Vector2f(logic.getWindowWidth()- PANEL_WIDTH, MARGIN_TOP), "Pins: " + std::to_string(logic.getPins()), font, 16);
    labels.emplace_back(sf::Vector2f(logic.getWindowWidth()- PANEL_WIDTH, MARGIN_TOP + MARGIN_BETWEEN), "Strings: " + std::to_string(logic.getStrings()), font, 16);
    labels.emplace_back(sf::Vector2f(logic.getWindowWidth()- PANEL_WIDTH, MARGIN_TOP + MARGIN_BETWEEN * 2), "Opacity: " + std::to_string(logic.getOpacity()), font, 16);
    labels.emplace_back(sf::Vector2f(logic.getWindowWidth()- PANEL_WIDTH, MARGIN_TOP + MARGIN_BETWEEN * 3), "Size: " + std::to_string(logic.getSize()), font, 16);
}

void UIController::handleEvents(const sf::Event& event, const sf::RenderWindow& window){
    for(auto& btn: buttons){
        btn.handleEvent(event, window);
    }
}


void UIController::render(sf::RenderWindow& window){
    for(const auto& btn: buttons){
        btn.render(window);
    }

    for(const auto& text: labels){
        text.render(window);
    }
}

