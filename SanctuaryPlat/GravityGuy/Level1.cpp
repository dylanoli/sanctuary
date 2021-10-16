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
#include "Level2.h"
#include "GameOver.h"
#include "Player.h"
#include "Platform.h"
#include "Background.h"
#include "Obstacle.h"

#include <sstream>

using std::stringstream;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

Scene * Level1::scene = nullptr;

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // pano de fundo do jogo
    backg = new Background(Color{ 1,1,1,1 });
    scene->Add(backg, STATIC);

    // adiciona jogador na cena
    scene->Add(GravityGuy::player, MOVING);

    // ----------------------
    // plataformas
    // ----------------------

    Platform * plat;
    uint  platType;
    Color white { 1,1,1,1 };

    plat = new Platform(window->CenterX(), window->CenterY() + 140, PLATTYPES::LARGE, white);
    scene->Add(plat, STATIC);

    Obstacle* obstacle = new Obstacle(window->CenterX() + 300, window->CenterY() + 95, OBSTACLETYPE::ROCK, white);
    scene->Add(obstacle, STATIC);
    // ----------------------

    // inicia com música
    GravityGuy::audio->Volume(MUSIC, 0.3f);
    GravityGuy::audio->Frequency(JUMP, 1.0f);
    GravityGuy::audio->Play(MUSIC, true);

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
        GravityGuy::audio->Stop(MUSIC);
        GravityGuy::NextLevel<Home>();
        GravityGuy::player->Reset();
    }
    else if (GravityGuy::player->Bottom() < 0 || GravityGuy::player->Top() > window->Height())
    {
        GravityGuy::audio->Stop(MUSIC);
        GravityGuy::NextLevel<GameOver>();
        GravityGuy::player->Reset();
    }
    else if (GravityGuy::player->Level() == 1 || window->KeyPress('N'))
    {
        GravityGuy::audio->Stop(MUSIC);
        GravityGuy::NextLevel<Level2>();
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
    ss << GravityGuy::player->Score();
    tahoma->Draw(window->Height() + 350.0f, 50, ss.str().c_str(), color, Layer::FRONT);


    if (GravityGuy::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    scene->Remove(GravityGuy::player, MOVING);
    delete scene;
    delete fixedsys;
    delete tahoma;
}

// ------------------------------------------------------------------------------
