#include "Header.h"
#include "Program.h"

Program::Program(int width, int height, int tickRate, int predAge, int preyAge, double nPred, double nPrey) : w(width), h(height), tick(tickRate), grid(width, height, predAge, preyAge, nPred, nPrey)

{
}



int Program::mainLoop()

{
	sf::RenderWindow window(sf::VideoMode(w, h), "Predator and Prey");
	sf::Event events;
	if (!window.isOpen())
	
	{
		std::cout << "Could not open window!" << std::endl;
		system("PAUSE");
		return EXIT_FAILURE;
	}

	double tickTime = 1000.0 / (double)tick;
	sf::VertexArray buffer;

	std::thread threadObj([&] 
	
	{
		double tickRate = 0.0;
		sf::Clock clock;
		sf::Clock fps;
		int frames = 1;
		while (window.isOpen())

		{
			if (clock.getElapsedTime().asMilliseconds() > tickTime)

			{
				grid.update();
				//std::cout << std::setprecision(3) << "\rTicks per second: " << clock.getElapsedTime().asMilliseconds() << "       ";
				clock.restart();
				frames++;
				if (frames > 10)

				{
					tickRate = (10 * 1000.0) / (double)(fps.getElapsedTime().asMilliseconds());
					int var = (fps.getElapsedTime().asMilliseconds());
					std::cout << std::setprecision(3) << "\rTicks per second: " << tickRate << "         ";
					frames = 1;
					fps.restart();
				}
			}

		}

	});

	threadObj.detach();

	while (window.isOpen())

	{

		while (window.pollEvent(events))

		{
			if (events.type == sf::Event::EventType::Closed)

			{
				window.close();
			}
		}

		
		window.clear(sf::Color::Black);
		window.draw(grid.draw());
		window.display();
	}
	return EXIT_SUCCESS;
}

void Program::draw(sf::VertexArray *ptr)

{
	*ptr = grid.draw();
}

void Program::update()

{
}