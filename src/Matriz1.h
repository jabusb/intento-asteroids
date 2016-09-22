#pragma once
#include "Vector4.h"

class Matriz4 {
public:
	float matriz[4][4];

	Matriz4();
	Matriz4(Vector4 &vec1, Vector4 &vec2, Vector4 &vec3, Vector4 &vec4 = Vector4(0, 0, 0));
	Vector4 operator*(Vector4 &rhs);
	Matriz4 operator*(const Matriz4 &rhs); 
	Matriz4 translate(const float &dx, const float &dy, const float &dz, const float &dw);
	Matriz4 lookAt(Vector4 &eye, Vector4 &target, Vector4 &up); 
	Matriz4 rotateX(const float angle); 
	Matriz4 rotateY(const float angle); 
	Matriz4 rotateZ(const float angle); 
								
	Matriz4 scale(const float &x, const float &y, const float &z);
	Matriz4 perspective(float &angle, float &aspect, float &near, float &far);
	Matriz4 ortho(float &near, float &far, float &left, float &right, float &top, float &bottom);
};