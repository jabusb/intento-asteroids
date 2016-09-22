#include "Matriz1.h"

Matriz4::Matriz4() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				matriz[i][j] = 1;
			}
			else {
				matriz[i][j] = 0;
			}
		}
	}
}

Matriz4::Matriz4(Vector4 & vec1, Vector4 & vec2, Vector4 & vec3, Vector4 & vec4) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0) {
				matriz[i][j] = vec1.vector4[j]; // Inicializa la primera linea de la matriz
			}
			else if (i == 1) {
				matriz[i][j] = vec2.vector4[j]; // Inicializa la segunda linea de la matriz
			}
			else if (i == 2) {
				matriz[i][j] = vec3.vector4[j]; // Inicializa la tercera linea de la matriz
			}
			else {
				matriz[i][j] = vec4.vector4[j]; // Inicializa la cuarta linea de la matriz
			}
		}
	}
}

Vector4 Matriz4::operator*(Vector4 & rhs) {
	Vector4 vR = Vector4(0, 0, 0, 1); 
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			vR.vector4[i] += matriz[i][j] * rhs.vector4[j];
		}
	}
	return vR;
}

Matriz4 Matriz4::operator*(const Matriz4 & rhs) {
	Matriz4 mR;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mR.matriz[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				mR.matriz[i][j] += matriz[i][k] * rhs.matriz[k][j];
			}
		}
	}
	return mR;
}

Matriz4 Matriz4::translate(const float & dx, const float & dy, const float & dz, const float & dw) {
	Matriz4 tM = Matriz4(Vector4(1, 0, 0, dx), Vector4(0, 1, 0, dy), Vector4(0, 0, 1, dz));
	Matriz4 mat = Matriz4(Vector4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vector4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vector4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vector4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return tM * mat;   
}

Matriz4 Matriz4::lookAt(Vector4 & eye, Vector4 & target, Vector4 & up) {
	Vector4 w = Vector4(0, 0, 0, 0);
	Vector4 u = Vector4(0, 0, 0, 0);
	Vector4 v = Vector4(0, 0, 0, 0);

	w = w.normalize(target - eye);
	u = u.normalize(w.cross(up));
	v = v.normalize(u.cross(w));

	Matriz4 mR = Matriz4(Vector4(u.vector4[0], u.vector4[1], u.vector4[2], 0),
		Vector4(v.vector4[0], v.vector4[1], v.vector4[2], 0),
		Vector4(w.vector4[0], w.vector4[1], w.vector4[2], 0));
	Matriz4 mT = Matriz4(Vector4(1, 0, 0, -eye.vector4[0]),
		Vector4(0, 1, 0, -eye.vector4[1]),
		Vector4(0, 0, 1, -eye.vector4[2]));
	return mT * mR;
}

Matriz4 Matriz4::rotateX(const float angle) {
	float r = angle / 180;
	Matriz4 rX = Matriz4(Vector4(1, 0, 0, 0), Vector4(0, cos(r), -sin(r), 0), Vector4(0, sin(r), cos(r), 0));
	Matriz4 mat = Matriz4(Vector4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vector4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vector4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vector4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return rX * mat;
}

Matriz4 Matriz4::rotateY(const float angle) {
	float r = angle / 180;
	Matriz4 rY = Matriz4(Vector4(cos(r), 0, sin(r), 0), Vector4(0, 1, 0, 0), Vector4(-sin(r), 0, cos(r), 0));
	Matriz4 mat = Matriz4(Vector4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vector4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vector4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vector4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return rY * mat;
}

Matriz4 Matriz4::rotateZ(const float angle) {
	float r = angle / 180;
	Matriz4 rZ = Matriz4(Vector4(cos(r), -sin(r), 0, 0), Vector4(sin(r), cos(r), 0, 0), Vector4(0, 0, 1, 0));
	Matriz4 mat = Matriz4(Vector4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vector4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vector4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vector4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return rZ * mat;
}


Matriz4 Matriz4::scale(const float & x, const float & y, const float & z) {
	Matriz4 sM = Matriz4(Vector4(x, 0, 0, 0), Vector4(0, y, 0, 0), Vector4(0, 0, z, 0));
	Matriz4 mat = Matriz4(Vector4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vector4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vector4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vector4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return sM * mat;
}

Matriz4 Matriz4::perspective(float & angle, float & aspect, float & near, float &far) {
	float d = 1 / (tan(angle / 360));
	Vector4 vector1 = Vector4((d / (aspect)), 0, 0, 0);
	Vector4 vector2 = Vector4(0, d, 0, 0);
	Vector4 vector3 = Vector4(0, 0, (-2 / (near - far)), 0);
	Vector4 vector4 = Vector4(0, 0, -1, 0);
	Matriz4 persp = Matriz4(vector1, vector2, vector3, vector4);
	Matriz4 object = Matriz4(Vector4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vector4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vector4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vector4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return persp * object;
}

Matriz4 Matriz4::ortho(float & near, float & far, float & left, float & right, float & top, float & bottom) {
	Vector4 vector1 = Vector4((2 / (right - left)), 0, 0, 0);
	Vector4 vector2 = Vector4(0, (2 / (top - bottom)), 0, 0);
	Vector4 vector3 = Vector4(0, 0, (-2 / (near - far)), 0);
	Matriz4 scale = Matriz4(vector1, vector2, vector3);
	vector1 = Vector4(1, 0, 0, (-(right + left) / 2));
	vector2 = Vector4(0, 1, 0, (-(top + bottom) / 2));
	vector3 = Vector4(0, 0, 1, (-(near + far) / 2));
	Matriz4 trans = Matriz4(vector1, vector2, vector3);
	scale = scale * trans;

	trans = Matriz4(Vector4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vector4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vector4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vector4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return scale * trans;
}