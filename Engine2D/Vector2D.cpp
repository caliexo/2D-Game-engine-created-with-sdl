#include "Vector2D.h"

float Vector2D::length() {
    return sqrt(x * x + y * y);
}

void Vector2D::normalize() {
    float l = length();
    if (l > 0) { // Make sure not to divide by zero
        (*this) *= 1 / l;
    }
}

Vector2D Vector2D::operator+(const Vector2D& v2) const {
    return Vector2D(x + v2.x, y + v2.y);
}

Vector2D& Vector2D::operator+=(const Vector2D& v2) {
    x += v2.x;
    y += v2.y;
    return *this;
}

Vector2D Vector2D::operator*(float scalar) {
    return Vector2D(x * scalar, y * scalar);
}

Vector2D& Vector2D::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2D Vector2D::operator-(const Vector2D& v2) const {
    return Vector2D(x - v2.x, y - v2.y);
}

Vector2D& Vector2D::operator-=(const Vector2D& v2) {
    x -= v2.x;
    y -= v2.y;
    return *this;
}

Vector2D Vector2D::operator/(float scalar) {
    return Vector2D(x / scalar, y / scalar);
}

Vector2D& Vector2D::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}