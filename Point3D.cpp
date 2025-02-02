#include "Point3D.h"
#include <cmath>

Point3D::Point3D(int x, int y, int z) : Point2D(x, y), z(z) {
    setDistFrOrigin();
}

void Point3D::setDistFrOrigin() {
    double dist = std::sqrt(getX() * getX() + getY() * getY() + z * z);
    Point2D::setX(dist);  // Update base class's distFrOrigin
}

int Point3D::getZ() const {
    return z;
}

void Point3D::setZ(int z) {
    this->z = z;
    setDistFrOrigin();
}
