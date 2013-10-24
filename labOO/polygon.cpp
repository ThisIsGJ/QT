#include <QtCore/qmath.h>
#define USE MATH DEFINES
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288419717
#endif

#include "polygon.h"

polygon::polygon(int XCentre, int YCentre, const QColor& colour,
               const QColor& selectedColour, unsigned int radius, int x) :
    shape(XCentre, YCentre, colour, selectedColour),
    mRadius(radius)
{
    sides = x;
}

void polygon::drawShape()
{
    const unsigned int numCoords = sides;

    //Draw polygon
    for(unsigned int i = 0;
        i < numCoords;
        i++)
    {
        int X = mRadius*qCos(2.0*i*M_PI/(double)numCoords)+0.5;
        int Y = mRadius*qSin(2.0*i*M_PI/(double)numCoords)+0.5;

        glVertex2i(X, Y);
    }

}

bool polygon::insideZeroCentredShape(int x, int y)
{
    float distFromCentre = qSqrt(x*x+y*y);

    return (distFromCentre <= mRadius);
}
