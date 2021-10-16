/**********************************************************************************
// GameOver (Arquivo de Cabeçalho)
// 
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Fim do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "GameOver.h"
#include "GravityGuy.h"
#include "Home.h"

#include <sstream>

using std::stringstream;

// ----------------------------------------------------------------------

void GameOver::Init()
{
    logo = new Sprite("Resources/GameOver.png");
    tileset = new TileSet("Resources/Home/Background.png", 1305, 720, 1, 13);
    anim = new Animation(tileset, 0.1f, true);

    GravityGuy::audio->Volume(FINAL, 0.3f);
    GravityGuy::audio->Play(FINAL, true);

    fixedsys = new Font("Resources/Font/fixedsys.png");
    fixedsys->Spacing("Resources/Font/fixedsys.dat");
}

// ----------------------------------------------------------------------

void GameOver::Update()
{
    if (window->KeyPress(VK_ESCAPE) || window->KeyPress(VK_RETURN)) {
        GravityGuy::audio->Stop(FINAL);
        GravityGuy::NextLevel<Home>();
    }
}

// ----------------------------------------------------------------------

void GameOver::Draw()
{
    Color dark{ 0.4f, 0.4f, 0.4f, 1.0f };
    anim->Draw(window->CenterX(), window->CenterY(), Layer::MIDDLE, dark);

    logo->Draw(window->CenterX(), window->CenterY() - 100, Layer::FRONT);

    Color color(1.0f, 1.0f, 1.0f, 1.0f);
    
    stringstream ss;
    
    ss << "Você alcançou a pontuação de: ";    
    fixedsys->Draw(250, window->CenterY() + 100, ss.str().c_str(), color, Layer::FRONT);
    
    ss.str("");
    ss << GravityGuy::player->Score() << " pontos";
    fixedsys->Draw(400, window->CenterY() + 140, ss.str().c_str(), color, Layer::FRONT);
}

// ----------------------------------------------------------------------

void GameOver::Finalize()
{
    delete anim;
    delete tileset;
    delete logo;
    delete fixedsys;
}

// ----------------------------------------------------------------------

