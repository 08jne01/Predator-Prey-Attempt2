#pragma once
#include "Header.h"
#include "Grid.h"
#include "Cell.h"

class Program

{

public:

	Program(int width, int height, int tickRate, int predAge, int preyAge, double nPred, double nPrey);
	int mainLoop();
	void update();
	void draw(sf::VertexArray *ptr);

private:

	int w, h, tick;
	Grid grid;
};