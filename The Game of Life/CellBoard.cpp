#include "CellBoard.h"


//initializes empty cellboard
CellBoard::CellBoard()
{
	cellMax = 500;
	for (int j = 0; j < cellMax; j++)
	{
		for (int i = 0; i < cellMax; i++)
		{
			matrix[i][j].set(5 * i, 5 * j, 5, 5, 0);
		}
	}
}

void CellBoard::clear()
{
	for (int j = 0; j < cellMax; j++)
	{
		for (int i = 0; i < cellMax; i++)
		{
			matrix[i][j].die();
		}
	}
}

//randomly generates colonies and plays simulation
void CellBoard::randomGrowth()
{
	clear();
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

//presents the still-life patterns
void CellBoard::stillLifes()
{
	clear();
	//displays "block" still-life
	block(50);
	//displays "beehive" still-life
	beehive(50, 54);

}

void CellBoard::block(int offset)
{
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			matrix[offset + i][offset + j].alive();
		}
	}
}

void CellBoard::beehive(int xoffset, int yoffset)
{
	matrix[xoffset][yoffset].alive();
	matrix[xoffset - 1][yoffset + 1].alive();
	matrix[xoffset - 1][yoffset + 2].alive();
	matrix[xoffset][yoffset + 3].alive();
	matrix[xoffset + 1][yoffset + 1].alive();
	matrix[xoffset + 1][yoffset + 2].alive();
}

void CellBoard::loaf(int xoffset, int yoffset)
{

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

//Checks neighbors of cell and returns how many alive neighbors 
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
