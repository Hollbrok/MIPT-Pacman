#include "libraries.hpp"

#include "Player.h"
#include "MIPT_pacman.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "MIPT Pacman");

	Player mainHero("main3.png", 320, 240, 25, 32);

	sf::Clock clock;

	float currentFrame{ 0 };
	float time{0};

	float fps{ 0 };
	std::chrono::high_resolution_clock::time_point start;


	while (window.isOpen())
	{
		sf::Event event;
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (isPressedMovementButton())
			mainHero.move(currentFrame, time);

		mainHero.update(time);
		
		start = std::chrono::high_resolution_clock::now();

		window.clear();
		window.draw(mainHero.getSprite());
		window.display();

		fps = (float)1e9 / (float)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count();
		const std::string title = "Raycasting (" + std::to_string((double)fps) + " fps)";
		window.setTitle(title);

	}


	

	return 0;
}