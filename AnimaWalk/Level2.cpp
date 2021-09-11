#include "Level3.h"
#include "Level2.h"
#include "Engine.h"
#include "Home.h"
#include "GameOver.h"

// ------------------------------------------------------------------------------

void Level2::Init()
{
	backg = new Sprite("Resources/Home/Background.png");
	scene = new Scene();
	
	player = new Player(scene);
	player->MoveTo(window->CenterX(), window->CenterY());
	scene->Add(player, MOVING);
	
	arrowNextLevel = new ArrowNextLevel();
	arrowNextLevel->MoveTo(window->CenterX() + 420, window->CenterY());
	scene->Add(arrowNextLevel, STATIC);

}

// ------------------------------------------------------------------------------

void Level2::Update()
{
	scene->Update();
	scene->CollisionDetection();

	if (player->IsDied())
		Engine::Next<GameOver>();

	if (window->KeyDown(VK_ESCAPE))
		Engine::Next<Home>();

	//if (arrowNextLevel->CanChangeLevel())
		//Engine::Next<Level3>();
}

// ------------------------------------------------------------------------------

void Level2::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();
	scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
	delete backg;
}
