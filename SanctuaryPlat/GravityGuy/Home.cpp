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

// ------------------------------------------------------------------------------

void Home::Init()
{
    logo = new Sprite("Resources/Home/Logo.png");
    startMessage = new Sprite("Resources/Home/StartMessage.png");
    tileset = new TileSet("Resources/Home/Background.png", 1305, 720, 1, 13);
    anim = new Animation(tileset, 0.1f, true);
    GravityGuy::audio->Volume(MENU, 0.5f);
    GravityGuy::audio->Play(MENU, true);
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
    startMessage->Draw(window->CenterX(), window->CenterY() + 100, Layer::FRONT);
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete anim;
    delete logo;
    delete tileset;
    delete startMessage;
}

// ------------------------------------------------------------------------------