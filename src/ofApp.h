#pragma once

#include "ofMain.h"
#include "FiguraPlana.h"
#include "Line.h"

class ofApp : public ofBaseApp{

	public:

		Line line; 
		Vector3 fuerza, direccion;
		FiguraPlana figura, nave, llama, bala, muerteydestruccion;
		//vector<bool> drawbala;
		bool drawBoolean, drawnave, drawLlama, drawBala, drawmuerteydestruccion;
		bool llama, rotacionNave;
		float angulo;

		void createNave();
		void createBala(int &bala);
		void createllama();
		void muerteydestruccion();

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
