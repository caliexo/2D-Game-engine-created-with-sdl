#pragma once
#include<iostream>

class Vector2D
{
private:
    
    float x, y;
public:

    Vector2D(float x, float y) : x(x), y(y) {}
    float getX() { return x; }
    float getY() { return y; }
    void setX(float newX) { x = newX; }
    void setY(float newY) { y = newY; }
    float length();

    void normalize();

    ///----------------------------------------------Operators overloading ------------------------------------------------------------
    /// + and += operators
    Vector2D operator+(const Vector2D& v2) const;
    Vector2D& operator+=(const Vector2D& v2);

    /// * and *= operator
    Vector2D operator*(float scalar);
    Vector2D& operator*=(float scalar);

    /// - and -= operator
    Vector2D operator-(const Vector2D& v2) const;
    Vector2D& operator-=(const Vector2D& v2);
    /// / and /= operator
    Vector2D operator/(float scalar);
    Vector2D& operator/=(float scalar);
};

