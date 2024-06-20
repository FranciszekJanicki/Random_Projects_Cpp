#include "Classes.h"

Vector3D::Vector3D(double x, double y , double z) : dx(x), dy(y), dz(z) {
}

double operator*(const Vector3D& arg1, const Vector3D& arg2) {
	return (arg1.dx * arg2.dx + arg1.dy * arg2.dy + arg1.dz * arg2.dz);
}

Point3D::Point3D(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Point3D Point3D::operator+(double arg) {
	this->x = x + arg;
	this->y = y + arg;
	this->z = z + arg;
	return *this;
}

Point3D Point3D::operator+(const Vector3D& vector) {
	this->x = x + vector.dx;
	this->y = y + vector.dy;
	this->z = z + vector.dz;
	return *this;
}

Point3D operator-(const Point3D& argPoint, const Vector3D& argVector) {
	Point3D Point;
	Point.x = argPoint.x - argVector.dx;
	Point.y = argPoint.y - argVector.dy;
	Point.z = argPoint.z - argVector.dz;
	return Point;
}

std::ostream& operator<<(std::ostream& os, const Point3D& point) {
	os << "[" << point.x << ' ' << point.y << ' ' << point.z << "] \n";
	return os;
}