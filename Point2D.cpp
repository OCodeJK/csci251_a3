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
