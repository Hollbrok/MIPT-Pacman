#include "PlayerBase.h"

PlayerBase::PlayerBase(sf::String file, sf::String name, float x, float y, int width, int height, GameMap & map) :
	x_(x),
	y_(y),
	dx_(0),
	dy_(0),
	speed_(0),
	moveDirection_(0),
	width_(width),
	height_(height),
	name_(name),
	file_(file),
	gameMap_(map)
{
	image_.loadFromFile("images/" + file_);						// ����������� image_ � ����� ������������ ������ � ������� ����� ������������
	//image_.createMaskFromColor(sf::Color(255, 255, 255));		// ���� ����� ������ ������ ���� � �����������
	texture_.loadFromImage(image_);								// ����������� �������� � ������������
	
	sprite_.setTexture(texture_);								// �������� ������ ���������
	sprite_.setTextureRect(sf::IntRect(0, 0, width_, height_));	// ������ ������� ���� ������������� ������� ������� ���������.
	//sprite_.scale(0.7f, 0.7f);
}

PlayerBase::PlayerBase(sf::Image image, sf::String name, float x, float y, int width, int height, GameMap& map) :
	x_(x),
	y_(y),
	dx_(0),
	dy_(0),
	speed_(0),
	moveDirection_(0),
	width_(width),
	height_(height),
	name_(name),
	image_(image),
	gameMap_(map)
{
	texture_.loadFromImage(image_);								// ����������� �������� � ������������
	sprite_.setTexture(texture_);								// �������� ������ ���������
	sprite_.setTextureRect(sf::IntRect(0, 0, width_, height_));	// ������ ������� ���� ������������� ������� ������� ���������.
}