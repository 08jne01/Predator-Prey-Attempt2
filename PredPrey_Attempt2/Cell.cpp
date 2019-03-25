#include "Cell.h"

Cell::Cell(int typ, int posX, int posY, int predAge, int preyAge, int edge): type(typ), x(posX), y(posY), predA(predAge), preyA(preyAge), edgeCell(edge)

{
	if (typ == RANDOMTYPE)

	{
		type = random(BLANK, PREY);
	}

	switch (type)

	{

		case BLANK:

		{
			age = 0;
			break;
		}

		case PRED:

		{
			age = predA;
			break;
		}

		case PREY:

		{
			age = 0;
			break;
		}
	}
	direction = random(LEFT, DOWN);
}

int Cell::getType()

{
	return type;
}

int Cell::random(int min, int max)

{
	return rand() % (max - min + 1) + min;
}

int Cell::getEdge()

{
	return edgeCell;
}

int Cell::getDirection()

{
	return direction;
}

void Cell::setType(int typ)

{
	type = typ;
}

void Cell::update(Cell *near, int edge)

{
	direction = random(LEFT, DOWN);
	//std::cout << direction << " ";

	if (type == BLANK || edge == 1)

	{
		return;
	}

	move(near);

}


void Cell::move(Cell *into)

{
	if (into->getEdge() == 1)

	{
		switch (type)

		{

			case BLANK:

			{
				age = 0;
				break;
			}

			case PRED:

			{
				age += -1;
				if (age < 0)

				{
					age = 0;
					type = BLANK;
				}
				break;
			}

			case PREY:

			{
				age += 1;
				break;
			}
		}
		return;
	}


	switch (type)

	{

		case BLANK:

		{
			break;
		}

		case PRED:

		{
			if (age < 0)

			{
				age = 0;
				type = BLANK;
				break;
			}

			switch (into->getType())

			{

				case BLANK:

				{
					age += -1;
					into->setType(PRED);
					into->setAge(age);
					age = 0;
					type = BLANK;
					break;
				}

				case PRED:

				{
					age += -1;
					break;
				}

				case PREY:

				{
					age = predA;
					into->setType(PRED);
					into->setAge(predA);
					break;
				}
			}
			break;
		}

		case PREY:

		{
			switch (into->getType())

				{

				case BLANK:

				{
					age += 1;

					if (age > preyA)

					{
						into->setType(PREY);
						into->setAge(0);
						age = 0;
					}

					else

					{
						age += 1;
						into->setType(PREY);
						into->setAge(age);
						age = 0;
						type = BLANK;
					}
					break;
				}

				case PRED:

				{
					age += 1;
					break;
				}

				case PREY:

				{
					age += 1;
					break;
				}	
			}
			break;
		}
	}
}

void Cell::setAge(int a)

{
	age = a;
}