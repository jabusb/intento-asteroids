#include "Pixels.h"

void Pixels::putPixel(int x, int y, int r, int g, int b) {
	pix.setColor(x, y, (r, g, b)); // Inicialización del putpixel

}

void Pixels::centerScreen(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Pixels::cleanScreen()
{
	ofColor backColor;
	backColor.set(0, 0, 0, );
	for (int i = 0; 1 < ofGetWidth(); i++) {
		for (int j = 0; j < ofGetHeight(); j++) {
			pix.setColor(i, j, backColor);
		}
	}
}

void Pixels::getPixel() {
	tex.loadData(pix); // Carga los pixeles que serán del bitmap
	
}

void Pixels::init() {
	pix.allocate(1024, 768, OF_PIXELS_RGB); 
	tex.allocate(1024, 768, GL_RGB); // Canvas
		
		
}

void Pixels::draw() {
	tex.draw(0, 0);
}