#pragma once

#include <vector>
#include <cstdint>
#include <stdexcept>
struct Pixel{
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    uint8_t a = 255;

    Pixel() = default;
    Pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255 ): r(r), g(g), b(b), a(a){}

    uint8_t brightness () const{
        return  0.299f * r + 0.587f * g + 0.114f * b;
    }
};

class PixelMatrix{
private:
    unsigned int width, height;
    std::vector<Pixel> data;
public:
    PixelMatrix(unsigned int width, unsigned int height): width(width), height(height), data(width * height){}
    PixelMatrix(): width(0), height(0){}

    Pixel& getPixel(unsigned int x, unsigned int y){
        if (x >= width || y >= height)
            throw std::out_of_range("Index out of range");
        return data[y * width + x];
    }

    const Pixel& getPixel(unsigned int x, unsigned int y) const{
        if (x >= width || y >= height)
            throw std::out_of_range("Index out of range");
        return data[y * width + x];
    }

    unsigned int getWidth() const {return width; }
    unsigned int getHeight() const {return height; }
};