/**********************************************************************************
// Platform (Código Fonte)
// 
// Criação:     21 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plataformas do jogo
//
**********************************************************************************/

#include "Platform.h"

// ---------------------------------------------------------------------------------

Platform::Platform(float posX, float posY, uint platType, Color tint) : color(tint)
{

    img = new Image("Resources/LongLongGray.png");
    platform = new Sprite(img);
    platform2 = new Sprite(img);
    xSprite = x;
    type = LARGE;
    
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
    xSprite -= 200 * gameTime;
}

// -------------------------------------------------------------------------------

inline void Platform::Draw()
{
    platform->Draw(xSprite, y, Layer::UPPER, 1.0f, 0.0f, color);
    platform2->Draw(xSprite + img->Width(), y, Layer::UPPER, 1.0f, 0.0f, color);

    // traz pano de fundo de volta para dentro da tela
    if (xSprite + img->Width() / 2.0f < 0)
        xSprite += img->Width();
}