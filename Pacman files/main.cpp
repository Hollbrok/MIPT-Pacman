#include "libraries.hpp"
#include "Player.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "MIPT Pacman");

	Player mainHero("main3.png", 320, 240, 25, 32);

	sf::Clock clock;

	float CurrentFrame{ 0 };
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			mainHero.setMoveDir(1);
			mainHero.setSpeed(0.1);
			CurrentFrame += 0.01 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			mainHero.getSprite().setTextureRect(sf::IntRect(79 + int(CurrentFrame) * (25 + 7), 40, 25, 32)); //через объект mainHero класса player меняем спрайт, делая анимацию
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			mainHero.setMoveDir(3);
			mainHero.setSpeed(0.1);
			CurrentFrame += 0.01 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			mainHero.getSprite().setTextureRect(sf::IntRect(76 + int(CurrentFrame) * (25 + 7), 72, 25, 32)); //через объект mainHero класса player меняем спрайт, делая анимацию
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			mainHero.setMoveDir(2);
			mainHero.setSpeed(0.1);
			CurrentFrame += 0.01 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			mainHero.getSprite().setTextureRect(sf::IntRect(77 + int(CurrentFrame) * (28 + 4), 8, 28, 32)); //через объект mainHero класса player меняем спрайт, делая анимацию
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			mainHero.setMoveDir(0);
			mainHero.setSpeed(0.1);
			CurrentFrame += 0.01 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			mainHero.getSprite().setTextureRect(sf::IntRect(76 + int(CurrentFrame) * (28 + 4), 104, 28, 32)); //через объект mainHero класса player меняем спрайт, делая анимацию
		}


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