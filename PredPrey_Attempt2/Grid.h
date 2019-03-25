#pragma once
#include "Header.h"
#include "Cell.h"

class Grid

{
public:

	Grid(int width, int height, int predAge, int preyAge, double nPred, double nPrey);
	sf::VertexArray draw();
	void update();

private:
	int w, h, predA, preyA;
	double numPred, numPrey;
	std::vector<std::vector<Cell>> cells;
	sf::VertexArray buffer;
	
};