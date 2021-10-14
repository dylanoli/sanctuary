/**********************************************************************************
// Level1 (C�digo Fonte)
//
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   N�vel 1 do jogo
//
**********************************************************************************/

#include "GravityGuy.h"
#include "Home.h"
#include "Level1.h"
#include "Player.h"
#include "Platform.h"

#include <string>
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros est�ticos da classe

Scene* Level1::scene = nullptr;

// ------------------------------------------------------------------------------

void Level1::Init()
{

    backg = new Sprite("Resources/Background.png");

    // cria gerenciador de cena
    scene = new Scene();

    // ----------------------
    // plataformas
    // ----------------------

    Platform* plat;
    float posX, posY;
    uint  platType;
    Color white{ 1,1,1,1 };

    plat = new Platform(200, window->CenterY() + 200, PLATTYPES::LARGE, white);
    scene->Add(plat, STATIC);

    plat = new Platform(720, window->CenterY() + 60, PLATTYPES::SMALL, white);
    scene->Add(plat, STATIC);

    plat = new Platform(440, window->CenterY() - 120, PLATTYPES::SMALL, white);
    scene->Add(plat, STATIC);

    Player * player = new Player(scene);
    scene->Add(player, MOVING);
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    if (window->KeyPress(VK_ESCAPE))
    {
        Engine::Next<Home>();
    }
    else
    {
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
        scene->DrawBBox();
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
    scene->Draw();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    delete scene;
}

// ------------------------------------------------------------------------------
