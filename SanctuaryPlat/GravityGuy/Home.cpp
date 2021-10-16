/**********************************************************************************
// Home (Código Fonte) 
// 
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "GravityGuy.h"
#include "Home.h"
#include "Level1.h"

#include <sstream>

using std::stringstream;

// ------------------------------------------------------------------------------

void Home::Init()
{
    logo = new Sprite("Resources/Home/Logo.png");
    tileset = new TileSet("Resources/Home/Background.png", 1305, 720, 1, 13);
    anim = new Animation(tileset, 0.1f, true);
    GravityGuy::audio->Volume(MENU, 0.5f);
    GravityGuy::audio->Play(MENU, true);

    fixedsys = new Font("Resources/Font/fixedsys.png");
    fixedsys->Spacing("Resources/Font/fixedsys.dat");
}

// ------------------------------------------------------------------------------

void Home::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyPress(VK_ESCAPE))
        window->Close();
    
    // se a tecla ENTER for pressionada
    if (window->KeyPress(VK_RETURN))
    {
        GravityGuy::audio->Stop(MENU);
        GravityGuy::NextLevel<Level1>();
    }
    else
    {
        anim->NextFrame();
    }
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
    anim->Draw(window->CenterX(), window->CenterY());
    logo->Draw(window->CenterX(), window->CenterY() - 100, Layer::FRONT);
    
    stringstream ss;
    ss << "Pressione Enter para iniciar";
    
    Color color(1.0f, 1.0f, 1.0f, 1.0f);
    
    fixedsys->Draw(250, window->CenterY() + 100, ss.str().c_str(), color, Layer::FRONT);
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete anim;
    delete logo;
    delete tileset;
    delete fixedsys;
}

// ------------------------------------------------------------------------------