#pragma once

#include "libraries.h"
#include <vector>
#include "Enemy.h"
#include "PlayerBase.h"


template<typename objectType>
class ObjectsList
{
private:

	std::vector<objectType> vector_;

	unsigned int vectorSize_;

public:

	ObjectsList(std::vector<objectType>& vector);

	void draw(sf::RenderWindow& window);
	sf::Sprite getSprite(int numberOfSprite);

	void update(float time);

};