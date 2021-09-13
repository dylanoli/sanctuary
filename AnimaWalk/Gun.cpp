#include "Gun.h";
#include "Image.h";
#include "Bullet.h";

Gun::Gun(
	Scene* scene,
	uint compensationDirection,
	string fileBulletNameSpriteRight,
	string fileBulletNameSpriteLeft,
	float bulletVelocity,
	int bulletDamage,
	float fireRate,
	GunMode gunMode
)
{
	Gun::compensationDirection = compensationDirection;
	Gun::scene = scene;
	Gun::bulletImageLeft = new Image(fileBulletNameSpriteLeft);
	Gun::bulletImageRight = new Image(fileBulletNameSpriteRight);
	Gun::bulletVelocity = bulletVelocity;
	Gun::bulletDamage = bulletDamage;
	Gun::fireRate = fireRate;
	Gun::gunMode = gunMode;
}

Gun::~Gun()
{

}

void Gun::Shot() 
{
	if (canShot) {
		if (lookDirection == RIGHT)
			scene->Add(new Bullet(x + 40, y - 10, lookDirection, bulletVelocity, bulletDamage, bulletImageRight, bulletImageLeft, scene), MOVING);			
		else
			scene->Add(new Bullet(x - 40, y - 10, lookDirection, bulletVelocity, bulletDamage, bulletImageRight, bulletImageLeft, scene), MOVING);
		
		canShot = false;
	}
}

void Gun::Update() {
	//controle de quando e possivel ativar novamente
	if (!canShot)
	{
		currentFireRateTime += gameTime;
	}
	if ((window->KeyUp(VK_SPACE) || gunMode == AUTOMATIC) && !canShot && currentFireRateTime >= fireRate)
	{
		canShot = true;
		currentFireRateTime = 0;
	}

	//atirando
	if (window->KeyDown(VK_SPACE))
	{
		Shot();
	}
}

void Gun::Draw() {
	//remove sprite arma
}