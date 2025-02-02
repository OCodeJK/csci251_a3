#include "Line2D.h"
#include <cmath>

Line2D::Line2D(const Point2D& pt1, const Point2D& pt2) : pt1(pt1), pt2(pt2) {
    setLength();
}

void Line2D::setLength() {
    int dx = pt2.getX() - pt1.getX();
    int dy = pt2.getY() - pt1.getY();
    length = std::sqrt(dx * dx + dy * dy);
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
