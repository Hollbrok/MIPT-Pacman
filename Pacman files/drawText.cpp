#include "Player.h"

#include "drawText.h"

void drawText(sf::RenderWindow & window, sf::Text & goldCollectedText, Player & mainHero)
{
	std::ostringstream totalGold;
	std::ostringstream ostr;
	ostr << mainHero.getGold();
	std::string theNumberString = ostr.str();

	goldCollectedText.setString("Total gold collected: " + theNumberString);
	
	goldCollectedText.setPosition(mainHero.getView().getCenter().x + 100, mainHero.getView().getCenter().y - 220);
	//goldCollectedText.setPosition(getLogicPosition(mainHero.getX(), mainHero.getY()));
	
	window.draw(goldCollectedText);
}

const sf::Vector2f & getLogicPosition(float x, float y) // эквивалент работа через метод const sf::Vector2f & sf::View::getCenter()
{
	x = x < 640 ? x + 100 : 640 + 100;
	x = x > 320 + 100 ? x : 320 + 100;

	y = y < 480 ? y - 200 : 480 - 200;
	y = y > 40 ? y : 140 - 100;

	sf::Vector2f position{x, y};

	return position;
}