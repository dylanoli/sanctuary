#include "Gun.h";
#include "Image.h";
#include "Bullet.h";

Image* image = new Image("Resources/Bullet.png");
Gun::Gun(string fileNameSpriteRight, string fileNameSpriteLeft, uint compensationDirection)
{
	_spriteRight = new Sprite(fileNameSpriteRight);
	_spriteLeft = new Sprite(fileNameSpriteLeft);
	_compensationDirection = compensationDirection;
}

Gun::~Gun()
{
	delete _spriteRight;
	delete _spriteLeft;
}

void Gun::Shot() 
{
	if (_canShot) {

	}
}

void Gun::Update() {
	if (window->KeyDown(VK_SPACE) && _canShot)
	{
		bullets.push_back(new Bullet(x, y, lookDirection, 500, image));
		_canShot = false;
	}
	if (window->KeyUp(VK_SPACE) && !_canShot)
	{
		_canShot = true;
	}

	for (auto i : bullets)
	{
		i->Update();
	}
}

void Gun::Draw() {
	if(lookDirection == RIGHT)
		_spriteRight->Draw(x, y, Layer::UPPER);
	else
		_spriteLeft->Draw(x, y, Layer::UPPER);

	for (auto i : bullets)
	{
		i->Draw();
	}
}