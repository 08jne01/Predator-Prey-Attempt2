#include "Grid.h"

Grid::Grid(int width, int height, int predAge, int preyAge, double nPred, double nPrey) : w(width), h(height), predA(predAge), preyA(predA), numPred(nPred), numPrey(nPrey)

{
	buffer.setPrimitiveType(sf::Points);
	int itt = 0;
	double pred = 0.0;
	double prey = 0.0;
	double fraction;

	for (int i = 0; i < width; i++)

	{
		std::vector<Cell> column;

		for (int j = 0; j < height; j++)

		{
			Cell c(RANDOMTYPE, i, j, predA, preyA, 0);
			itt++;
			fraction = (double)(itt) / (double)(width*height);

			//std::cout << numPrey*fraction  << " " << prey / (width * height) << " " <<  prey << std::endl;

			if (c.getType() == PREY)

			{
				if (numPrey*fraction < (prey / (width * height)))

				{
					c.setType(BLANK);
				}

				else

				{
					prey++;
				}
			}

			else if (c.getType() == PRED)

			{
				if (numPred*fraction < (pred/(width*height)))

				{
					c.setType(BLANK);
				}

				else

				{
					pred++;
				}

			}

			//std::cout << fraction << std::endl;

			column.push_back(c);
		}
		cells.push_back(column);
	}
}

sf::VertexArray Grid::draw()

{
	buffer.clear();

	for (int i = 0; i < cells.size(); i++)

	{

		for (int j = 0; j < cells[i].size(); j++)

		{
			sf::Color color;
			switch (cells[i][j].getType())

			{
				case BLANK:

				{
					break;
				}

				case PRED:

				{
					color = sf::Color(255, 10, 10, 255);
					buffer.append(sf::Vertex(sf::Vector2f(i, j), color));
					break;
				}

				case PREY:

				{
					color = sf::Color(10, 255, 10, 255);
					buffer.append(sf::Vertex(sf::Vector2f(i, j), color));
					break;
				}
			}
		}
	}
	return buffer;
	
}

void Grid::update()

{
	Cell blank(BLANK, -1, -1, predA, preyA, 1);

	std::vector<std::vector<Cell>> cellBuf = cells;

	for (int i = 0; i < cells.size(); i++)

	{

		for (int j = 0; j < cells[i].size(); j++)

		{
			
			Cell blank(BLANK, -1, -1, predA, preyA, 1);
			Cell *c = nullptr;
			int direction = cellBuf[i][j].getDirection();
			int edge = 0;

			switch (direction)

			{
				case LEFT:

				{
					if (i - 1 < 1)

					{
						c = &blank;
						edge = 1;
					}

					else

					{
						c = &cellBuf[i - 1][j];
					}
					break;
				}

				case RIGHT:

				{
					if (i + 1 > w-1)

					{
						c = &blank;
						edge = 1;
					}

					else

					{
						c = &cellBuf[i + 1][j];
					}
					break;
				}

				case UP:

				{
					if (j - 1 < 1)

					{
						c = &blank;
						edge = 1;
					}

					else

					{
						c = &cellBuf[i][j - 1];
					}
					break;
				}

				case DOWN:

				{
					if (j + 1 > h-1)

					{
						c = &blank;
						edge = 1;
					}

					else

					{
						c = &cellBuf[i][j + 1];
					}
					break;
				}
			}

			cellBuf[i][j].update(c, edge);

			//Cell c = near(cells[i][j].getDirection(), cells, i, j);
		}
	}

	cells = cellBuf;
}