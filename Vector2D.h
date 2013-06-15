#ifndef Vector2D_h
#define Vector2D_h

#include <string>
#include <sstream>
using std::string;

class Vector2D {
	public:
		float x;
		float y;

		Vector2D();
		Vector2D(float x, float y);

		Vector2D operator+(const Vector2D &rhs);
		Vector2D &operator+=(const Vector2D &rhs);
		Vector2D &operator=(const Vector2D &rhs);
		Vector2D operator-(const Vector2D &rhs);
		Vector2D &operator-=(const Vector2D &rhs);

		Vector2D &operator*=(const int &rhs);
		Vector2D &operator*=(const unsigned int &rhs);
		Vector2D &operator*=(const float &rhs);
		Vector2D &operator*=(const double &rhs);
		Vector2D operator*(const int &rhs);
		Vector2D operator*(const unsigned int &rhs);
		Vector2D operator*(const float &rhs);
		Vector2D operator*(const double &rhs);

		float dot(const Vector2D &rhs);
		Vector2D perpendicular();

		string toString();
};

#endif
