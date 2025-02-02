#ifndef LINE2D_H
#define LINE2D_H

#include "Point2D.h"

class Line2D {
private:
    Point2D pt1, pt2;
    
protected:
    double length;
    virtual void setLength();

public:
    Line2D(const Point2D& pt1, const Point2D& pt2);

    Point2D getPt1() const;
    Point2D getPt2() const;
    double getScalarValue() const;

    void setPt1(const Point2D& pt1);
    void setPt2(const Point2D& pt2);
};

#endif
