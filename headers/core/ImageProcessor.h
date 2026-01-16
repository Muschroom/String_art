#pragma once
#include <SFML/Graphics.hpp>


class ImageProcessor{
public:
    struct ProcessedImage
    {
        sf::Image image;
        unsigned int width;
        unsigned int height;
    };
    
    static ProcessedImage process(
        const sf::Image& image,
        unsigned int width,
        unsigned int height,
        bool toGrayscale = true
    );
private:
    static sf::Color toGrayScale(const sf::Color& color);
};