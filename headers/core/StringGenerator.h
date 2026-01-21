#pragma once
#include <vector>
#include <cstdint>
#include "../headers/data_structures/Geometry.h"   
#include "../headers/data_structures/ImageLogic.h"  

class StringGenerator{
private:
    PixelMatrix image;
    std::vector<Pin> pins;
    int currentPin = 0;
    int linesGenerated = 0;
    int lines = 0;
    float lineInfluence = 10.f;

    std::vector<Pin> generateFrame(int cpins_countunt, int size);
    
    std::vector<int> getPixelsPerLine(int x0, int y0, int x1, int y1) const;

    float calculateImpact(const std::vector<int>& pixelsIndex) const;

    void darkenLine(const std::vector<int>& pixelsIndex);

public:
    StringGenerator() = default;

    void init(const PixelMatrix& image, int pins, int strings, float lineInfluence);

    bool hasNextLine() const;
    Line getNextLine();
    const std::vector<Pin>& getNailPositions() const;
};