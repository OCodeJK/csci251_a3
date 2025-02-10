#ifndef LINE3D_H
#define LINE3D_H

#include "Point3D.h"
#include "Line2D.h"

class Line3D : public Line2D {
private:
    Point3D pt1, pt2;
    

protected:
    void setLength() override;

public:
    //Default constructor
    Line3D() : pt1(Point3D(0,0,0)), pt2(Point3D(0,0,0)) {}

    //Existing Constructor
    Line3D(const Point3D& pt1, const Point3D& pt2);

    Point3D getPt1() const;
    Point3D getPt2() const;

    void setPt1(const Point3D& pt1);
    void setPt2(const Point3D& pt2);

    //Static comparator functions for sorting
    static bool compareByP1X_ASC(const Line3D& a, const Line3D& b);
    static bool compareByP1X_DESC(const Line3D& a, const Line3D& b);

    static bool compareByP1Y_ASC(const Line3D& a, const Line3D& b);
    static bool compareByP1Y_DESC(const Line3D& a, const Line3D& b);

    static bool compareByLength_ASC(const Line3D& a, const Line3D& b);
    static bool compareByLength_DESC(const Line3D& a, const Line3D& b);

    bool operator==(const Line3D& other) const {
        return pt1 == other.pt1 && pt2 == other.pt2;
    }

    friend ostream& operator<<(ostream& os, const Line3D& line) {
        os << "[" << setw(4) << line.pt1.getX() << ", "
            << setw(4) << line.pt1.getY() << ", "
            << setw(4) << line.pt1.getZ() << "]   "
            << "[" << setw(4) << line.pt2.getX() << ", "
            << setw(4) << line.pt2.getY() << ", "
            << setw(4) << line.pt2.getZ() << "]   "
            << fixed << setprecision(3) << line.getScalarValue();
        return os;
    }

};

#endif
