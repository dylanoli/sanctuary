/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador 
//
**********************************************************************************/

#include "Player.h"
#include "GravityGuy.h"
#include "Platform.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    tileset = new TileSet("Resources/astronner.png", 126, 126, 4, 13);
    anim = new Animation(tileset, 0.120f, true);

    // sequências de animação do player
    uint SeqRight[4] = { 3, 4, 5, 6 };

    anim->Add(0, SeqRight, 4);

    // cria bounding box
    BBox(new Rect(-20, -50, 20, 50));    
    
    // inicializa estado do player
    level = 0;
    velY = 0.0f;
    jumping = false;
    isOnTheFloor = false;
    
    // posição inicial
    MoveTo(100, 24.0f, Layer::FRONT);

    scoreInterval.Start();
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
        // chegou ao final do nível
        level++;
    }
    else
    {
        // mantém personagem em cima da plataforma
        if (!jumping) {
            isOnTheFloor = true;
            MoveTo(x, obj->Y() - 70);
        }
    }

}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    if (jumping)
    {
        if (jumpDuration.Elapsed(1.0f))
        {
            jumping = false;
            velY = 0;
        }
        else
        {
            velY += 700.f * gameTime;
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

            GravityGuy::audio->Volume(TRANSITION, 0.05f);
            GravityGuy::audio->Play(TRANSITION);
        }

        Translate(0, 300 * gameTime);
    }

    // atualiza animação
    anim->NextFrame();

    if (scoreInterval.Elapsed(0.2f)) {
        score += 1;
        scoreInterval.Reset();
    }
}

// ---------------------------------------------------------------------------------