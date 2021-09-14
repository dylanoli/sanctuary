#ifndef _SANCTUARY_LINCE_H_
#define _SANCTUARY_LINCE_H_

#include "Enemy.h"
#include "Player.h"
#include "Scene.h"

class Lince : public Enemy
{
public:
	Lince(Player* player, Scene* scene, Spawn* spawn, float startPosX, float startPosY);
	~Lince();
};

#endif