#include "Line2D.h"
#include <cmath>

Line2D::Line2D(const Point2D& pt1, const Point2D& pt2) : pt1(pt1), pt2(pt2) {
    setLength();
}

void Line2D::setLength() {
    int dx = pt2.getX() - pt1.getX();
    int dy = pt2.getY() - pt1.getY();
    length = sqrt(dx * dx + dy * dy);
}

Point2D Line2D::getPt1() const {
    return pt1;
}

Point2D Line2D::getPt2() const {
    return pt2;
}

double Line2D::getScalarValue() const {
    return length;
}

void Line2D::setPt1(const Point2D& pt1) {
    this->pt1 = pt1;
    setLength();
}

void Line2D::setPt2(const Point2D& pt2) {
    this->pt2 = pt2;
    setLength();
}

//Sorting functions

// Sort by P1-X in ascending order, then by P1-Y
bool Line2D::compareByP1X_ASC(const Line2D& a, const Line2D& b) {
    if (a.getPt1().getX() != b.getPt1().getX()) 
        return a.getPt1().getX() < b.getPt1().getX();
    return a.getPt1().getY() < b.getPt1().getY(); // Tie-break by P1-Y
}

// Sort by P1-X in descending order, then by P1-Y
bool Line2D::compareByP1X_DESC(const Line2D& a, const Line2D& b) {
    if (a.getPt1().getX() != b.getPt1().getX()) 
        return a.getPt1().getX() > b.getPt1().getX();
    return a.getPt1().getY() > b.getPt1().getY(); // Tie-break by P1-Y
}

// Sort by P2-X in ascending order, then by P2-Y
bool Line2D::compareByP2X_ASC(const Line2D& a, const Line2D& b) {
    if (a.getPt2().getX() != b.getPt2().getX()) 
        return a.getPt2().getX() < b.getPt2().getX();
    return a.getPt2().getY() < b.getPt2().getY(); // Tie-break by P2-Y
}

// Sort by P2-X in descending order, then by P2-Y
bool Line2D::compareByP2X_DESC(const Line2D& a, const Line2D& b) {
    if (a.getPt2().getX() != b.getPt2().getX()) 
        return a.getPt2().getX() > b.getPt2().getX();
    return a.getPt2().getY() > b.getPt2().getY(); // Tie-break by P2-Y
}

// Sort by Length in ascending order
bool Line2D::compareByLength_ASC(const Line2D& a, const Line2D& b) {
    return a.getScalarValue() < b.getScalarValue();
}

// Sort by Length in descending order
bool Line2D::compareByLength_DESC(const Line2D& a, const Line2D& b) {
    return a.getScalarValue() > b.getScalarValue();
}