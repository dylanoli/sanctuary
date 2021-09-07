#pragma once
#include "Object.h"
#include "Sprite.h"
#include "Constants.h"
#include "Bullet.h"

class Gun : public Object
{
private:
	bool _canShot = true;
	Sprite* _spriteRight;
	Sprite* _spriteLeft;
	uint _compensationDirection;
	list<Bullet*> bullets;
protected:
	Direction lookDirection;

public:
	Gun(string fileNameSpriteRight, string fileNameSpriteLeft, uint compensationDirection);
	~Gun();

	void::Object::Update();
	void Object:: Draw();
	void Shot();

	inline void SetDirection(Direction direction)
	{
		lookDirection = direction;
	}

	inline void MoveTo(float px, float py) 
	{
		if(lookDirection == RIGHT)
			Object::MoveTo(px + _compensationDirection, py);
		else
			Object::MoveTo(px - _compensationDirection, py);

	}
};
