#include "Player.h"
#include "GameMap.h"
#include "playerView.h"
#include "MIPT_pacman.h"
#include "drawText.h"
#include "Consts.h"
#include "DEBUG_STAFF.h"
#include "Enemy.h"
#include "ObjectsList.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 960), "MIPT Pacman");
	playerView.reset(sf::FloatRect(0, 0, 640, 480));

	GameMap map{};
	map.generateMap();

	Player mainHero(sf::String("main3.png"), sf::String("MAIN"), 320, 240, 25, 32, &map);
	mainHero.setView(&playerView);

	sf::Image sonic;
	sonic.loadFromFile("images/sonic.gif");
	sonic.createMaskFromColor(sf::Color(0, 128, 0));


	std::vector<Enemy> enemyVector;

	Enemy enemy1(sonic, sf::String("1Enemy"), 400, 120, 42, 34, &map);
	Enemy enemy2(sonic, sf::String("2Enemy"), 500, 400, 46, 35, &map);

	enemyVector.push_back(enemy1);
	enemyVector.push_back(enemy2);

	ObjectsList<Enemy> objectsList(enemyVector);
	//Enemy enemy1(sonic, sf::String("1Enemy"), 400, 120, 42, 34, map);
	//Enemy enemy2(sonic, sf::String("2Enemy"), 500, 400, 46, 35, map);
	
	//mainHero.setMap(map);

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
			mainHero.cameraMovement(window, time, needMouseCoords); // ���� ����� ������ ������� �����. ������ ��������� ��� � � ������� ����� �������� ���������� ��������� �����
		else if (needMouseCoords)									// ���� �������� ����� �� �����, �� ����� ���������� �����, �� ������� ��
		{
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			std::cout << "LocPos : " << localPosition.x << ' ' << localPosition.y << std::endl;
		}


		mainHero.update(time);

		objectsList.update(time);

		start = std::chrono::high_resolution_clock::now();

		window.setView(playerView);

		window.clear();

		mainHero.getMap().draw(window);
		
		window.draw(mainHero.getSprite());
		
		objectsList.draw(window);

		drawText(window, goldCollectedText, mainHero);

		window.display();

		fps = (float)1e9 / (float)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count();
		const std::string title = "MIPT PacMan (" + std::to_string(int(fps)) + " fps)";
		window.setTitle(title);

	}


	

	return 0;
}