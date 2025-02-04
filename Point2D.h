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

    //Static comparator functions for sorting
    static bool compareByX_ASC(const Point2D& a, const Point2D& b);
    static bool compareByX_DESC(const Point2D& a, const Point2D& b);
    
    static bool compareByY_ASC(const Point2D& a, const Point2D& b);
    static bool compareByY_DESC(const Point2D& a, const Point2D& b);

    static bool compareByDistance_ASC(const Point2D& a, const Point2D& b);
    static bool compareByDistance_DESC(const Point2D& a, const Point2D& b);


};

#endif