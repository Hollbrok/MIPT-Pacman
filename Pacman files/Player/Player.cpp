#include "Player.h"
#include "MIPT_pacman.h"
#include "Consts.h"

#include "PlayerBase.h"



Player::Player(sf::String file, sf::String name, float x, float y, int width, int height, GameMap * map) :
	PlayerBase(file, name, x, y, width, height, map),
	stay_(MoveDir::stay),
	goldCounter_(0)
{

}

Player::Player(sf::Image image, sf::String name, float x, float y, int width, int height, GameMap * map) :
	PlayerBase(image, name, x, y, width, height, map),
	stay_(MoveDir::stay),
	goldCounter_(0)
{

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
		for (int i = int(y_ / 21) + 1; i < (y_ + height_) / 21; i++)
		{
			//std::cout << "\ni " << i << std::endl;
			if (gameMap_->stringMap_[i][j] == borderTile)
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
			else if (gameMap_->stringMap_[i][j] == bonfireTile)
			{
				std::cout << "bonfireTile" << std::endl;
				x_ = 320;
				y_ = 340;
				gameMap_->stringMap_[i][j] = defaultMapTile;
			}
			else if (gameMap_->stringMap_[i][j] == goldTile)
			{
				gameMap_->stringMap_[i][j] = defaultMapTile;

				goldCounter_++;
				lastGoldCounter++;

				std::cout << "lastGeneratedNumberOfCoints: " << gameMap_->lastGeneratedNumberOfCoints << std::endl;
				std::cout << "gold: " << goldCounter_ << std::endl;
				std::cout << "lastGoldCounter: " << lastGoldCounter << std::endl;

				if (lastGoldCounter == gameMap_->lastGeneratedNumberOfCoints)
				{
					gameMap_->generateMap();
					lastGoldCounter = 0;
				}
			}
			else if (gameMap_->stringMap_[i][j] == portalTile)
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

void Player::cameraMovement(sf::RenderWindow & window, float time, bool needMouseCoords)
{
	sf::Vector2i localPosition = sf::Mouse::getPosition(window);					// camera movement

	int cameraMoveDir = getCameraMoveDirection(localPosition.x, localPosition.y, window.getSize().x, window.getSize().y);

	if (cameraMoveDir == BAD_DIRECTION)
		;// we dont need to move camera
	else if (cameraMoveDir == UP)
		getView().move(0, -0.2 * time);
	else if (cameraMoveDir == LEFT)
		getView().move(-0.2 * time, 0);
	else if (cameraMoveDir == DOWN)
		getView().move(0, 0.2 * time);
	else if (cameraMoveDir == RIGHT)
		getView().move(0.2 * time, 0);
	else
		std::cout << "LOGIC_ERROR in line : " << __LINE__ << std::endl;

	if(needMouseCoords)
		std::cout << "LocPos : " << localPosition.x << ' ' << localPosition.y << std::endl;
}
