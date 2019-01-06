#include "CellBoard.h"



CellBoard::CellBoard()
{
	cellMax = 500;
	for (int j = 0; j < cellMax; j++)
	{
		for (int i = 0; i < cellMax; i++)
		{
			int dice = rand() % 15;
			if (dice != 0)matrix[i][j].set(5 * i, 5 * j, 5, 5, 0);
			else matrix[i][j].set(5 * i, 5 * j, 5, 5, 1);
		}
	}
}
void CellBoard::draw()
{
	for (int j = 0; j < cellMax; j++)
	{
		for (int i = 0; i < cellMax; i++)
		{
			matrix[i][j].draw();
		}
	}
}
/*
For a space that is 'populated':
    Each cell with one or no neighbors dies, as if by solitude. 
    Each cell with four or more neighbors dies, as if by overpopulation. 
    Each cell with two or three neighbors survives. 
For a space that is 'empty' or 'unpopulated'
    Each cell with three neighbors becomes populated. 
*/
void CellBoard::update()
{
	int liveNeighbors = 0;
	for (int j = 0; j < cellMax; j++)
	{
		for (int i = 0; i < cellMax; i++)
		{
			liveNeighbors = checkNeighbor(i, j);
			if (liveNeighbors < 2 || liveNeighbors > 3) matrix[i][j].die();
			if (liveNeighbors == 3 && matrix[i][j].getAlive() == 0) matrix[i][j].alive();
		}
	}
}

int CellBoard::checkNeighbor(int iIn, int jIn)
{
	int liveNeighbors = 0;
	for (int j = -1; j < 2; j++)
	{
		for (int i = -1; i < 2; i++)
		{
			if (i == 0 && j == 0) liveNeighbors = liveNeighbors;
			else if (matrix[iIn + i][jIn + j].getAlive() == 1) liveNeighbors = liveNeighbors + 1;
		}
	}
	return(liveNeighbors);
}

CellBoard::~CellBoard()
{
}
