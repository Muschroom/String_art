#include "../../headers/core/ImageProcessor.h"

PixelMatrix ImageProcessor::resize(const sf::Image& image, unsigned int width, unsigned int height){
    PixelMatrix result(width, height);

    unsigned int imageHeight = image.getSize().y;
    unsigned int imageWidth = image.getSize().x;

    for (unsigned int y = 0; y < height; y++){
        for (unsigned int x = 0; x < width; x++){
            unsigned int originalX = static_cast<unsigned int>(
                static_cast<float>(x) * imageWidth / width
            );
            unsigned int originalY = static_cast<unsigned int>(
                static_cast<float>(y) * imageHeight / height
            );
            originalX = std::min(originalX, imageWidth - 1);
            originalY = std::min(originalY, imageHeight - 1);

            sf::Color color = image.getPixel(originalX, originalY);
            result.getPixel(x, y) = Pixel(color.r, color.g, color.b);
        }
    }

    return result;
}