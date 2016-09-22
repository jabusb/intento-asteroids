#pragma once
#include "Pixels.h"


class Line {
public:
	Pixels pixel;
	
	int x1, x2; 
	int y1, y2; 

	int dX, dY;
	int a, b; 

	int d = 2 * (a + b);

	int x, y; 

	int tempXi, tempXf, tempYi, tempYf; 

	bool filter; 
	int changeLine, val;

	void init();
	void Linea(int x1, int y1, int x2, int y2, int red, int green, int blue);
	
	void update();
	void draw();

};