#ifndef GAMEMAP_H
#define GAMEMAP_H


#pragma once

#include "libraries.h"

class GameMap
{
private:

	sf::Image image_;
	sf::Texture texture_;
	sf::Sprite sprite_;

public:

	GameMap();

	void draw(sf::RenderWindow & window);
};

#endif

