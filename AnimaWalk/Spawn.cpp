#include "Spawn.h"
#include "Lince.h"
#include "Snake.h"
#include "Bear.h"

using namespace std;

Spawn::Spawn(float i, int number, uint type, SideSpawn side, Scene* s, Player* p) {
	interval = i;
	numberToSpawn = number;
	spawnType = type;
	player = p;
	scene = s;
	sideSpawn = side;
	timer.Start();
}

void Spawn::Update()
{
	if (timer.Elapsed(interval)) {
		if (currentEnemiesCount < numberToSpawn) {
			CreateMobi();
			currentEnemiesCount++;
			timer.Start();
		}
	}
}

void Spawn::CreateMobi()
{
	auto coords = GenerateRandomCoords();
	switch (spawnType)
	{
		case WOLF: {
			auto enemy = new Lince(player, scene, this, coords.first, coords.second);
			scene->Add(enemy, MOVING);
			break;
		}
		case BEAR: {
			auto enemy = new Bear(player, scene, this, coords.first, coords.second);
			scene->Add(enemy, MOVING);
			break;
		}
		case SNAKE: {
			auto enemy = new Snake(player, scene, this, coords.first, coords.second);
			scene->Add(enemy, MOVING);
			break;
		}
	}
}

pair<float, float> Spawn::GenerateRandomCoords()
{
	const int MAX_VARY = 430;

	int varyX = 0;
	
	random_device rd;
	mt19937 mt(rd());

	switch (sideSpawn)
	{
		case LEFT_ONLY:
			varyX = -MAX_VARY;
			break;
		case RIGHT_ONLY:
			varyX = MAX_VARY;
			break;
		default:
			uniform_int_distribution<int> fifth(0, 1);
			varyX = fifth(mt) == true ? MAX_VARY : -MAX_VARY;
			break;
	}

	uniform_real_distribution<float> dist(window->CenterY(), window->Height());

	const float posX = window->CenterX() + varyX;
	const float posY = dist(mt);

	return pair<float, float>(posX, posY);
}

bool Spawn::AllEnemiesIsDied()
{
	return numberToSpawn == enemiesDied;
}

void Spawn::IncrementEnemieDied() {
	enemiesDied++;
}