#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"

class polygon : public shape
{
public:
    polygon(int XCentre, int YCentre, const QColor& colour,
            const QColor& selectedColour, unsigned int radius,int x);
    int sides;


private:
    //Implemented functions for drawing and checking if inside the shape, specified by the base class, shape
    virtual void drawShape();
    virtual bool insideZeroCentredShape(int x, int y);

    unsigned int mRadius;

};

#endif // POLYGON_H
