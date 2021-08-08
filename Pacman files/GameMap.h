#ifndef GAMEMAP_H
#define GAMEMAP_H
#pragma once

#include "libraries.h"
#include "Consts.h"


class GameMap
{
private:

	sf::Image image_;
	sf::Texture texture_;
	sf::Sprite sprite_;

public:

	int lastGeneratedNumberOfCoints = 0;

	sf::String stringMap_[HEIGHT_MAP] = {
	"000000000000000000000000000000000000000000000000",
	"0                                              0",
	"0   wwwwwwwwwww                                0",
	"0   wwwwwwwwwww                                0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                   f                          0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"000000000000000000000000000000000000000000000000",
	};

	GameMap();

	void draw(sf::RenderWindow & window);

	void generateMap();
};

#endif

