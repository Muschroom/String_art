#include <windows.h>
#include <commdlg.h>
#include "../../headers/core/AppLogic.h"
#include "../../headers/core/AppState.h"
#include "../../headers/core/Canvas.h"
#include "../../headers/core/ImageProcessor.h"
#include <iostream>
AppLogic::AppLogic(Canvas& canvas, AppState& state): canvas(canvas), state(state){}

int AppLogic::getPins() const {return state.pins; }
int AppLogic::getStrings() const {return state.strings; }
int AppLogic::getOpacity() const {return state.opacity; }
int AppLogic::getSize() const {return state.size; }
unsigned int AppLogic::getWindowWidth() const {return state.windowWidth; }
unsigned int AppLogic::getWindowHeight() const {return state.windowHeight; }

void AppLogic::addPins(int pins){
    state.pins = std::max(100, state.pins + pins);
}

void AppLogic::addStrings(int strings){
    state.strings = std::max(1000, state.strings + strings);
}

void AppLogic::addOpacity(int opacity){
    state.opacity = std::clamp(state.opacity + opacity, 5, 100);
}

void AppLogic::addSize(int size){
    int maxSize = std::min(state.windowHeight * 0.75, state.windowWidth * 0.75);
    int minSize = 300;
    state.size = std::clamp(state.size + size, minSize, maxSize);
}
std::string AppLogic::openFileDialog(){
#ifdef _WIN32
    OPENFILENAMEA ofn;
    CHAR szFile[260] = { 0 };
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "Image Files\0*.png;*.jpg;*.jpeg;*.bmp\0All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileNameA(&ofn))
    {
        return std::string(ofn.lpstrFile);
    }
#endif
    return "";
}

void AppLogic::loadImage(){
    std::string path = openFileDialog();
    if (path.empty()) return;

    if (!state.image.loadFromFile(path)) return;
    reset();
}

void AppLogic::reset(){
    canvas.clear();
    state.is_generating = false;
}

void AppLogic::startGeneration(){
    pixelMatrix = ImageProcessor::resize(state.image, state.size, state.size);
    if (pixelMatrix.getWidth() == 0) return;

    generator.init(pixelMatrix, state.pins, state.strings, state.opacity);
    canvas.setNailPositions(generator.getNailPositions());
    state.is_generating = true;
}

bool AppLogic::isGenerating() const {
    return state.is_generating;
}

void AppLogic::update(){
    if (isGenerating() && generator.hasNextLine()){
        Line line = generator.getNextLine();
        canvas.addLine(line, state.opacity);
    }
}