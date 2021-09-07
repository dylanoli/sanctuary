#include "Bullet.h"

Bullet::Bullet(int posX, int posY, Direction direction, float velocity, Image * image)
{
	MoveTo(posX, posY);
	_direction = direction;
	_velocity = velocity;
	//_sprite = new Sprite(image);
	_sprite = new Sprite("Resources/Bullet.png");
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	if(_direction == RIGHT)
		MoveTo(x + (_velocity * gameTime), y);
	else
		MoveTo(x - (_velocity * gameTime), y);
}

void Bullet::Draw()
{
	_sprite->Draw(x,y);
}