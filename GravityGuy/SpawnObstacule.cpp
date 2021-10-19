#include "SpawnObstacule.h"
#include "Obstacle.h"
#include "Sanctuary.h"
#include <random>

SpawnObstacule::SpawnObstacule(Scene* _scene, float minInt, float maxInt)
{
	scene = _scene;
	timeSpawn.Start();
	minInterval = minInt;
	maxInterval = maxInt;
	timeToNextSpawn = maxInt;
}

SpawnObstacule::~SpawnObstacule()
{
}

void SpawnObstacule::Update()
{
	if (timeSpawn.Elapsed(timeToNextSpawn))
	{
		//spawn
		Obstacle* obstacle = new Obstacle(window->CenterX() + 700, window->CenterY() + 95, scene);
		scene->Add(obstacle, STATIC);

		//set time to next spawn
		random_device rd;
		mt19937 mt(rd());

		uniform_real_distribution<float> dist(minInterval, maxInterval);
		timeToNextSpawn = dist(mt);

		//reset countdown
		timeSpawn.Start();
	}
}