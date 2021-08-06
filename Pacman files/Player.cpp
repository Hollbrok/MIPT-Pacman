#include "Player.h"

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