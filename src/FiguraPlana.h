#pragma once
#include "Line.h"
#include "Vector3.h"
#include "Matriz.h"
#include "ofVec2f.h"

enum type {
	LINEA, LINEACERRADA, TRIANGULOS,
};
class FiguraPlana {
private:
	vector<Vector3>puntos;
	Matriz3 transform;

public:
	Vector3 pos, escalar; 
	float angulo;

	void init(Line &linea);
		void update(Line &linea, int type);
		void addPoint(Vector3 Vertice);

		void dibujarFiguras(Vector3 posx1, Vector3 posy1, Vector3 posx2, Vector3 posy2, int red, int green, int blue);

	
};

