#ifndef _SANCTUARY_SPAWN_H_
#define _SANCTUARY_SPAWN_H_

#include "Timer.h"
#include "Types.h"
#include "Player.h"
#include "Object.h"
#include <random>

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
		void CreateMobi();
		pair<float, float> GenerateRandomCoords();

	public:
		Spawn(float, int, uint, SideSpawn, Scene*, Player*);
		void Update();
		void Draw();
		bool AllEnemiesIsDied();
		void IncrementEnemieDied();
};

inline void Spawn::Draw() {

}

#endif

