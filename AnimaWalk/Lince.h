#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Scene.h"

class Lince : public Enemy
{
public:
	Lince(Player* player, Scene* scene);
	~Lince();
};