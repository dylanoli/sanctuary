#include "Level1.h"
#include "Level2.h"
#include "Engine.h"
#include "Home.h"
#include "Lince.h"
#include "Bear.h"
#include "GameOver.h"

// ------------------------------------------------------------------------------

void Level1::Init()
{
	backg = new Sprite("Resources/Home/Background.png");
	scene = new Scene();
	player = new Player(scene);
	arrowNextLevel = new ArrowNextLevel();
	arrowNextLevel->MoveTo(window->CenterX()+420, window->CenterY());
	auto enemy = new Lince(player, scene);
	player->MoveTo(window->CenterX(), window->CenterY());
	scene->Add(player, MOVING);
	scene->Add(enemy, MOVING);
	scene->Add(arrowNextLevel, MOVING);

}

// ------------------------------------------------------------------------------

void Level1::Update()
{
	scene->Update();
	scene->CollisionDetection();

	if (player->IsDied())
		Engine::Next<GameOver>();

    if (window->KeyDown(VK_ESCAPE))
		Engine::Next<Home>();    

	if(arrowNextLevel->CanChangeLevel())
		Engine::Next<Level2>();
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