#include "Matriz.h"

Matriz3::Matriz3() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				matriz[i][j];
			}
			else {
				matriz[i][j] = 0;
			}
		}
	}
}

Matriz3::Matriz3(Vector3 & vec1, Vector3 & vec2, Vector3 & vec3) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) { 
			if (i == 0) {
				matriz[i][j] = vec1.vector3[j]; 
			}
			else if (i == 1) {
				matriz[i][j] = vec2.vector3[j]; 
			}
			else {
				matriz[i][j] = vec3.vector3[j];
			}
		}
	}
}

Matriz3 Matriz3::operator*(const Matriz3 & rhs) {
	Matriz3 mR; 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mR.matriz[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				mR.matriz[i][j] += matriz[i][k] * rhs.matriz[k][j];
			}
		}
	}
	return mR;
}

Vector3 Matriz3::operator*(Vector3 & rhs) {
	Vector3 vR = Vector3(0, 0, 0); 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			vR.vector3[i] += matriz[i][j] * rhs.vector3[j];
		}
	}
	return vR;
}

Matriz3 Matriz3::rotate(const float & angle) {
	float r = angle / 180; 
	Matriz3 rot = Matriz3(Vector3(cos(r), -sin(r)), Vector3(sin(r), cos(r)));
	Matriz3 mat = Matriz3(Vector3(matriz[0][0], matriz[0][1], matriz[0][2]),
		Vector3(matriz[1][0], matriz[1][1], matriz[1][2]),
		Vector3(matriz[2][0], matriz[2][1], matriz[2][2]));
	return rot * mat;
}

Matriz3 Matriz3::translate(const float & x, const float & y) {
	Matriz3 tras = Matriz3(Vector3(1, 0, x), Vector3(0, 1, y));
	Matriz3 mat = Matriz3(Vector3(matriz[0][0], matriz[0][1], matriz[0][2]),
		Vector3(matriz[1][0], matriz[1][1], matriz[1][2]),
		Vector3(matriz[2][0], matriz[2][1], matriz[2][2]));
	return tras * mat;
}


Matriz3 Matriz3::scale(const float & x, const float & y) {
	Matriz3 scal = Matriz3(Vector3(x, 0, 0), Vector3(0, y, 0)); 
	Matriz3 mat = Matriz3(Vector3(matriz[0][0], matriz[0][1], matriz[0][2]),
		Vector3(matriz[1][0], matriz[1][1], matriz[1][2]),
		Vector3(matriz[2][0], matriz[2][1], matriz[2][2]));
	return scal * mat;
}