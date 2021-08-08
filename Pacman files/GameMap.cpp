#include "GameMap.h"
#include "Consts.h"
#include "MIPT_pacman.h"
#include <ctime>


GameMap::GameMap()
{
	srand(static_cast<unsigned int>(time(0)));

	image_.loadFromFile("images/map/tiles_set.png");
	texture_.loadFromImage(image_);
	sprite_.setTexture(texture_);
 
	stringMap_[portal1_y][portal1_x] = portalTile;
	stringMap_[portal2_y][portal2_x] = portalTile;
}

void GameMap::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (stringMap_[i][j] == defaultMapTile)
				sprite_.setTextureRect(sf::IntRect(132, 40, 20, 21));
			else if (stringMap_[i][j] == waterTile)
				sprite_.setTextureRect(sf::IntRect(192, 239, 20, 21));
			else if (stringMap_[i][j] == bonfireTile)
				sprite_.setTextureRect(sf::IntRect(192, 1095, 20, 21));
			else if (stringMap_[i][j] == borderTile)
				sprite_.setTextureRect(sf::IntRect(172, 239, 20, 21));
			else if (stringMap_[i][j] == goldTile)
				sprite_.setTextureRect(sf::IntRect(450, 1214, 20, 21));
			else if (stringMap_[i][j] == portalTile)
				sprite_.setTextureRect(sf::IntRect(191, 617, 21, 21));

			sprite_.setPosition(j * 20, i * 21);

			window.draw(sprite_);
		}
}

void GameMap::generateMap()
{
	std::cout << "int generateMap\n";
	int numberOfCoints = getRandomNumber(1, MaxGoldAmount);
	lastGeneratedNumberOfCoints = numberOfCoints;

	for (int i = 0; i < numberOfCoints; i++)
	{
		int x = getRandomNumber(1, WIDTH_MAP - 1 - 1);
		int y = getRandomNumber(1, HEIGHT_MAP - 1 - 1);

		if(stringMap_[y][x] == defaultMapTile) // если дефолтная плитка, но на её месте генерируем монетку
			stringMap_[y][x] = goldTile;
		else
		{
			--i;
			continue;
		}

		/*if ((x != portal1_x) && (x != portal2_x)) // если x не совпадает с порталами
			stringMap_[y][x] = goldTile;
		else if ((y != portal1_y) && (y != portal2_y)) // если совпали x, то остлалось проверить по у
			stringMap_[y][x] = goldTile;
		else // повторяем эту итерацию еще раз
		{
			--i;
			continue;
		}*/
	}

}