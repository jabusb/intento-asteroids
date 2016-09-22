#pragma once
#include <iostream>

using namespace std;

class Vector3 {
public:
	float vector3[3];

	Vector3();
	Vector3(const float &dx, const float &dy, const float &dz = 1);
	Vector3 operator+(Vector3 rhs); // Suma
	Vector3 operator-(Vector3 rhs); // Resta
	Vector3 operator*(Vector3 rhs); // Multiplicaci�n
	Vector3 operator*(float num); // Multiplicaci�n por un entero
	Vector3 normalize(Vector3 vec); // Normalizar
	Vector3 cross(Vector3 vec); // Producto Cruz
	float point(Vector3 vec); // Producto Punto
};