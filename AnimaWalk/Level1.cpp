#include "Level1.h"
#include "Engine.h"
#include "Home.h"

// ------------------------------------------------------------------------------

void Level1::Init()
{
	backg = new Sprite("Resources/Home/Background.png");
	scene = new Scene();
	player = new Player(scene);
	player->MoveTo(window->CenterX(), window->CenterY());
	scene->Add(player, MOVING);
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
	scene->Update();
    if (window->KeyDown(VK_ESCAPE))
		Engine::Next<Home>();    
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
	delete backg;
}

// ------------------------------------------------------------------------------
