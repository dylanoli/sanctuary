#include "Spawn.h"
#include "Lince.h"
#include "Bear.h"

Spawn::Spawn(float i, int number, uint type, Scene* s, Player* p) {
	interval = i;
	numberToSpawn = number;
	spawnType = type;
	player = p;
	scene = s;
	timer.Start();
}

void Spawn::Generate() {
	
	if (timer.Elapsed(interval)) {
		if (currentEnemiesCount < numberToSpawn) {

			switch (spawnType)
			{
			case WOLF: {
				auto enemy = new Lince(player, scene, this);
				scene->Add(enemy, MOVING);
				break;
			}
			case BEAR: {
				auto enemy = new Bear(player, scene, this);
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