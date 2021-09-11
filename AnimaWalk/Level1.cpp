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
	player->MoveTo(window->CenterX(), window->CenterY());
	scene->Add(player, MOVING);
	
	arrowNextLevel = new ArrowNextLevel();
	arrowNextLevel->MoveTo(window->CenterX()+420, window->CenterY());	
	scene->Add(arrowNextLevel, MOVING);

	spawn = new Spawn(2.0, 1, WOLF, scene, player);
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
	spawn->Generate();

	scene->Update();
	scene->CollisionDetection();

    if(arrowNextLevel->CanChangeLevel())
		Engine::Next<Level2>();
	
	if (player->IsDied())
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