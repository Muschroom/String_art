#include "../../headers/core/AppState.h"
#include "../../headers/core/ImageProcessor.h"

void AppState::setImage(const sf::Image& image){
    originalImage = image;

    auto result = ImageProcessor::process(
        originalImage,
        canvasWidth,
        canvasHeight,
        true
    );

    imageUpdated = true;
    processedImage = std::move(result.image);
}