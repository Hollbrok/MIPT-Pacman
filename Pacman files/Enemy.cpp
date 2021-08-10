#include "MIPT_pacman.h"
#include "Consts.h"
#include "Enemy.h"


Enemy::Enemy(sf::String file, sf::String name, float x, float y, int width, int height, GameMap& map) :
	PlayerBase(file, name, x, y, width, height, map)
{

	image_.createMaskFromColor(sf::Color(0, 128, 0));
	texture_.loadFromImage(image_);								
	sprite_.setTexture(texture_);
	
	if (name == "1Enemy")
	{
		moveTime_ = 0.0f;
		dy_ = 0.1;
		sprite_.setTextureRect(sf::IntRect(4, 18, width_, height_));
	}
	else if (name == "2Enemy")
	{
		moveTime_ = 0.0f;
		dx_ = 0.1;
		sprite_.setTextureRect(sf::IntRect(249, 400, width_, height_));
	}
	else
	{
		;
	}
}

Enemy::Enemy(sf::Image image, sf::String name, float x, float y, int width, int height, GameMap& map) :
	PlayerBase(image, name, x, y, width, height, map)
{
	if (name == "1Enemy")
	{
		moveTime_ = 0.0f;
		dy_ = 0.2;
		sprite_.setTextureRect(sf::IntRect(4, 18, width_, height_));
	}
	else if (name == "2Enemy")
	{
		moveTime_ = 0.0f;
		dx_ = 0.2;
		sprite_.setTextureRect(sf::IntRect(249, 400, width_, height_));
	}
	else
	{
		;
	}
}

void Enemy::move(float& currentFrame, float time)
{

}

void Enemy::update(float time)
{
	moveTime_ += time;
	if (moveTime_ > 1000)
	{
		dx_ *= -1;
		dy_ *= -1;
		moveTime_ -= 1000;
	}

	x_ += dx_ * time;
	y_ += dy_ * time;

	sprite_.setPosition(x_, y_);
}