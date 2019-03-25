#pragma once
#include "Header.h"

class Cell

{
public:

	Cell(int typ, int posX, int posY, int predAge, int preyAge, int edge);
	int getType();
	int random(int min, int max);
	int getEdge();
	int getDirection();
	void setType(int typ);
	void setAge(int a);
	void update(Cell *near, int edge);
	void move(Cell *into);

private:

	int type, x, y, direction, age, predA, preyA, edgeCell;

};