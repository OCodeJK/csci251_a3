#include "Point2D.h"
#include <cmath>

Point2D::Point2D(int x, int y) : x(x), y(y) {
    setDistFrOrigin();
}

void Point2D::setDistFrOrigin() {
    distFrOrigin = std::sqrt(x * x + y * y);
}

int Point2D::getX() const {
    return x;
}

int Point2D::getY() const {
    return y;
}

double Point2D::getScalarValue() const {
    return distFrOrigin;
}

void Point2D::setX(int x) {
    this->x = x;
    setDistFrOrigin();
}

void Point2D::setY(int y) {
    this->y = y;
    setDistFrOrigin();
}

//Sorting Functions
// X-ordinate ASC: Sort by X (Ascending), then Y (Ascending)
bool Point2D::compareByX_ASC(const Point2D& a, const Point2D& b) {
    if (a.getX() != b.getX()) return a.getX() < b.getX(); // Sort X first
    return a.getY() < b.getY(); // If X is the same, sort Y
}

// X-ordinate DESC: Sort by X (Descending), then Y (Ascending)
bool Point2D::compareByX_DESC(const Point2D& a, const Point2D& b) {
    if (a.getX() != b.getX()) return a.getX() > b.getX(); // Sort X Descending
    return a.getY() < b.getY(); // If X is the same, sort Y Ascending
}

// Y-ordinate ASC: Sort by Y (Ascending), then X (Ascending)
bool Point2D::compareByY_ASC(const Point2D& a, const Point2D& b) {
    if (a.getY() != b.getY()) return a.getY() < b.getY(); // Sort Y first
    return a.getX() < b.getX(); // If Y is the same, sort X
}

// Y-ordinate DESC: Sort by Y (Descending), then X (Ascending)
bool Point2D::compareByY_DESC(const Point2D& a, const Point2D& b) {
    if (a.getY() != b.getY()) return a.getY() > b.getY(); // Sort Y Descending
    return a.getX() < b.getX(); // If Y is the same, sort X Ascending
}

// Distance ASC: Sort by Distance from Origin (Ascending)
bool Point2D::compareByDistance_ASC(const Point2D& a, const Point2D& b) {
    return a.getScalarValue() < b.getScalarValue();
}

// Distance DESC: Sort by Distance from Origin (Descending)
bool Point2D::compareByDistance_DESC(const Point2D& a, const Point2D& b) {
    return a.getScalarValue() > b.getScalarValue();
}