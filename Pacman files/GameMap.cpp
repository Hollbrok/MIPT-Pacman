#include "gameMap.h"

const int HEIGHT_MAP = 23;
const int WIDTH_MAP = 32;

const char defaultMapTile	= ' ';
const char waterTile		= 'w';
const char bonfireTile		= 'f';
const char borderTile		= '0';

sf::String TileMap[HEIGHT_MAP] = {
	"00000000000000000000000000000000",
	"0                              0",
	"0   wwwwwwwwwww                0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                   ff         0",
	"0                   ff         0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0               w              0",
	"0               w              0",
	"0     wwwwwwwwwww              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"00000000000000000000000000000000",
};

GameMap::GameMap()
{
	image_.loadFromFile("images/map/tiles_set.png");
	texture_.loadFromImage(image_);
	sprite_.setTexture(texture_);
}

void GameMap::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == defaultMapTile)
				sprite_.setTextureRect(sf::IntRect(132, 40, 20, 21));
			else if (TileMap[i][j] == waterTile)
				sprite_.setTextureRect(sf::IntRect(192, 239, 20, 21));
			else if (TileMap[i][j] == bonfireTile)
				sprite_.setTextureRect(sf::IntRect(172, 1095, 20, 21));
			else if (TileMap[i][j] == borderTile)
				sprite_.setTextureRect(sf::IntRect(172, 239, 20, 21));

			sprite_.setPosition(j * 20, i * 21);

			window.draw(sprite_);
		}
}