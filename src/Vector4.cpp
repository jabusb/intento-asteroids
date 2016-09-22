#include "Vector4.h"

Vector4::Vector4() {
	vector4[0] = 0;
	vector4[1] = 0;
	vector4[2] = 0;
	vector4[3] = 1;
}

Vector4::Vector4(const float & dx, const float & dy, const float & dz, const float & dw) {
	vector4[0] = dx;
	vector4[1] = dy;
	vector4[2] = dz;
	vector4[3] = dw;
}

Vector4 Vector4::operator+(Vector4 rhs) {
	return Vector4(vector4[0] + rhs.vector4[0], vector4[1] + rhs.vector4[1], vector4[2] + rhs.vector4[2]);
}

Vector4 Vector4::operator-(Vector4 rhs) {
	return Vector4(vector4[0] - rhs.vector4[0], vector4[1] - rhs.vector4[1], vector4[2] - rhs.vector4[2]);
}

Vector4 Vector4::operator*(Vector4 rhs) {
	return Vector4(vector4[0] * rhs.vector4[0], vector4[1] * rhs.vector4[1], vector4[2] * rhs.vector4[2]);
}

Vector4 Vector4::operator*(float num) {
	return Vector4(vector4[0] * num, vector4[1] * num, vector4[2] * num);
}

Vector4 Vector4::normalize(Vector4 vec) {
	float norm = sqrt(pow(vec.vector4[0], 2) + pow(vec.vector4[1], 2) + pow(vec.vector4[2], 2) + pow(vec.vector4[3], 2));
	return Vector4(vector4[0] / norm, vector4[1] / norm, vector4[2] / norm, vector4[3] / norm);
}

Vector4 Vector4::cross(Vector4 vec) {
	Vector4 vecTemp;
	vecTemp.vector4[0] = vector4[1] * vec.vector4[2] - (vector4[2] * vec.vector4[1]);
	vecTemp.vector4[1] = vector4[0] * vec.vector4[2] - (vector4[2] * vec.vector4[0]);
	vecTemp.vector4[2] = vector4[0] * vec.vector4[1] - (vector4[1] * vec.vector4[0]);

	
	return vecTemp;
}

float Vector4::point(Vector4 vec) {
	float p = 0;
	for (int i = 0; i < 3; i++) {
		p += vector4[i] * vec.vector4[i];
	}
	cout << p << endl;
	return p;
}