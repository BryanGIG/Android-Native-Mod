#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>

struct Rect
{
    union
    {
        struct
        {
			float x;
			float y;
			float width;
			float height;
        };
        float data[4];
    };

    inline Rect();
    inline Rect(float XMin, float YMin, float Width, float Height);
};

Rect::Rect() : x(0), y(0), width(0), height(0) {}
Rect::Rect(float XMin, float YMin, float Width, float Height) : x(XMin), y(YMin), width(Width), height(Height) {}

