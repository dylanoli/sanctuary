#pragma once

#include "Timer.h"
#include "Types.h"
#include "Player.h"

enum SpawnType { WOLF, SNAKE, BEAR };

class Spawn {
	private:
		Timer timer;
		float interval;
		int numberToSpawn = 0;
		int enemiesDied = 0;
		int currentEnemiesCount = 0;
		uint spawnType;
		Player* player;
		Scene* scene;

	public:
		Spawn(float, int, uint, Scene*, Player*);
		void Generate();
		bool AllEnemiesIsDied();
		void IncrementEnemieDied();
};

