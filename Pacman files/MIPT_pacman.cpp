#include "MIPT_pacman.hpp"
#include "libraries.hpp"

const int BAD_DIRECTION = 100;

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