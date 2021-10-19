/**********************************************************************************
// Level2 (Código Fonte)
//
// Criação:     27 Set 2021
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 2 do jogo
//
**********************************************************************************/

#include "Sanctuary.h"
#include "Home.h"
#include "Level2.h"
#include "GameOver.h"
#include "Player.h"
#include "Platform.h"
#include "Background.h"

#include <sstream>
#include "SpawnObstacule.h"

using std::stringstream;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

Scene* Level2::scene = nullptr;

// ------------------------------------------------------------------------------

void Level2::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // pano de fundo do jogo
    Color dark{ 0.29f, 0.0f, 0.5f, 1.0f };
    backg = new Background(dark);
    scene->Add(backg, STATIC);

    Platform * plat = new Platform(window->CenterX(), window->CenterY() + 140);
    scene->Add(plat, STATIC);

    SpawnObstacule* spo = new SpawnObstacule(scene, 1.0f, 2.0f);
    scene->Add(spo, STATIC);

    // adiciona jogador na cena
    scene->Add(Sanctuary::player, MOVING);

    Sanctuary::audio->Frequency(JUMP, 0.85f);
    Sanctuary::audio->Volume(MUSIC2, 0.3f);
    Sanctuary::audio->Play(MUSIC2, true);

    fixedsys = new Font("Resources/Font/fixedsys.png");
    fixedsys->Spacing("Resources/Font/fixedsys.dat");

    tahoma = new Font("Resources/Font/tahoma.png");
    tahoma->Spacing("Resources/Font/tahoma.dat");
}

// ------------------------------------------------------------------------------

void Level2::Update()
{
    if (window->KeyPress(VK_ESCAPE) || window->KeyPress('N'))
    {
        Sanctuary::audio->Stop(MUSIC2);
        Sanctuary::NextLevel<Home>();
        Sanctuary::player->Reset();
    }
    else if (!Sanctuary::player->IsAlive())
    {
        Sanctuary::audio->Stop(MUSIC2);
        Sanctuary::NextLevel<GameOver>();
    }
    else
    {
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level2::Draw()
{
    backg->Draw();
    scene->Draw();

    Color color(1.0f, 1.0f, 1.0f, 1.0f);
    fixedsys->Draw(window->Height() + 300.0f, 20, "Level 2", color, Layer::FRONT);

    stringstream ss;
    ss << "Score: " << Sanctuary::player->Score();
    tahoma->Draw(window->Height() + 310, 50, ss.str().c_str(), color, Layer::FRONT);

    if (Sanctuary::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
    scene->Remove(Sanctuary::player, MOVING);
    delete scene;
    delete fixedsys;
    delete tahoma;
}

// ------------------------------------------------------------------------------
