#pragma once
#pragma once
#include <iostream>

using namespace std;

class Vector4 {
public:
	float vector4[4];

	Vector4();
	Vector4(const float &dx, const float &dy, const float &dz, const float &dw = 1);
	Vector4 operator+(Vector4 rhs); // Suma
	Vector4 operator-(Vector4 rhs); // Resta
	Vector4 operator*(Vector4 rhs); // Multiplicación
	Vector4 operator*(float num); // Multiplicación con un entero
	Vector4 normalize(Vector4 vec); // Normalizar
	Vector4 cross(Vector4 vec); // Producto Cruz
	float point(Vector4 vec); // Producto Punto

};