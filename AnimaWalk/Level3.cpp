#include "Level3.h"
#include "Engine.h"
#include "Home.h"
#include "GameOver.h"
#include "Victory.h"

// ------------------------------------------------------------------------------

void Level3::Init()
{
	backg = new Sprite("Resources/Home/Background.png");
	scene = new Scene();

	player = new Player(scene);
	player->MoveTo(window->CenterX(), window->CenterY());
	spawn = new Spawn(2.0f, 1, BEAR, LEFT_ONLY, scene, player);

	scene->Add(player, MOVING);
	scene->Add(spawn, STATIC);

}

// ------------------------------------------------------------------------------

void Level3::Update()
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
		Engine::Next<Victory>();

	if (!arrowExists && player->IsDied())
		Engine::Next<GameOver>();

	if (window->KeyDown(VK_ESCAPE))
		Engine::Next<Home>();
}

// ------------------------------------------------------------------------------

void Level3::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();
	scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level3::Finalize()
{
	delete backg;
}
