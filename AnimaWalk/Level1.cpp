#include "Level1.h"
#include "Level2.h"
#include "Engine.h"
#include "Home.h"
#include "GameOver.h"

// ------------------------------------------------------------------------------

void Level1::Init()
{
	backg = new Sprite("Resources/Background.png");
	introMessage = new Sprite("Resources/IntroMessage.png");
	scene = new Scene();

	player = new Player(scene);	
	spawn = new Spawn(4.0f, 3, WOLF, RIGHT_ONLY, scene, player);

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
		arrowNextLevel->MoveTo(window->CenterX() + 420, window->CenterY() + 100);
		scene->Add(arrowNextLevel, MOVING);
	}

	if (arrowExists && arrowNextLevel->CanChangeLevel())
		Engine::Next<Level2>();
	
	if (!arrowExists && player->IsDied())
		Engine::Next<GameOver>(LEVEL1);

	if (window->KeyDown(VK_ESCAPE))
		Engine::Next<Home>();
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
	introMessage->Draw(float(window->CenterX()), float(window->CenterY() + 200.0f), Layer::FRONT);
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();
	scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
	delete backg;
	delete introMessage;
	delete scene;
}