#include "Line3D.h"
#include <cmath>

Line3D::Line3D(const Point3D& pt1, const Point3D& pt2) : Line2D(pt1, pt2) {
    setLength();
}

void Line3D::setLength() {
    int dx = pt2.getX() - pt1.getX();
    int dy = pt2.getY() - pt1.getY();
    int dz = pt2.getZ() - pt1.getZ();
    length = std::sqrt(dx * dx + dy * dy + dz * dz);
}

Point3D Line3D::getPt1() const {
    return pt1;
}

Point3D Line3D::getPt2() const {
    return pt2;
}


void Line3D::setPt1(const Point3D& pt1) {
    this->pt1 = pt1;
    setLength();
}

void Line3D::setPt2(const Point3D& pt2) {
    this->pt2 = pt2;
    setLength();
}
