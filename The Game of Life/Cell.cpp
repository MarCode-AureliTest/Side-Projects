#include "Cell.h"



Cell::Cell()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	isOccupied = 0;
}

void Cell::set(int xin, int yin, int win, int hin, int occupyIn)
{
	x = xin;
	y = yin;
	width = win;
	height = hin;
	isOccupied = occupyIn;
}

void Cell::draw()
{
	if (isOccupied > 0)
	{
		ofSetColor(0, 255, 0);
		ofDrawRectangle(x, y, width, height);
	}
}

void Cell::die()
{
	isOccupied = 0;
}

int Cell::getAlive()
{
	return(isOccupied);
}

void Cell::alive()
{
	isOccupied = 1;
}

Cell::~Cell()
{
}
