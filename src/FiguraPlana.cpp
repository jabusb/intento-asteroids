#include "FiguraPlana.h"

void FiguraPlana::init(Line & linea)
{
	transform = Matriz3();
	pos = Vector3(0, 0);
	angulo = 0; 
	escalar = Vector3(1, 1); 

}

void FiguraPlana::update(Line & linea, int type)
{
	vector<Vector3>dibujarpuntos = puntos; 
	setTransform();
	for (int i = 0; i < dibujarpuntos.size(); i++) {
		dibujarpuntos[i] = transform*puntos[i];

	}
	dibujarFiguras(type, linea, dibujarpuntos);
}

void FiguraPlana::addPoint(Vector3 Vertice)
{
	puntos.push_back(Vertice); 
}

void FiguraPlana::dibujarFiguras(Vector3 posx1, Vector3 posy1, Vector3 posx2, Vector3 posy2, int red, int green, int blue)
{

}
