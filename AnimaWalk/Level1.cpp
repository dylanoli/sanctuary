#include "Level1.h"
#include "Level2.h"
#include "Engine.h"
#include "Home.h"
#include "GameOver.h"

// ------------------------------------------------------------------------------

void Level1::Init()
{
	backg = new Sprite("Resources/Home/Background.png");
	scene = new Scene();

	player = new Player(scene);	
	spawn = new Spawn(2, 3, WOLF, LEFT_ONLY, scene, player);

	scene->Add(player, MOVING);
	scene->Add(spawn, STATIC);
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
	scene->Update();
	scene->CollisionDetection();
	
	if (spawn->AllEnemiesIsDied() && !arrowExists) {
		arrowExists = true;

		arrowNextLevel = new ArrowNextLevel();
		arrowNextLevel->MoveTo(window->CenterX() + 420, window->CenterY());
		scene->Add(arrowNextLevel, MOVING);
	}

	if (arrowExists && arrowNextLevel->CanChangeLevel())
		Engine::Next<Level2>();
	
	if (!arrowExists && player->IsDied())
		Engine::Next<GameOver>();

	if (window->KeyDown(VK_ESCAPE))
		Engine::Next<Home>();
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();
	scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
	delete backg;
}