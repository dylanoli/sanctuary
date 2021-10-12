/**********************************************************************************
// Level1 (Código Fonte)
//
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 1 do jogo
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
// Inicializa membros estáticos da classe

Scene* Level1::scene = nullptr;

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // ----------------------
    // plataformas
    // ----------------------

    Platform* plat;
    float posX, posY;
    uint  platType;
    Color white{ 1,1,1,1 };

    plat = new Platform(200, window->CenterY() + 100, PLATTYPES::LARGE, white);
    scene->Add(plat, STATIC);

    plat = new Platform(650, window->CenterY(), PLATTYPES::SMALL, white);
    scene->Add(plat, STATIC);

    plat = new Platform(440, window->CenterY() - 80, PLATTYPES::SMALL, white);
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
    scene->Draw();

    if (GravityGuy::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    delete scene;
}

// ------------------------------------------------------------------------------
