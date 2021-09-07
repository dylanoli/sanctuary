#pragma once
#include "Object.h";
#include "Constants.h";
#include "Sprite.h";
#include "Image.h";
class Bullet :public Object 
{
private:
	Direction _direction;
	float _velocity;
	Sprite* _sprite;
public:
	Bullet(int posX, int posY, Direction direction, float velocity, Image* image);
	~Bullet();
	void Object::Update();
	void Object::Draw();
};