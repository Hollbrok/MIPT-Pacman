#ifndef PLAYER_VIEW_H
#define PLAYER_VIEW_H

#pragma once

#include "libraries.h"

sf::View playerView{};

sf::View& getView(float x, float y)
{
	x = x < 320 ? 320 : x;
	x = x > 640 ? 640 : x;

	y = y < 240 ? 240 : y;
	y = y > 480 ? 480 : y;


	playerView.setCenter(x, y);
	return playerView;
}

#endif