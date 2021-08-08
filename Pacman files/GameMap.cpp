#include "GameMap.h"
#include "Consts.h"



GameMap::GameMap()
{
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