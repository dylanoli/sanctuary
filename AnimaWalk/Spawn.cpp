#include "Spawn.h"
#include "Lince.h"
#include "Snake.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Bear.h"

Spawn::Spawn(float i, int number, uint type, SideSpawn side, Scene* s, Player* p) {
	interval = i;
	numberToSpawn = number;
	spawnType = type;
	player = p;
	scene = s;
	sideSpawn = side;
	timer.Start();
	srand((unsigned)time(NULL));
}

void Spawn::Update()
{
	Generate();
}

void Spawn::Generate() {
	
	if (timer.Elapsed(interval)) {
		if (currentEnemiesCount < numberToSpawn) {
			const int MAX_VARY = 430;
			int varyX = 0;
			if (sideSpawn == RIGHT_ONLY)
				varyX = -MAX_VARY;
			else if (sideSpawn == LEFT_ONLY)
				varyX = MAX_VARY;
			else
			{
				auto choice = (rand() % 10);
				varyX = choice > 5? MAX_VARY: -MAX_VARY;
			}
			const float posX = window->CenterX() + varyX;
			const float posY = window->CenterY() + ((rand() % 540) - 270);
			switch (spawnType)
			{
			case WOLF: {
				auto enemy = new Lince(player, scene, this, posX, posY);
				scene->Add(enemy, MOVING);
				break;
			}
			case BEAR: {
				auto enemy = new Bear(player, scene, this, posX, posY);
				scene->Add(enemy, MOVING);
				break;
			}
			case SNAKE: {
				auto enemy = new Snake(player, scene, this, posX, posY);
				scene->Add(enemy, MOVING);
				break;
			}
			default:
				break;
			}

			currentEnemiesCount++;
			timer.Start();
		}
	}
}

bool Spawn::AllEnemiesIsDied()
{
	return numberToSpawn == enemiesDied;
}

void Spawn::IncrementEnemieDied() {
	enemiesDied++;
}