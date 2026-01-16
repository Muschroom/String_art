#include "../../headers/ui/UIController.h"
#include "../../headers/core/FIleDialog.h"
#include <iostream>

UIController::UIController(AppState& state): state(state){
    font.loadFromFile("resources/fonts/myFont.ttf");
    createMenu();
}

void UIController::createMenu(){
    createParametrsInfo();
    createControllers();
}

void UIController::updateLayot(){
    labels[0].setText("Pins: " + std::to_string(state.pins));
    labels[1].setText("Strings: " + std::to_string(state.strings));
    labels[2].setText("Opacity: " + std::to_string(state.opacity));
}

void UIController::createControllers(){
    buttons.emplace_back(sf::Vector2f(state.windowWidth - PANEL_WIDTH, MARGIN_TOP * 2 + MARGIN_BETWEEN * labels.size()),
                         sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), "Load Image", font, [this]{loadImage();});
    buttons.emplace_back(sf::Vector2f(state.windowWidth - PANEL_WIDTH, MARGIN_TOP * 2 + MARGIN_BETWEEN * (labels.size() + 1)),
                         sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), "Generate", font, [this]{std::cout <<"generate";});

    buttons.emplace_back(sf::Vector2f(state.windowWidth - PANEL_WIDTH, MARGIN_TOP * 3 + MARGIN_BETWEEN * labels.size()),
                         sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT), "+50", font, [this]{state.pins+=50;updateLayot();});
    buttons.emplace_back(sf::Vector2f(state.windowWidth - PANEL_WIDTH + BUTTON_WIDTH / 2, MARGIN_TOP * 3 + MARGIN_BETWEEN * (labels.size())),
                         sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT), "-50", font, [this]{state.pins-=50;updateLayot();});

    buttons.emplace_back(sf::Vector2f(state.windowWidth - PANEL_WIDTH, MARGIN_TOP * 3.5 + MARGIN_BETWEEN * labels.size()),
                         sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT), "+500", font, [this]{state.strings+=500;updateLayot();});
    buttons.emplace_back(sf::Vector2f(state.windowWidth - PANEL_WIDTH + BUTTON_WIDTH / 2, MARGIN_TOP * 3.5 + MARGIN_BETWEEN * (labels.size())),
                         sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT), "-500", font, [this]{state.strings-=500;updateLayot();});

    buttons.emplace_back(sf::Vector2f(state.windowWidth - PANEL_WIDTH, MARGIN_TOP * 4 + MARGIN_BETWEEN * labels.size()),
                         sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT), "+10", font, [this]{state.opacity+=10;updateLayot();});
    buttons.emplace_back(sf::Vector2f(state.windowWidth - PANEL_WIDTH + BUTTON_WIDTH / 2, MARGIN_TOP * 4 + MARGIN_BETWEEN * (labels.size())),
                         sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT), "-10", font, [this]{state.opacity-=10;updateLayot();});
    
}

void UIController::createParametrsInfo(){
    labels.emplace_back(sf::Vector2f(state.windowWidth - PANEL_WIDTH, MARGIN_TOP), "Pins: " + std::to_string(state.pins), font, 16);
    labels.emplace_back(sf::Vector2f(state.windowWidth - PANEL_WIDTH, MARGIN_TOP + MARGIN_BETWEEN), "Strings: " + std::to_string(state.strings), font, 16);
    labels.emplace_back(sf::Vector2f(state.windowWidth - PANEL_WIDTH, MARGIN_TOP + MARGIN_BETWEEN * 2), "Opacity: " + std::to_string(state.opacity), font, 16);
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

void UIController::loadImage(){
    std::string path = openFileDialog();
    sf::Image img;
    if(img.loadFromFile(path)){
        std::cout << "Loaded";
        state.setImage(img);
    }
}
