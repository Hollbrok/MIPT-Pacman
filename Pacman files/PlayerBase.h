#pragma once

#include "libraries.h"
#include "GameMap.h"

class PlayerBase
{
public:

	float x_;
	float y_;

	float dx_;
	float dy_;

	float speed_;
	int moveDirection_;


	int width_;		// высота модельки
	int height_;	// ширина модельки

	float moveTime_;
	sf::String name_;

	sf::String file_;
	sf::Image image_;
	sf::Texture texture_;
	sf::Sprite sprite_;
	sf::View* playerView_;

	GameMap& gameMap_;

	bool isLife_ = false;
	bool isMove_ = false;

//public:


	// GETTERS

	float& getX() { return x_; }
	const float& getX() const { return x_; }

	float& getY() { return y_; }
	const float& getY() const { return y_; }

	float& getDx() { return dx_; }
	const float& getDx() const { return dx_; }

	float& getDy() { return dy_; }
	const float& getDy() const { return dy_; }

	float& getSpeed() { return speed_; }
	const float& getSpeed() const { return speed_; }

	int& getMoveDirection() { return moveDirection_; }
	const int& getMoveDirection() const { return moveDirection_; }

	int& getW() { return width_; }
	const int& getW() const { return width_; }

	int& getH() { return height_; }
	const int& getH() const { return height_; }

	sf::Sprite& getSprite() { return sprite_; }
	const sf::Sprite& getSprite() const { return sprite_; }


	sf::View& getView() { return *playerView_; }
	const sf::View& getView() const { return *playerView_; }

	GameMap& getMap() { return gameMap_; }
	const GameMap& getMap() const { return gameMap_; }


	// SETTERS

	void setX(float x) { x_ = x; }
	void setY(float y) { y_ = y; }

	void setDx(float dx) { dx_ = dx; }
	void setDy(float dy) { dy_ = dy; }

	void setSpeed(float speed) { speed_ = speed; }
	void setMoveDir(int moveDir) { moveDirection_ = moveDir; }

	void setWidth(int width) { width_ = width; }
	void setHeight(int height) { height_ = height; }

	void setView(sf::View* playerView) { playerView_ = playerView; };

	void setMap(GameMap& map) { gameMap_ = map; }

	//
	PlayerBase(sf::String file, sf::String name, float x, float y, int width, int height, GameMap & map);
	PlayerBase(sf::Image image, sf::String name, float x, float y, int width, int height, GameMap& map);

};

