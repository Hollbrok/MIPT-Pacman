#pragma once
#include "ObjectsList.h"


template <typename objectType>
ObjectsList<objectType>::ObjectsList(std::vector<objectType> & vector) :
	vector_()
{
	vector_ = vector;
	//std::copy(vector.begin(), vector.end(), vector_.begin());
	vectorSize_ = vector_.size();

	std::cout << "size " << vectorSize_ << std::endl;
}

template <typename objectType>
void ObjectsList<objectType>::update(float time)
{
	for (auto& i : vector_)
	{
		i.update(time);
	}
}

template <typename objectType>
void ObjectsList<objectType>::draw(sf::RenderWindow & window)
{
	for (auto & i : vector_)
	{
		window.draw(i.getSprite());
	}
}

template <typename objectType>
sf::Sprite ObjectsList<objectType>::getSprite(int numberOfSprite)
{
	return vector_[numberOfSprite].getSprite();
}


