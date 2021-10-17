/**********************************************************************************
// Platform (C�digo Fonte)
// 
// Cria��o:     21 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plataformas do jogo
//
**********************************************************************************/

#include "Platform.h"
#include "GravityGuy.h"

// ---------------------------------------------------------------------------------

Platform::Platform(float posX, float posY)
{
    img = new Image("Resources/LongLongGray.png");
    platform = new Sprite(img);
    platform2 = new Sprite(img);
    xSprite = x;
    
    BBox(new Rect(-platform->Width()/2.0f, 
                  -platform->Height()/2.0f, 
                   platform->Width()/2.0f, 
                   platform->Height()/2.0f));

    MoveTo(posX, posY, Layer::MIDDLE);
}

// ---------------------------------------------------------------------------------

Platform::~Platform()
{
    delete platform;
    delete platform2;
    delete img;
}

// -------------------------------------------------------------------------------

void Platform::Update()
{
    xSprite -= (200 + GravityGuy::player->Score()) * gameTime;
}

// -------------------------------------------------------------------------------

inline void Platform::Draw()
{
    platform->Draw(xSprite, y, Layer::UPPER, 1.0f, 0.0f);
    platform2->Draw(xSprite + img->Width(), y, Layer::UPPER, 1.0f, 0.0f);

    // traz pano de fundo de volta para dentro da tela
    if (xSprite + img->Width() / 2.0f < 0)
        xSprite += img->Width();
}