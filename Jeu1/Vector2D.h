#pragma once

#include <iostream>

class Vector2D
{
public:
	float x, y; // in public cause it's just a personalised type, not really a class

	Vector2D();
	Vector2D(float x_, float y_);

	Vector2D& operator+=(const Vector2D& vec);
	Vector2D& operator-=(const Vector2D& vec);
	Vector2D& operator*=(const Vector2D& vec);
	Vector2D& operator*(const int& i); // |!| Modifies "this" |!|
	Vector2D& operator/=(const Vector2D& vec);

	/*
		CarlBirch  does friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
		Maybe there's a reason but for now this seems more logical since vec1 + vec2 shouldn't modifiy vec1
	*/
	friend Vector2D operator+(Vector2D v1, const Vector2D& v2);
	friend Vector2D operator-(Vector2D v1, const Vector2D& v2);
	friend Vector2D operator*(Vector2D v1, const Vector2D& v2);
	friend Vector2D operator/(Vector2D v1, const Vector2D& v2);

	Vector2D& Add(const Vector2D& vec);
	Vector2D& Substract(const Vector2D& vec);
	Vector2D& Multiply(const Vector2D& vec);
	Vector2D& Divide(const Vector2D& vec);
	Vector2D& Zero();

	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);
};

