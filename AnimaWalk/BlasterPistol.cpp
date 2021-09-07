#include "BlasterPistol.h"
#include "Bullet.h"

string FileNameSpriteRight = "Resources/BlasterPistolRight.png";
string FileNameSpriteLeft = "Resources/BlasterPistolLeft.png";
string FileBulletNameSpriteRight = "Resources/BulletRight.png";
string FileBulletNameSpriteLeft = "Resources/BulletLeft.png";
uint CompensationDirection = 20;
float BulletVelocity = 500;
float FireRate = 0.3f;


BlasterPistol::BlasterPistol(Scene* scene):Gun(
	scene,
	FileNameSpriteRight,
	FileNameSpriteLeft,
	CompensationDirection,
	FileBulletNameSpriteRight,
	FileBulletNameSpriteLeft,
	BulletVelocity,
	FireRate,
	SINGLE
) {
}

BlasterPistol::~BlasterPistol() {

}

