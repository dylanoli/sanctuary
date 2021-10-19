#ifndef _SANCTUARY_SPAWN_H_
#define _SANCTUARY_SPAWN_H_

// ---------------------------------------------------------------------------------

#include "Timer.h"
#include "Object.h"      
#include "Scene.h"               

// ---------------------------------------------------------------------------------

class SpawnObstacule: public Object
{
public:
	SpawnObstacule(Scene* _scene, float minInterval, float maxInterval);
	~SpawnObstacule();

private:
	Timer timeSpawn;
	Scene* scene = nullptr;
	float minInterval = 1;
	float maxInterval = 3;
	float timeToNextSpawn = 0;

	void OnCollision(Object* obj);
	void Update();                      
	void Draw();                        
};

// ---------------------------------------------------------------------------------

inline void SpawnObstacule::Draw()
{
}

// ---------------------------------------------------------------------------------

inline void SpawnObstacule::OnCollision(Object* obj)
{
}

// ---------------------------------------------------------------------------------

#endif