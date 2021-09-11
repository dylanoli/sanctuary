#include "Timer.h"
#include "Lince.h"
#include "Bear.h"
#include <sstream>

using namespace std;

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
		Spawn(float, int, SpawnType, Scene*, Player*);
		void Generate();
		bool AllEnemiesIsDied();
		void IncrementEnemieDied();
};

inline Spawn::Spawn(float i, int number, SpawnType type, Scene* s, Player* p) {
	interval = i;
	numberToSpawn = number;
	spawnType = type;
	player = p;
	scene = s;
	timer.Start();
}

inline void Spawn::Generate() {
	stringstream ss;
	if (timer.Elapsed(interval)) {
		if (currentEnemiesCount < numberToSpawn) {
			
			switch (spawnType)
			{
			case WOLF: {
				auto enemy = new Lince(player, scene);
				scene->Add(enemy, MOVING);
				break;
			}
			case BEAR: {
				
				break;
			}
			default:
				break;
			}

			ss << "---------------- Oi\n";
			OutputDebugString(ss.str().c_str());
			currentEnemiesCount++;
			timer.Start();
		}
	}
}

inline bool Spawn::AllEnemiesIsDied()
{
	return numberToSpawn == enemiesDied;
}

inline void Spawn::IncrementEnemieDied() {
	enemiesDied++;
}