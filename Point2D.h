#ifndef POINT2D_H
#define POINT2D_H

#include <iomanip>
#include <iostream>

using namespace std;


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

    bool operator==(const Point2D& other) const {
        return x == other.x && y == other.y;
    }

    friend ostream& operator<<(ostream& os, const Point2D& point) {
        os << "[" << setw(4) << point.getX() << ", " 
           << setw(4) << point.getY() << "]   "
           << fixed << setprecision(3) << point.getScalarValue();
        return os;
    }


};

#endif