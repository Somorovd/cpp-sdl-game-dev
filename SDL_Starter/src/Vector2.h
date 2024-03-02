#pragma once
#include "math.h"

class Vector2
{
public:

	Vector2(float x, float y) : m_x(x), m_y(y) {}

	float getX() const { return m_x; }
	float getY() const { return m_y; }

	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

	float length() const;
	void normalize();

	Vector2 operator+(const Vector2& v) const;
	Vector2& operator+=(const Vector2& v);

	Vector2 operator-(const Vector2& v) const;
	Vector2& operator-=(const Vector2& v);

	Vector2 operator*(float scalar) const;
	Vector2& operator*=(float scalar);

	Vector2 operator/(float scalar) const;
	Vector2& operator/=(float scalar);

private:

	float m_x, m_y;
};

