#include "Level1.h"
#include "Engine.h"
#include "Home.h"

// ------------------------------------------------------------------------------

void Level1::Init()
{
	backg = new Sprite("Resources/Home/Background.png");
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    if (window->KeyDown(VK_ESCAPE))
		Engine::Next<Home>();    
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
	delete backg;
}

// ------------------------------------------------------------------------------
