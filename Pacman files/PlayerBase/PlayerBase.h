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

	GameMap* gameMap_;

	bool isLife_ = true;
	bool isMove_ = false;

//
public:


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

	sf::Texture& getTexture() { return texture_; }
	const sf::Texture& getTexture() const { return texture_; }


	sf::Image& getImage() { return image_; }
	const sf::Image& getImage() const { return image_; }

	sf::View& getView() { return *playerView_; }
	//const sf::View& getView() const { return *playerView_; }

	//const sf::View getView() const { return *playerView_; }

	sf::String& getName() { return name_; }
	const sf::String& getName() const { return name_; }

	sf::String& getFile() { return file_; }
	const sf::String& getFile() const { return file_; }


	GameMap* getPMap() { return gameMap_; }

	GameMap & getMap() { return *gameMap_; }
	const GameMap & getMap() const { return *gameMap_; }

	float & getMoveTimer() { return moveTime_; }
	const float& getMoveTimer() const { return moveTime_; }


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

	void setMap(GameMap * map) { gameMap_ = map; }

	//
	PlayerBase(sf::String file, sf::String name, float x, float y, int width, int height, GameMap * map);
	PlayerBase(sf::Image image, sf::String name, float x, float y, int width, int height, GameMap * map);

	/*PlayerBase& operator=(const PlayerBase& obj)
	{
		x_ = obj.getX();
		y_ = obj.getY();

		dx_ = obj.getDx();
		dy_ = obj.getDy();;

		speed_ = obj.getSpeed();
		moveDirection_ = obj.getMoveDirection();


		width_ = obj.getW();		
		height_ = obj.getH();		

		moveTime_ = obj.getMoveTimer();
		name_ = obj.getName();

		file_ = obj.getFile();
		image_ = obj.getImage();
		texture_ = obj.getTexture();
		sprite_ = obj.getSprite();
		playerView_ = obj.getView();

		gameMap_ = obj.getPMap();

		isLife_ = true;
		isMove_ = false;
	}*/
};

