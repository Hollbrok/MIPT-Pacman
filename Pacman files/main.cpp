#include "Player.h"
#include "GameMap.h"
#include "playerView.h"
#include "MIPT_pacman.h"
#include "drawText.h"
#include "Consts.h"
#include "DEBUG_STAFF.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 960), "MIPT Pacman");
	playerView.reset(sf::FloatRect(0, 0, 640, 480));

	Player mainHero("main3.png", 320, 240, 25, 32);
	mainHero.setView(&playerView);

	GameMap map{};

	mainHero.setMap(map);

	sf::Clock clock;

	float currentFrame{ 0 };
	float time{0};

	float fps{ 0 };
	std::chrono::high_resolution_clock::time_point start;

	sf::Font mainFont;
	mainFont.loadFromFile("text/1.ttf");

	sf::Text goldCollectedText("", mainFont, 20);
	goldCollectedText.setFillColor(sf::Color::Black);


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

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		if (isPressedMovementButton())
		{
			mainHero.move(currentFrame, time);
			getView(mainHero.getX(), mainHero.getY());

		}

		if(needMouseMovement)
			mainHero.cameraMovement(window, time, needMouseCoords); // если нужно мышкой двигать карту. третья константа еще и в добавок нужно выводить координаты положения мышки
		else if (needMouseCoords)									// если движение карты не нужно, НО нужны координаты мышки, то выводим их
		{
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			std::cout << "LocPos : " << localPosition.x << ' ' << localPosition.y << std::endl;
		}


		mainHero.update(time);
		start = std::chrono::high_resolution_clock::now();

		window.setView(playerView);

		window.clear();

		mainHero.getMap().draw(window);
		window.draw(mainHero.getSprite());
		drawText(window, goldCollectedText, mainHero);

		window.display();

		fps = (float)1e9 / (float)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count();
		const std::string title = "MIPT PacMan (" + std::to_string(int(fps)) + " fps)";
		window.setTitle(title);

	}


	

	return 0;
}