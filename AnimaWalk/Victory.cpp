#include "Victory.h"
#include "Engine.h"
#include "Home.h"

// ------------------------------------------------------------------------------

void Victory::Init()
{
	backg = new Sprite("Resources/Victory.png");
}

// ------------------------------------------------------------------------------

void Victory::Update()
{
	if (window->KeyDown(VK_RETURN))
		Engine::Next<Home>();
}

// ------------------------------------------------------------------------------

void Victory::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

// ------------------------------------------------------------------------------

void Victory::Finalize()
{
	delete backg;
}

// ------------------------------------------------------------------------------
