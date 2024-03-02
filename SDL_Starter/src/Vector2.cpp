#include "Vector2.h"

float Vector2::length() const
{
	return sqrt(m_x * m_x + m_y * m_y);
}

void Vector2::normalize()
{
	float len = length();
	if (len > 0)
	{
		(*this) *= 1 / len;
	}
}

Vector2 Vector2::operator+(const Vector2& v) const
{
	return Vector2(m_x + v.m_x, m_y + v.m_y);
}

Vector2& Vector2::operator+=(const Vector2& v)
{
	m_x += v.m_x;
	m_y += v.m_y;
	return *this;
}

Vector2 Vector2::operator-(const Vector2& v) const
{
	return Vector2(m_x - v.m_x, m_y - v.m_y);
}

Vector2& Vector2::operator-=(const Vector2& v)
{
	m_x -= v.m_x;
	m_y -= v.m_y;
	return *this;
}

Vector2 Vector2::operator*(float scalar) const
{
	return Vector2(m_x * scalar, m_y * scalar);
}

Vector2& Vector2::operator*=(float scalar)
{
	m_x *= scalar;
	m_y *= scalar;
	return *this;
}

Vector2 Vector2::operator/(float scalar) const
{
	return Vector2(m_x / scalar, m_y / scalar);
}

Vector2& Vector2::operator/=(float scalar)
{
	m_x /= scalar;
	m_y /= scalar;
	return *this;
}
