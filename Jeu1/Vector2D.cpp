#include "Vector2D.h"

Vector2D::Vector2D() :x(0.), y(0.) {}
Vector2D::Vector2D(float x_, float y_) :x(x_), y(y_) {}

Vector2D& Vector2D::operator+=(const Vector2D& vec)
{
	x += vec.x;
	y += vec.y;

	return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& vec)
{
	x -= vec.x;
	y -= vec.y;

	return *this;
}

Vector2D& Vector2D::operator*=(const Vector2D& vec)
{
	x *= vec.x;
	y *= vec.y;

	return *this;
}

Vector2D& Vector2D::operator*(const int& i)
{
	return *this *= Vector2D(static_cast<float>(i), static_cast<float>(i));
}

Vector2D& Vector2D::operator/=(const Vector2D& vec)
{
	if (vec.x == 0 && vec.y == 0) throw std::exception("Division by 0 in \"Vector2D& Vector2D::operator/=(const Vector2D& vec)\"");
	x /= vec.x;
	y /= vec.y;

	return *this;
}

Vector2D& Vector2D::Add(const Vector2D& vec)
{
	return *this += vec;
}

Vector2D& Vector2D::Substract(const Vector2D& vec)
{
	return *this -= vec;
}

Vector2D& Vector2D::Multiply(const Vector2D& vec)
{
	return *this *= vec;
}

Vector2D& Vector2D::Divide(const Vector2D& vec)
{
	return *this /= vec;
}

Vector2D& Vector2D::Zero()
{
	x = y = 0.;

	return *this;
}

Vector2D operator+(Vector2D v1, const Vector2D& v2)
{
	return v1 += v2;
}

Vector2D operator-(Vector2D v1, const Vector2D& v2)
{
	return v1 -= v2;
}

Vector2D operator*(Vector2D v1, const Vector2D& v2)
{
	return v1 *= v2;
}

Vector2D operator/(Vector2D v1, const Vector2D& v2)
{
	return v1 /= v2;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& vec)
{
	stream << "(" << vec.x << "," << vec.y << ")";

	return stream;
}
