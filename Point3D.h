#ifndef POINT3D_H
#define POINT3D_H

#include "Point2D.h"

class Point3D : public Point2D {
protected:
    int z;
    void setDistFrOrigin() override;

public:
    Point3D(int x=0, int y=0, int z=0);

    int getZ() const;
    void setZ(int z);

    // Static comparator functions for sorting
    static bool compareByX_ASC(const Point3D& a, const Point3D& b);
    static bool compareByX_DESC(const Point3D& a, const Point3D& b);
    
    static bool compareByY_ASC(const Point3D& a, const Point3D& b);
    static bool compareByY_DESC(const Point3D& a, const Point3D& b);

    static bool compareByZ_ASC(const Point3D& a, const Point3D& b);
    static bool compareByZ_DESC(const Point3D& a, const Point3D& b);

    static bool compareByDistance_ASC(const Point3D& a, const Point3D& b);
    static bool compareByDistance_DESC(const Point3D& a, const Point3D& b);

    
};

#endif
