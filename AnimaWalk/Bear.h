#pragma once

#include "Enemy.h"
#include "Player.h"
#include "Scene.h"

class Bear : public Enemy
{
private:
	Sprite* heartSprite[10];
public:
	Bear(Player* player, Scene* scene, Spawn* spawn, float startPosX, float startPosY);
	~Bear();
	void Draw();
};

inline void Bear::Draw()
{
	anim->Draw(x, y - 20, z);

	const float countHeartFloat = 10 * ((life * 1.0f) / maxLife);
	const int countHeartInt = (int)countHeartFloat;
	const int countHeart = countHeartFloat > countHeartInt? countHeartInt + 1: countHeartInt;

	for (size_t i = 0; i < countHeart; i++)
	{
		float posX = window->Width() - 15.0f - (28.0f * i);
		heartSprite[i]->Draw(posX, 15, Layer::UPPER);
	}
}