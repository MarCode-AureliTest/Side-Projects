#pragma once
#include "Cell.h"
class CellBoard
{
public:

	int cellMax;
	Cell matrix[1500][1500];

	CellBoard();
	~CellBoard();
	void setup();
	void draw();
	void update();
	int checkNeighbor(int iIn, int jIn);
};

