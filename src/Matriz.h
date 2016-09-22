#pragma once
#include "Vector3.h"

using namespace std;

class Matriz3 {
public:
	float matriz[3][3];

	Matriz3();
	Matriz3(Vector3 &vec1, Vector3 &vec2, Vector3 &vec3 = Vector3(0, 0));
	Matriz3 operator*(const Matriz3 &rhs); 
	Vector3 operator*(Vector3 &rhs);
	Matriz3 rotate(const float &angle); 
	Matriz3 translate(const float &x, const float &y);
	Matriz3 scale(const float &x, const float &y);
};