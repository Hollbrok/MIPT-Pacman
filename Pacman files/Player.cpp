#include "Player.h"
#include "MIPT_pacman.h"

#include "GameMap.h"


const int UP = 0;
const int LEFT = 1;
const int DOWN = 2;
const int RIGHT = 3;

const char defaultMapTile = ' ';
const char waterTile = 'w';
const char bonfireTile = 'f';
const char borderTile = '0';
const char goldTile = 'g';
const char portalTile = 'p';

const int HEIGHT_MAP = 34;
const int WIDTH_MAP = 48;

const int portal1_x = 10;
const int portal1_y = 12;

const int portal2_x = 25;
const int portal2_y = 30;

sf::String TileMap[HEIGHT_MAP] = {
	"000000000000000000000000000000000000000000000000",
	"0                                              0",
	"0   wwwwwwwwwww                                0",
	"0   wwwwwwwwwww                      g         0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                   f                          0",
	"0                                              0",
	"0         g                                    0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0        g                                     0",
	"0                                              0",
	"0                                     g        0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"0                         g                    0",
	"0                                              0",
	"0                                              0",
	"0                                              0",
	"000000000000000000000000000000000000000000000000",
};

Player::Player(sf::String file, float x, float y, int width, int height) :
	x_(x),
	y_(y),
	dx_(0),
	dy_(0),
	speed_(0),
	moveDirection_(0),
	width_(width),
	height_(height),
	file_(file),
	goldCounter_(0)
{
	image_.loadFromFile("images/" + file_);						// ассоциируем image_ с нашим изображением вместе с адресом папки расположения
	//image_.createMaskFromColor(sf::Color(255, 255, 255));		// Если нужно убрать лишний цвет с изображения
	texture_.loadFromImage(image_);								// ассоциируем текстуру с изображением
	sprite_.setTexture(texture_);								// заливаем спрайт текстурой
	sprite_.setTextureRect(sf::IntRect(0, 150, width_, height_));	// задаем спрайту один прямоугольник нужного размера персонажа.
	//sprite_.scale(0.7f, 0.7f);
}

void Player::move(float & currentFrame, float time)
{
	int dir = defineDirection();
	switch (dir)
	{
	case UP:
		setMoveDir(0);
		setSpeed(0.1f);
		currentFrame += 0.01f * time;
		if (currentFrame > 3) currentFrame -= 3;
		getSprite().setTextureRect(sf::IntRect(76 + int(currentFrame) * (28 + 4), 104, 28, 32)); //через объект mainHero класса player меняем спрайт, делая анимацию
		break;
	case LEFT:
		setMoveDir(1);
		setSpeed(0.1f);
		currentFrame += 0.01f * time;
		if (currentFrame > 3) currentFrame -= 3;
		getSprite().setTextureRect(sf::IntRect(79 + int(currentFrame) * (25 + 7), 40, 25, 32)); //через объект mainHero класса player меняем спрайт, делая анимацию
		break;
	case DOWN:
		setMoveDir(2);
		setSpeed(0.1f);
		currentFrame += 0.01f * time;
		if (currentFrame > 3) currentFrame -= 3;
		getSprite().setTextureRect(sf::IntRect(77 + int(currentFrame) * (28 + 4), 8, 28, 32)); //через объект mainHero класса player меняем спрайт, делая анимацию
		break;
	case RIGHT:
		setMoveDir(3);
		setSpeed(0.1f);
		currentFrame += 0.01f * time;
		if (currentFrame > 3) currentFrame -= 3;
		getSprite().setTextureRect(sf::IntRect(76 + int(currentFrame) * (25 + 7), 72, 25, 32)); //через объект mainHero класса player меняем спрайт, делая анимацию
		break;
	default:
		std::cerr << "ERROR IN LINE:" << __LINE__ << std::endl
				  << "direction = "   <<    dir   << std::endl;
	}
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
	gameLogic();
}

void Player::gameLogic()
{
	float newX = x_;
	float newY = y_;
	bool wasPortal = false;

	for (int j = int(x_ / 20); j < (x_ + width_) / 20; j++)
	{
		//std::cout << "j " << j;
		for (int i = int(y_ / 21); i < (y_ + height_) / 21; i++)
		{
			//std::cout << "\ni " << i << std::endl;
			if (TileMap[i][j] == borderTile)
			{
				std::cout << "borderTile" << std::endl;
				if (dy_ > 0)
					y_ = i * 21 - height_;
				if (dy_ < 0)
					y_ = i * 21 + 21;
				if (dx_ > 0)
					x_ = j * 20 - width_;
				if (dx_ < 0)
					x_ = j * 20 + 20;

			}
			else if (TileMap[i][j] == bonfireTile)
			{
				std::cout << "bonfireTile" << std::endl;
				x_ = 320;
				y_ = 340;
				TileMap[i][j] = defaultMapTile;
			}
			else if (TileMap[i][j] == goldTile)
			{
				TileMap[i][j] = defaultMapTile;
				goldCounter_++;
				std::cout << "gold: " << goldCounter_ << std::endl;
			}
			else if (TileMap[i][j] == portalTile)
			{
				int newExit_x = 0;
				int newExit_y = 0;

				if (dx_ > 0)	  // move RIGHT
					newExit_x = 1;
				else if (dx_ < 0) // move LEFT
					newExit_x = -1;
				else			  // none MOVE
					newExit_x = 0;

				if (dy_ > 0)      // move DOWN
					newExit_y = 1;
				else if (dy_ < 0) // move UP
					newExit_y = -1;
				else			  // none MOVE
					newExit_y = 0;

				if (i == portal1_y)
				{
					//std::cout << "portal 1\n";
					newX = (portal2_x + newExit_x * 1.8f) * 20;
					newY = (portal2_y + newExit_y * 1.8f) * 21;
				}
				else
				{
					//std::cout << "portal 2\n";
					newX = (portal1_x + newExit_x * 1.8f) * 20;
					newY = (portal1_y + newExit_y * 1.8f) * 21;
				}

				wasPortal = true;
			}
		}
	}

	if (wasPortal)
	{
		x_ = newX;
		y_ = newY;
	}

}



GameMap::GameMap()
{
	image_.loadFromFile("images/map/tiles_set.png");
	texture_.loadFromImage(image_);
	sprite_.setTexture(texture_);

	TileMap[portal1_y][portal1_x] = portalTile;
	TileMap[portal2_y][portal2_x] = portalTile;
}

void GameMap::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == defaultMapTile)
				sprite_.setTextureRect(sf::IntRect(132, 40, 20, 21));
			else if (TileMap[i][j] == waterTile)
				sprite_.setTextureRect(sf::IntRect(192, 239, 20, 21));
			else if (TileMap[i][j] == bonfireTile)
				sprite_.setTextureRect(sf::IntRect(192, 1095, 20, 21));
			else if (TileMap[i][j] == borderTile)
				sprite_.setTextureRect(sf::IntRect(172, 239, 20, 21));
			else if (TileMap[i][j] == goldTile)
				sprite_.setTextureRect(sf::IntRect(450, 1214, 20, 21));
			else if (TileMap[i][j] == portalTile)
				sprite_.setTextureRect(sf::IntRect(191, 617, 21, 21));

			sprite_.setPosition(j * 20, i * 21);

			window.draw(sprite_);
		}
}