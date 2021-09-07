#pragma once
#include "Object.h"
#include "Sprite.h"
#include "Constants.h"
#include "Scene.h"
enum GunMode { SINGLE, AUTOMATIC };
class Gun : public Object
{
private:
	bool canShot = true;
	Sprite* spriteRight;
	Sprite* spriteLeft;
	uint compensationDirection;
	Scene* scene;
	Image* bulletImageLeft;
	Image * bulletImageRight;
	float bulletVelocity;
	float fireRate;
	float currentFireRateTime = 0;
	GunMode gunMode;

protected:
	Direction lookDirection;

public:
	Gun(
		Scene* scene,
		string fileNameSpriteRight,
		string fileNameSpriteLeft,
		uint compensationDirection,
		string fileBulletNameSpriteRight,
		string fileBulletNameSpriteLeft,
		float bulletVelocity,
		float fireRate,
		GunMode gunMode
	);
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
			Object::MoveTo(px + compensationDirection, py);
		else
			Object::MoveTo(px - compensationDirection, py);
	}
};
