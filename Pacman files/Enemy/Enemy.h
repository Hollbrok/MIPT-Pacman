#pragma once


#include "PlayerBase.h"

class Enemy : public PlayerBase
{
private:

public:
	int typeOfEnemy_;


	Enemy(sf::String file, sf::String name, float x, float y, int width, int height, GameMap * map);
	Enemy(sf::Image image, sf::String name, float x, float y, int width, int height, GameMap * map);


	void move(float & currentFrame, float time);
	void update(float time);

	/*Enemy& operator=(const Enemy& enemy)
	{
		PlayerBase::operator=(enemy);
		typeOfEnemy_ = enemy.typeOfEnemy_;
	}*/

};

