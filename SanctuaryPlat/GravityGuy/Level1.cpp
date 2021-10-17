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

#include "Sanctuary.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "GameOver.h"
#include "Player.h"
#include "Platform.h"
#include "Background.h"
#include "Obstacle.h"
#include "SpawnObstacule.h"

#include <sstream>

using std::stringstream;

// ------------------------------------------------------------------------------
// Inicializa membros est�ticos da classe

Scene *Level1::scene = nullptr;

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // pano de fundo do jogo
    backg = new Background(Color{1, 1, 1, 1});
    scene->Add(backg, STATIC);

    // adiciona jogador na cena
    scene->Add(Sanctuary::player, MOVING);

    // ----------------------
    // plataformas
    // ----------------------

    Platform *plat;
    Color white{1, 1, 1, 1};

    plat = new Platform(window->CenterX(), window->CenterY() + 140);
    scene->Add(plat, STATIC);

    SpawnObstacule *spo = new SpawnObstacule(scene);
    scene->Add(spo, STATIC);
    // ----------------------

    // inicia com m�sica
    Sanctuary::audio->Volume(MUSIC, 0.3f);
    Sanctuary::audio->Frequency(JUMP, 1.0f);
    Sanctuary::audio->Play(MUSIC, true);

    fixedsys = new Font("Resources/Font/fixedsys.png");
    fixedsys->Spacing("Resources/Font/fixedsys.dat");

    tahoma = new Font("Resources/Font/tahoma.png");
    tahoma->Spacing("Resources/Font/tahoma.dat");
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    if (window->KeyPress(VK_ESCAPE))
    {
        Sanctuary::audio->Stop(MUSIC);
        Sanctuary::NextLevel<Home>();
        Sanctuary::player->Reset();
    }
    else if (!Sanctuary::player->IsAlive())
    {
        Sanctuary::audio->Stop(MUSIC);
        Sanctuary::NextLevel<GameOver>();
    }
    else if (Sanctuary::player->Level() == 1 || window->KeyPress('N'))
    {
        Sanctuary::audio->Stop(MUSIC);
        Sanctuary::NextLevel<Level2>();
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
    backg->Draw();
    scene->Draw();

    Color color(1.0f, 1.0f, 1.0f, 1.0f);
    fixedsys->Draw(window->Height() + 300.0f, 20, "Level 1", color, Layer::FRONT);

    stringstream ss;
    ss << "Score: " << Sanctuary::player->Score();
    tahoma->Draw(window->Height() + 310, 50, ss.str().c_str(), color, Layer::FRONT);

    if (Sanctuary::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    scene->Remove(Sanctuary::player, MOVING);
    delete scene;
    delete fixedsys;
    delete tahoma;
}

// ------------------------------------------------------------------------------
