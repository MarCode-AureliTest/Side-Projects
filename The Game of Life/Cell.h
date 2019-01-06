#pragma once
#include <ofMain.h>
class Cell : public ofRectangle
{
public: 

	Cell();
	void set(int xin, int yin, int win, int hin, int occupyIn);
	void draw();
	void die();
	void alive();
	int getAlive();
	~Cell();

private:

	int isOccupied;

};

