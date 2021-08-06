#include "Player.h"
#include "MIPT_pacman.hpp"

Player::Player(sf::String file, float x, float y, int width, int height) :
	x_(x),
	y_(y),
	dx_(0),
	dy_(0),
	speed_(0),
	moveDirection_(0),
	width_(width),
	height_(height),
	file_(file)
{
	image_.loadFromFile("images/" + file_);						// ����������� image_ � ����� ������������ ������ � ������� ����� ������������
	//image_.createMaskFromColor(sf::Color(255, 255, 255));		// ���� ����� ������ ������ ���� � �����������
	texture_.loadFromImage(image_);								// ����������� �������� � ������������
	sprite_.setTexture(texture_);								// �������� ������ ���������
	sprite_.setTextureRect(sf::IntRect(0, 150, width_, height_));	// ������ ������� ���� ������������� ������� ������� ���������.
}

void Player::move(float & currentFrame, float time)
{
	int dir = defineDirection();
	switch (dir)
	{
		using namespace MP_directions;
	case UP:
		setMoveDir(0);
		setSpeed(0.1);
		currentFrame += 0.01 * time;
		if (currentFrame > 3) currentFrame -= 3;
		getSprite().setTextureRect(sf::IntRect(76 + int(currentFrame) * (28 + 4), 104, 28, 32)); //����� ������ mainHero ������ player ������ ������, ����� ��������
		break;
	case LEFT:
		setMoveDir(1);
		setSpeed(0.1);
		currentFrame += 0.01 * time;
		if (currentFrame > 3) currentFrame -= 3;
		getSprite().setTextureRect(sf::IntRect(79 + int(currentFrame) * (25 + 7), 40, 25, 32)); //����� ������ mainHero ������ player ������ ������, ����� ��������
		break;
	case DOWN:
		setMoveDir(2);
		setSpeed(0.1);
		currentFrame += 0.01 * time;
		if (currentFrame > 3) currentFrame -= 3;
		getSprite().setTextureRect(sf::IntRect(77 + int(currentFrame) * (28 + 4), 8, 28, 32)); //����� ������ mainHero ������ player ������ ������, ����� ��������
		break;
	case RIGHT:
		setMoveDir(3);
		setSpeed(0.1);
		currentFrame += 0.01 * time;
		if (currentFrame > 3) currentFrame -= 3;
		getSprite().setTextureRect(sf::IntRect(76 + int(currentFrame) * (25 + 7), 72, 25, 32)); //����� ������ mainHero ������ player ������ ������, ����� ��������
		break;
	default:
		std::cerr << "ERROR IN LINE:" << __LINE__ << std::endl;
	}
}

void Player::update(float time) // time -- ����� SFML
{
	switch (moveDirection_)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
	{
	case 0: // UP - W
			dx_ = 0;
			dy_ = -speed_;
			break;	
	case 1: // LEFT - A
			dx_ = -speed_;
			dy_ = 0;
			break;	
	case 2:  // DOWN - S
			dx_ = 0; 
			dy_ = speed_;
			break;
	case 3: // RIGHT - D
			dx_ = speed_;
			dy_ = 0;
			break;
	}

	x_ += dx_ * time;	
	y_ += dy_ * time;	

	speed_ = 0;						// ��������� ��� ��������. ���� �� ��������, �� ����� ��� � ������
	sprite_.setPosition(x_, y_);	// ��������� ������� �������
}