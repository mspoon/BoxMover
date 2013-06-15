#include "Vector2D.h"

Vector2D::Vector2D() {
	x = 0.0f;
	y = 0.0f;
}

Vector2D::Vector2D(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2D Vector2D::operator+(const Vector2D &rhs) {
	return Vector2D(this->x, this->y) += rhs;
}

Vector2D &Vector2D::operator+=(const Vector2D &rhs) {
	this->x += rhs.x;
	this->y += rhs.y;

	return *this;
}

Vector2D Vector2D::operator-(const Vector2D &rhs) {
	return Vector2D(this->x, this->y) -= rhs;
}

Vector2D &Vector2D::operator-=(const Vector2D &rhs) {
	this->x -= rhs.x;
	this->y -= rhs.y;

	return *this;
}

Vector2D &Vector2D::operator=(const Vector2D &rhs) {
	this->x = rhs.x;
	this->y = rhs.y;

	return *this;
}

Vector2D &Vector2D::operator*=(const int &rhs) {
	this->x *= rhs;
	this->y *= rhs;

	return *this;
}

Vector2D &Vector2D::operator*=(const unsigned int &rhs) {
	this->x *= rhs;
	this->y *= rhs;

	return *this;
}

Vector2D &Vector2D::operator*=(const float &rhs) {
	this->x *= rhs;
	this->y *= rhs;

	return *this;
}

Vector2D &Vector2D::operator*=(const double &rhs) {
	this->x *= rhs;
	this->y *= rhs;

	return *this;
}

Vector2D Vector2D::operator*(const int &rhs) {
	return Vector2D(this->x, this->y) *= rhs;
}

Vector2D Vector2D::operator*(const unsigned int &rhs) {
	return Vector2D(this->x, this->y) *= rhs;
}

Vector2D Vector2D::operator*(const float &rhs) {
	return Vector2D(this->x, this->y) *= rhs;
}

Vector2D Vector2D::operator*(const double &rhs) {
	return Vector2D(this->x, this->y) *= rhs;
}

float Vector2D::dot(const Vector2D &rhs) {
	return (this->x*rhs.x) + (this->y*rhs.y);
}

Vector2D Vector2D::perpendicular() {
	return Vector2D(-y, x);
}

string Vector2D::toString() {
	std::stringstream ss;
	ss << "(" << x << "," << y << ")";
	return ss.str();
}
