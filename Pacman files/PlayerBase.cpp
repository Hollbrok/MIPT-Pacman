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
	image_.loadFromFile("images/" + file_);						// ассоциируем image_ с нашим изображением вместе с адресом папки расположения
	//image_.createMaskFromColor(sf::Color(255, 255, 255));		// Если нужно убрать лишний цвет с изображения
	texture_.loadFromImage(image_);								// ассоциируем текстуру с изображением
	sprite_.setTexture(texture_);								// заливаем спрайт текстурой
	sprite_.setTextureRect(sf::IntRect(0, 150, width_, height_));	// задаем спрайту один прямоугольник нужного размера персонажа.
	//sprite_.scale(0.7f, 0.7f);
}