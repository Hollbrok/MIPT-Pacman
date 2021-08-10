#pragma once


#include "PlayerBase.h"

class Enemy : public PlayerBase
{
private:


public:

	Enemy(sf::String file, sf::String name, float x, float y, int width, int height, GameMap& map);
	Enemy(sf::Image image, sf::String name, float x, float y, int width, int height, GameMap& map);


	void move(float & currentFrame, float time);
	void update(float time);
};

