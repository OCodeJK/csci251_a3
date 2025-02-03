#include "Point3D.h"
#include <cmath>
#include <iostream>


Point3D::Point3D(int x, int y, int z) : Point2D(x, y), z(z) {
    setDistFrOrigin();
}

void Point3D::setDistFrOrigin() {
    distFrOrigin = sqrt(getX() * getX() + getY() * getY() + z * z);
}

int Point3D::getZ() const {
    return z;
}

void Point3D::setZ(int z) {
    this->z = z;
    setDistFrOrigin();
}

// Static Comparator Functions
bool Point3D::compareByX_ASC(const Point3D& a, const Point3D& b) {
    if (a.getX() != b.getX()) return a.getX() < b.getX(); // Sort X first
    if (a.getY() != b.getY()) return a.getY() < b.getY(); // If X is the same, sort Y
    return a.getZ() < b.getZ(); // If X and Y are the same, sort Z
}

bool Point3D::compareByX_DESC(const Point3D& a, const Point3D& b) {
    if (a.getX() != b.getX()) return a.getX() > b.getX(); // Sort X Descending
    if (a.getY() != b.getY()) return a.getY() < b.getY(); // Sort Y Ascending
    return a.getZ() > b.getZ(); // Sort Z Descending
}

bool Point3D::compareByY_ASC(const Point3D& a, const Point3D& b) {
    if (a.getY() != b.getY()) return a.getY() < b.getY();
    if (a.getX() != b.getX()) return a.getX() < b.getX();
    return a.getZ() < b.getZ();
}

bool Point3D::compareByY_DESC(const Point3D& a, const Point3D& b) {
    if (a.getY() != b.getY()) return a.getY() > b.getY();
    if (a.getX() != b.getX()) return a.getX() > b.getX();
    return a.getZ() > b.getZ();
}

bool Point3D::compareByZ_ASC(const Point3D& a, const Point3D& b) {
    if (a.getZ() != b.getZ()) return a.getZ() < b.getZ();
    if (a.getX() != b.getX()) return a.getX() < b.getX();
    return a.getY() < b.getY();
}

bool Point3D::compareByZ_DESC(const Point3D& a, const Point3D& b) {
    if (a.getZ() != b.getZ()) return a.getZ() > b.getZ();
    if (a.getX() != b.getX()) return a.getX() > b.getX();
    return a.getY() > b.getY();
}

bool Point3D::compareByDistance_ASC(const Point3D& a, const Point3D& b) {
    return a.getScalarValue() < b.getScalarValue();
}

bool Point3D::compareByDistance_DESC(const Point3D& a, const Point3D& b) {
    return a.getScalarValue() > b.getScalarValue();
}