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
	image_.loadFromFile("images/" + file_);						// ассоциируем image_ с нашим изображением вместе с адресом папки расположени€
	//image_.createMaskFromColor(sf::Color(255, 255, 255));		// ≈сли нужно убрать лишний цвет с изображени€
	texture_.loadFromImage(image_);								// ассоциируем текстуру с изображением
	
	sprite_.setTexture(texture_);								// заливаем спрайт текстурой
	sprite_.setTextureRect(sf::IntRect(0, 0, width_, height_));	// задаем спрайту один пр€моугольник нужного размера персонажа.
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
	texture_.loadFromImage(image_);								// ассоциируем текстуру с изображением
	sprite_.setTexture(texture_);								// заливаем спрайт текстурой
	sprite_.setTextureRect(sf::IntRect(0, 0, width_, height_));	// задаем спрайту один пр€моугольник нужного размера персонажа.
}