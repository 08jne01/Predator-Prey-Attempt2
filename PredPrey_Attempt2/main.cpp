#include "Header.h"
#include "Program.h"

int main()

{
	sf::err().rdbuf(NULL);

	Program p(700, 700, 2000, 100, 10, 0.0005, 0.01);

	return p.mainLoop();
}