#include "MIPT_pacman.h"
#include "libraries.h"

const int BAD_DIRECTION = 100;

const int UP = 0;
const int LEFT = 1;
const int DOWN = 2;
const int RIGHT = 3;

bool isPressedUpButton()
{
	return	sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::W);
}

bool isPressedLeftButton()
{
	return	sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::A);
}

bool isPressedDownButton()
{
	return	sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}
bool isPressedRightButton()
{
	return	sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::D);
}

bool isPressedMovementButton()
{
	return (isPressedUpButton()   || isPressedLeftButton() ||
			isPressedDownButton() || isPressedRightButton());
}

int defineDirection()
{
	if (isPressedUpButton())
		return 0;
	if (isPressedLeftButton())
		return 1;
	if (isPressedDownButton())
		return 2;
	if (isPressedRightButton())
		return 3;
	return BAD_DIRECTION;
}

int getCameraMoveDirection(int x, int y, int windowSizeX, int windowSizeY)
{
	if (y < 2)
		return UP;
	if (x < 2)
		return LEFT;
	if (y > windowSizeY - 2)
		return DOWN;
	if (x > windowSizeX - 2)
		return RIGHT;
	return BAD_DIRECTION;
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем рандомное число в нашем диапазоне
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}