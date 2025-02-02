#ifndef POINT2D_H
#define POINT2D_H

class Point2D {
protected:
    int x, y;
    double distFrOrigin;

    virtual void setDistFrOrigin();

public:
    Point2D(int x = 0, int y = 0);

    int getX() const;
    int getY() const;
    double getScalarValue() const;

    void setX(int x);
    void setY(int y);
};

#endif