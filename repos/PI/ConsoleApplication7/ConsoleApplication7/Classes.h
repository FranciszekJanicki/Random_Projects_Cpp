#pragma once
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <ostream>

class Vector3D {
public:
	double dx, dy, dz;
	Vector3D(double x, double y, double z);
};

double operator*(const Vector3D& arg1, const Vector3D& arg2);

class Point3D {
public:
	double x, y, z;
	Point3D() = default;
	Point3D(double, double, double);
	Point3D operator+(double arg);
	Point3D operator+(const Vector3D& vector);
	friend std::ostream& operator<<(std::ostream& os, const Point3D& point);
};

Point3D operator-(const Point3D& argPoint, const Vector3D& argVector);
