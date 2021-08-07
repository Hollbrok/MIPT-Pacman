#pragma once

#include "libraries.hpp"

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

