/**********************************************************************************
// Player (C�digo Fonte)
// 
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador 
//
**********************************************************************************/

#include "Player.h"
#include "GravityGuy.h"
#include "Platform.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    tileset = new TileSet("Resources/GravityGuy.png", 32, 48, 5, 10);
    anim = new Animation(tileset, 0.120f, true);

    // sequ�ncias de anima��o do player
    uint invert[4] = {6,7,8,9};
    uint normal[4] = {1,2,3,4};

    anim->Add(0, invert, 4);
    anim->Add(1, normal, 4);

    // cria bounding box
    BBox(new Rect(
        -1.0f * tileset->TileWidth() / 2.0f,
        -1.0f * tileset->TileHeight() / 2.0f,
        tileset->TileWidth() / 2.0f,
        tileset->TileHeight() / 2.0f));
    
    // inicializa estado do player
    level = 0;
    velY = 0.0f;
    jumping = false;
    isOnTheFloor = false;
    
    // posi��o inicial
    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete anim;
    delete tileset;    
}

// ---------------------------------------------------------------------------------

void Player::Reset()
{
    // volta ao estado inicial
    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
    level = 0;
}


// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    if (obj->Type() == FINISH)
    {
        // chegou ao final do n�vel
        level++;
    }
    else
    {
        // mant�m personagem em cima da plataforma
        if (!jumping) {
            isOnTheFloor = true;
            MoveTo(window->CenterX(), obj->Y() - 40);
        }
    }

    // ----------------------------------------------------------
    // Processa teclas pressionadas
    // ----------------------------------------------------------
    // jogador s� pode alterar a gravidade enquanto estiver
    // em cima de uma plataforma, n�o � poss�vel a mudan�a no ar
    // ----------------------------------------------------------

    if (window->KeyPress(VK_UP))
    {
        // toca efeito sonoro
        GravityGuy::audio->Play(TRANSITION);        
    }
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    if (jumping)
    {
        if (jumpDuration.Elapsed(0.5f))
        {
            jumping = false;
            velY = 0;
        }
        else
        {
            velY += 1000.f * gameTime;
        }

        Translate(0, velY * gameTime);
    }
    else
    {
        if (window->KeyPress(VK_UP) && isOnTheFloor)
        {
            velY = -400;

            // inicia temporizadores
            jumpDuration.Start();
            jumping = true;
            isOnTheFloor = false;
        }

        Translate(0, 300 * gameTime);
    }

    // atualiza anima��o
    anim->NextFrame();
}

// ---------------------------------------------------------------------------------