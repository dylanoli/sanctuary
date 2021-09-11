#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Scene.h"

class Snake : public Enemy
{
private:
	Sprite* heartSprite[10];
public:
	Snake(Player* player, Scene* scene, Spawn* spawn, float startPosX, float startPosY);
	~Snake();
};
