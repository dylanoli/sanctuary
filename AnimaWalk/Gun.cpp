#include "Gun.h";
#include "Image.h";
#include "Bullet.h";

Gun::Gun(
	Scene* scene,
	string fileNameSpriteRight,
	string fileNameSpriteLeft,
	uint compensationDirection,
	string fileBulletNameSpriteRight,
	string fileBulletNameSpriteLeft,
	float bulletVelocity,
	float fireRate,
	GunMode gunMode
)
{
	Gun::spriteRight = new Sprite(fileNameSpriteRight);
	Gun::spriteLeft = new Sprite(fileNameSpriteLeft);
	Gun::compensationDirection = compensationDirection;
	Gun::scene = scene;
	Gun::bulletImageLeft = new Image(fileBulletNameSpriteLeft);
	Gun::bulletImageRight = new Image(fileBulletNameSpriteRight);
	Gun::bulletVelocity = bulletVelocity;
	Gun::fireRate = fireRate;
	Gun::gunMode = gunMode;
}

Gun::~Gun()
{
	delete spriteRight;
	delete spriteLeft;
}

void Gun::Shot() 
{
	if (canShot) {
		scene->Add(new Bullet(x, y, lookDirection, bulletVelocity, bulletImageRight, bulletImageLeft, scene), MOVING);
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
	if(lookDirection == RIGHT)
		spriteRight->Draw(x, y, Layer::UPPER);
	else
		spriteLeft->Draw(x, y, Layer::UPPER);
}