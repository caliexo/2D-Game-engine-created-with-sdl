#pragma once
#include<iostream>

class Vector2D
{
private:

public:

	float x, y;

	Vector2D(float _x = 0.0f, float _y = 0.0f) : x(_x), y(_y) {}

	Vector2D operator+(const Vector2D& SecondVec) const { return Vector2D(this->x + SecondVec.x, this->y + SecondVec.y); }
	Vector2D operator-(const Vector2D& SecondVec) const { return Vector2D(this->x - SecondVec.x, this->y - SecondVec.y); }
	Vector2D operator*(const Vector2D& SecondVec) const { return Vector2D(this->x * SecondVec.x, this->y * SecondVec.y); }
	Vector2D operator/(const Vector2D& SecondVec) const { return Vector2D(this->x / SecondVec.x, this->y / SecondVec.y); }

	bool operator==(const Vector2D& SecondVec) const { return this->x == SecondVec.x && this->y == SecondVec.y; }

	
	float Distance(const Vector2D& SecondVec) const { return sqrt(pow(this->x - SecondVec.x, 2) + pow(this->y - SecondVec.y, 2)); }


};

