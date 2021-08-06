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
	image_.loadFromFile("images/" + file_);						// ассоциируем image_ с нашим изображением вместе с адресом папки расположения
	//image_.createMaskFromColor(sf::Color(255, 255, 255));		// Если нужно убрать лишний цвет с изображения
	texture_.loadFromImage(image_);								// ассоциируем текстуру с изображением
	sprite_.setTexture(texture_);								// заливаем спрайт текстурой
	sprite_.setTextureRect(sf::IntRect(0, 150, width_, height_));	// задаем спрайту один прямоугольник нужного размера персонажа.
}

void Player::update(float time) // time -- время SFML
{
	switch (moveDirection_)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
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

	speed_ = 0;						// Дефолтный вид движения. Если не занулять, то будет как в змейке
	sprite_.setPosition(x_, y_);	// Обновляем позицию спрайта
}