#include "Line3D.h"
#include <cmath>
#include <iostream>
#include <string>

Line3D::Line3D(const Point3D& pt1, const Point3D& pt2) 
    : Line2D(Point2D(pt1.getX(), pt1.getY()), Point2D(pt2.getX(), pt2.getY())) {
    this->pt1 = pt1;  // Store the full Point3D object
    this->pt2 = pt2;  // Store the full Point3D object

    
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

//Sorting Functions

// Sort by P1-X in ascending order, with tie-breakers by P1-Y, then P1-Z
bool Line3D::compareByP1X_ASC(const Line3D& a, const Line3D& b) {
    if (a.getPt1().getX() != b.getPt1().getX()) return a.getPt1().getX() < b.getPt1().getX();
    if (a.getPt1().getY() != b.getPt1().getY()) return a.getPt1().getY() < b.getPt1().getY();
    return a.getPt1().getZ() < b.getPt1().getZ();
}

// Sort by P1-X in descending order, with tie-breakers by P1-Y, then P1-Z
bool Line3D::compareByP1X_DESC(const Line3D& a, const Line3D& b) {
    if (a.getPt1().getX() != b.getPt1().getX()) return a.getPt1().getX() > b.getPt1().getX();
    if (a.getPt1().getY() != b.getPt1().getY()) return a.getPt1().getY() > b.getPt1().getY();
    return a.getPt1().getZ() > b.getPt1().getZ();
}

// Sort by P1-Y in ascending order, with tie-breakers by P1-X, then P1-Z
bool Line3D::compareByP1Y_ASC(const Line3D& a, const Line3D& b) {
    if (a.getPt1().getY() != b.getPt1().getY()) return a.getPt1().getY() < b.getPt1().getY();
    if (a.getPt1().getX() != b.getPt1().getX()) return a.getPt1().getX() < b.getPt1().getX();
    return a.getPt1().getZ() < b.getPt1().getZ();
}

// Sort by P1-Y in descending order, with tie-breakers by P1-X, then P1-Z
bool Line3D::compareByP1Y_DESC(const Line3D& a, const Line3D& b) {
    if (a.getPt1().getY() != b.getPt1().getY()) return a.getPt1().getY() > b.getPt1().getY();
    if (a.getPt1().getX() != b.getPt1().getX()) return a.getPt1().getX() > b.getPt1().getX();
    return a.getPt1().getZ() > b.getPt1().getZ();
}

// Sort by Length in ascending order
bool Line3D::compareByLength_ASC(const Line3D& a, const Line3D& b) {
    return a.getScalarValue() < b.getScalarValue();
}

// Sort by Length in descending order
bool Line3D::compareByLength_DESC(const Line3D& a, const Line3D& b) {
    return a.getScalarValue() > b.getScalarValue();
}
