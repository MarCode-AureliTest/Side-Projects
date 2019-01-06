#pragma once
#include "Cell.h"
class CellBoard
{
public:

	int cellMax; //maximum number of cells contained on board
	Cell matrix[2000][2000];

	CellBoard();
	~CellBoard();

	void clear();
	void randomGrowth();
	void stillLifes();
	void block(int offset);
	void beehive(int xoffset, int yoffset);
	void loaf(int xoffset, int yoffset);

	void draw();
	void update();
	int checkNeighbor(int iIn, int jIn);
};

