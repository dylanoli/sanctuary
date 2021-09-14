#include "Level3.h"
#include "Level2.h"
#include "Engine.h"
#include "Home.h"
#include "GameOver.h"

// ------------------------------------------------------------------------------

void Level2::Init()
{
	backg = new Sprite("Resources/Background.png");
	scene = new Scene();

	player = new Player(scene);
	spawn = new Spawn(1, 10, WOLF, BOTH_SIDES, scene, player);
	spawn2 = new Spawn(3, 6, SNAKE, BOTH_SIDES, scene, player);
	
	scene->Add(player, MOVING);
	scene->Add(spawn, STATIC);
	scene->Add(spawn2, STATIC);
	
}

// ------------------------------------------------------------------------------

void Level2::Update()
{
	scene->Update();
	scene->CollisionDetection();

	if (spawn->AllEnemiesIsDied() && spawn2->AllEnemiesIsDied() && !arrowExists) {
		arrowExists = true;

		arrowNextLevel = new ArrowNextLevel();
		arrowNextLevel->MoveTo(window->CenterX() + 420, window->CenterY() + 100);
		scene->Add(arrowNextLevel, MOVING);
	}

	if (arrowExists && arrowNextLevel->CanChangeLevel())
		Engine::Next<Level3>();

	if (!arrowExists && player->IsDied())
		Engine::Next<GameOver>(LEVEL2);

	if (window->KeyDown(VK_ESCAPE))
		Engine::Next<Home>();
}

// ------------------------------------------------------------------------------

void Level2::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();
}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
	delete backg;
	delete scene;
}
