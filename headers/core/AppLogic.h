#pragma once
#include <string>

#include "StringGenerator.h"
#include "AppState.h"
#include "Canvas.h"
class AppLogic{
private:
    Canvas& canvas;
    AppState& state;
    StringGenerator generator;
    PixelMatrix pixelMatrix;
    std::string openFileDialog();

public:
    AppLogic(Canvas& canvas, AppState& state);

    int getPins() const;
    int getStrings() const;
    int getOpacity() const;
    int getSize() const;
    unsigned getWindowWidth() const;
    unsigned getWindowHeight() const;

    void addPins(int pins);
    void addStrings(int strings);
    void addOpacity(int opacity);
    void addSize(int size);
    
    void loadImage();
    void reset();

    void startGeneration();
    bool isGenerating() const;

    void update();
};
