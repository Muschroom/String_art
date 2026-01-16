#include "../../headers/core/ImageProcessor.h"

ImageProcessor::ProcessedImage ImageProcessor::process(
        const sf::Image& image,
        unsigned int width,
        unsigned int height,
        bool toGrayscale
){
    sf::Image result;
    result.create(width, height);

    unsigned int imageWidth = image.getSize().x;
    unsigned int imageHeight = image.getSize().y;
    
    for(unsigned int y = 0; y < width; y++){
        for(unsigned int x = 0; x < height; x++){
            unsigned int imageX = static_cast<unsigned int>(
                static_cast<float>(x) * imageWidth / width
            );
            unsigned int imageY = static_cast<unsigned int>(
                static_cast<float>(y) * imageHeight / height
            );

            sf::Color pixel = image.getPixel(imageX, imageY);
            pixel = toGrayScale(pixel);
            
            result.setPixel(x, y, pixel);
        }
    }

    return {result, width, height};
}


sf::Color ImageProcessor::toGrayScale(const sf::Color& color){
    uint8_t gray = static_cast<uint8_t>(0.299f * color.r + 0.587f * color.g +0.114f * color.b);

    return sf::Color(gray, gray, gray);
}