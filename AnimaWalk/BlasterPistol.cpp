#include "BlasterPistol.h"
#include "Bullet.h"

string fileNameSpriteRight = "Resources/BlasterPistolRight.png";
string fileNameSpriteLeft = "Resources/BlasterPistolLeft.png";
uint compensationDirection = 20;


BlasterPistol::BlasterPistol():Gun(fileNameSpriteRight, fileNameSpriteLeft, compensationDirection) {
}

BlasterPistol::~BlasterPistol() {

}

