#include "Level1.h"
#include "Engine.h"
#include "Home.h"
#include "Enemy.h"

// ------------------------------------------------------------------------------

void Level1::Init()
{
	backg = new Sprite("Resources/Home/Background.png");
	scene = new Scene();
	player = new Player(scene);
	auto enemy = new Enemy(player, scene);
	player->MoveTo(window->CenterX(), window->CenterY());
	scene->Add(player, MOVING);
	scene->Add(enemy, MOVING);
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
	scene->Update();
	scene->CollisionDetection();

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

// ------------------------------------------------------------------------------
