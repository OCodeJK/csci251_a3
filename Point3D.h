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
};

#endif
