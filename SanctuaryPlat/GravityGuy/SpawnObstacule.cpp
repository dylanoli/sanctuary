#include "SpawnObstacule.h"
#include "Obstacle.h"
#include "GravityGuy.h"
#include <random>

SpawnObstacule::SpawnObstacule(Scene* _scene)
{
	scene = _scene;
	timeSpawn.Start();
	timeToNextSpawn = 2;
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

		uniform_real_distribution<float> dist(1, 3);
		timeToNextSpawn = dist(mt);

		//reset countdown
		timeSpawn.Start();
	}
}