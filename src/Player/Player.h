#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include "libraries.h"

#include "PlayerBase.h"



class Player : public PlayerBase	
{
private:

	enum class MoveDir 
	{
		up, left, down, right, stay
	} stay_;

	int goldCounter_ = 0;

public:

	int lastGoldCounter = 0;

// GETTERS


	int & getGold() { return goldCounter_; }
	const int & getGold() const { return goldCounter_; }


// SETTERS



//

	Player(sf::String file, sf::String name, float x, float y, int width, int height, GameMap * map);
	Player(sf::Image image, sf::String name, float x, float y, int width, int height, GameMap * map);

	void move(float & currentFrame, float time);
	void update(float time);
	void gameLogic();
	void cameraMovement(sf::RenderWindow& window, float time, bool needMouseCoords = false);

};



#endif