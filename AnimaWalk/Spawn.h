#pragma once

#include "Timer.h"
#include "Types.h"
#include "Player.h"
#include "Object.h"

enum SpawnType { WOLF, SNAKE, BEAR };
enum SideSpawn { LEFT_ONLY, RIGHT_ONLY, BOTH_SIDES };

class Spawn: public Object {
	private:
		Timer timer;
		float interval;
		int numberToSpawn = 0;
		int enemiesDied = 0;
		int currentEnemiesCount = 0;
		uint spawnType;
		SideSpawn sideSpawn;
		Player* player;
		Scene* scene;

	public:
		Spawn(float, int, uint, SideSpawn, Scene*, Player*);
		void Update();
		void Draw();
		void Generate();
		bool AllEnemiesIsDied();
		void IncrementEnemieDied();
};

inline void Spawn::Draw() {

}

