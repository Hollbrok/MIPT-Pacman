#include "Player.h"
#include "GameMap.h"
#include "playerView.h"
#include "MIPT_pacman.h"
#include "drawText.h"

const int BAD_DIRECTION = 100;

const int UP = 0;
const int LEFT = 1;
const int DOWN = 2;
const int RIGHT = 3;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 960), "MIPT Pacman");
	playerView.reset(sf::FloatRect(0, 0, 640, 480));

	Player mainHero("main3.png", 320, 240, 25, 32);
	mainHero.setView(&playerView);

	GameMap map{};

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

		/* sf::Vector2i localPosition = sf::Mouse::getPosition(window);					// camera movement
		
		int cameraMoveDir = getCameraMoveDirection(localPosition.x, localPosition.y, window.getSize().x, window.getSize().y);

		if (cameraMoveDir == BAD_DIRECTION)
			;// we dont need to move camera
		else if (cameraMoveDir == UP)
			mainHero.getView().move(0, -0.2 * time);
		else if (cameraMoveDir == LEFT)
			mainHero.getView().move(-0.2 * time, 0);
		else if (cameraMoveDir == DOWN)
			mainHero.getView().move(0, 0.2 * time);
		else if (cameraMoveDir == RIGHT)
			mainHero.getView().move(0.2 * time, 0);
		else
			std::cout << "LOGIC_ERROR in line : " << __LINE__ << std::endl;
		
		//std::cout << "LocPos : " << localPosition.x << ' ' << localPosition.y << std::endl;
		*/

		mainHero.update(time);
		start = std::chrono::high_resolution_clock::now();

		window.setView(playerView);


		window.clear();

		map.draw(window);
		window.draw(mainHero.getSprite());
		drawText(window, goldCollectedText, mainHero);

		window.display();

		fps = (float)1e9 / (float)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count();
		const std::string title = "MIPT PacMan (" + std::to_string(int(fps)) + " fps)";
		window.setTitle(title);

	}


	

	return 0;
}