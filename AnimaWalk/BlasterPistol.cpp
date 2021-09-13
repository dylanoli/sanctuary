#include "BlasterPistol.h"
#include "Bullet.h"

string FileNameSpriteRight = "Resources/BlasterPistolRight.png";
string FileNameSpriteLeft = "Resources/BlasterPistolLeft.png";
string FileBulletNameSpriteRight = "Resources/BulletRight.png";
string FileBulletNameSpriteLeft = "Resources/BulletLeft.png";
uint CompensationDirection = 20;
float BulletVelocity = 800;
int BulleDamage = 5;
float FireRate = 0.3f;


BlasterPistol::BlasterPistol(Scene* scene) : Gun(
	scene,
	CompensationDirection,
	FileBulletNameSpriteRight,
	FileBulletNameSpriteLeft,
	BulletVelocity,
	BulleDamage,
	FireRate,
	SINGLE
) {}

BlasterPistol::~BlasterPistol() {

}

