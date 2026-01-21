#pragma once
#include <SFML/Graphics.hpp>

#include "../headers/data_structures/ImageLogic.h"

class ImageProcessor{
public:
    static PixelMatrix resize(const sf::Image& img, unsigned int width, unsigned int height);
};   