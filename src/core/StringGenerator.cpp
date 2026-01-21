#include "../../headers/core/StringGenerator.h"
#include <cmath>
#include <algorithm>
#include <limits>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void StringGenerator::init(const PixelMatrix& _image, int _pins, int _strings, float _lineInfluence){
    image = _image;
    lines = _strings;
    lineInfluence = _lineInfluence;
    pins = generateFrame(_pins, _image.getWidth());
    linesGenerated = 0;
}

std::vector<Pin> StringGenerator::generateFrame(int pins_count, int size){
    std::vector<Pin> pins;

    float center = size / 2.0f;
    float radius =  size * 0.45f;

    for(int i = 0; i < pins_count; i++){
        float angle = 2.0f * M_PI * i / pins_count;
        float x = center + radius * std::cos(angle);
        float y = center + radius * std::sin(angle);

        pins.emplace_back(x, y);
    }

    return pins;
}

std::vector<int> StringGenerator::getPixelsPerLine(int x0, int y0, int x1, int y1) const {
    std::vector<int> pixels;
    const int imgW = static_cast<int>(image.getWidth());
    const int imgH = static_cast<int>(image.getHeight());

    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = std::max(std::abs(dx), std::abs(dy));

    float xStep = static_cast<float>(dx) / steps;
    float yStep = static_cast<float>(dy) / steps;

    float currentX = static_cast<float>(x0);
    float currentY = static_cast<float>(y0);

    for (int i = 0; i <= steps; i++){
        int x = static_cast<int>(std::round(currentX));
        int y = static_cast<int>(std::round(currentY));

        if (x >= 0 && x < imgW && y >= 0 && y < imgH){
            pixels.push_back(y * imgW + x);
        }

        currentX += xStep;
        currentY += yStep;
    }

    return pixels;
}

float StringGenerator::calculateImpact(const std::vector<int>& pixelIndex) const{
    float sum = 0.0f;

    for(int index : pixelIndex){
        int y = index / image.getWidth();
        int x = index % image.getWidth();

        sum += image.getPixel(x, y).brightness();
    }

    return sum / pixelIndex.size();
}

void StringGenerator::darkenLine(const std::vector<int>& pixelIndex){
    for(int index: pixelIndex){
        int y = index / image.getWidth();
        int x = index % image.getWidth();
        uint8_t current = image.getPixel(x, y).brightness();
        uint8_t newValue = std::min(255, static_cast<int>(current + lineInfluence));
        image.getPixel(x, y) = Pixel(newValue, newValue, newValue);
    }
}

bool StringGenerator::hasNextLine() const{
    return !pins.empty() && linesGenerated < lines;
}

Line StringGenerator::getNextLine(){
    if(!hasNextLine()){
        return {-1, -1};
    }

    int bestPin = -1;
    std::vector<int> bestPixels;
    float minBrightness = std::numeric_limits<float>::max();
    
    for(int i = 0; i < static_cast<int>(pins.size()); i++){
        if(i == currentPin){
            continue;
        }

        const Pin& start = pins[currentPin];
        const Pin& end = pins[i];

        int x0 = static_cast<int>(std::round(start.x));
        int y0 = static_cast<int>(std::round(start.y));
        int x1 = static_cast<int>(std::round(end.x));
        int y1 = static_cast<int>(std::round(end.y));

        auto pixels = getPixelsPerLine(x0, y0, x1, y1);
        if (pixels.empty()) continue;

        float brightness = calculateImpact(pixels);

        if(brightness < minBrightness){
            minBrightness = brightness;
            bestPin = i;
            bestPixels = pixels;
        }
    }

    if(bestPin == -1){
        linesGenerated = lines;
        return Line(-1, -1);
    }

    darkenLine(bestPixels);
    Line result(currentPin, bestPin);
    currentPin = bestPin;
    linesGenerated++;
    return result;
}

const std::vector<Pin>& StringGenerator::getNailPositions() const{
    return pins;
}