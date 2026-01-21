#pragma once

struct Pin{
    float x = 0.0f;
    float y = 0.0f;

    Pin() = default;
    Pin(float x, float y): x(x), y(y){}
};

struct Line{
    int start = -1;
    int end = -1;

    Line() = default;
    Line(int start, int end): start(start), end(end){}
};

