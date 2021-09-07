#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "GameOver.h"

// ------------------------------------------------------------------------------

void GameOver::Init()
{
	backg = new Sprite("Resources/GameOver/Background.png");
	logo = new Sprite("Resources/GameOver/GameOver.png");
	restartMessage = new Sprite("Resources/GameOver/RestartMessage.png");
	youCatchUpMessage = new Sprite("Resources/GameOver/YouCatchMessage.png");
	lastLevel = new Sprite("Resources/GameOver/LevelOne.png");
}

// ------------------------------------------------------------------------------

void GameOver::Update()
{
	if (window->KeyDown(VK_ESCAPE))
		Engine::Next<Home>();

	if (window->KeyDown(VK_RETURN))
		Engine::Next<Level1>();
}

// ------------------------------------------------------------------------------

void GameOver::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	logo->Draw(float(window->CenterX()), float(window->CenterY() - 100.0f), Layer::FRONT);
	restartMessage->Draw(float(window->CenterX()), float(window->CenterY() + 160.0f), Layer::FRONT);
	youCatchUpMessage->Draw(float(window->CenterX() - 80.0f), float(window->CenterY() + 30.0f), Layer::FRONT);
	lastLevel->Draw(window->CenterX() + 68.0f, float(window->CenterY() + 33.0f), Layer::FRONT);
}

// ------------------------------------------------------------------------------

void GameOver::Finalize()
{
	delete backg;
	delete logo;
	delete restartMessage;
	delete youCatchUpMessage;
	delete lastLevel;
}

// ------------------------------------------------------------------------------
