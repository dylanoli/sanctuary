/**********************************************************************************
// WaveG (C�digo Fonte)
//
// Cria��o:     06 Ago 2019
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Cria uma onda de inimigos Shooter
//
**********************************************************************************/

#include "WaveG.h"
#include "BasicAI.h"
#include "Shooter.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

WaveG::WaveG() : secs(10.0f, 15.0f)
{
    // atraso para a pr�xima onda
    delay = secs.Rand();
}

// ------------------------------------------------------------------------------

WaveG::~WaveG()
{
}

// -------------------------------------------------------------------------------

void WaveG::Update()
{
    // contador de inimigos
    static uint counter = 1;

    // se passou o tempo de atraso
    if (timer.Elapsed(delay) && Hud::shooters < 16)
    {
        if (counter > 0)
        {
            // toca som de nova onda
            BasicAI::audio->Play(SHOOTER);

            // adiciona nova inimigo
            BasicAI::scene->Add(new Shooter(50, 50, BasicAI::player), MOVING);
            BasicAI::scene->Add(new Shooter(game->Width() - 50, 50, BasicAI::player), MOVING);
            BasicAI::scene->Add(new Shooter(game->Width() - 50, game->Height() - 50, BasicAI::player), MOVING);
            BasicAI::scene->Add(new Shooter(50, game->Height() - 50, BasicAI::player), MOVING);

            delay = 1.0f;
            timer.Start();
            --counter;
        }
        else
        {
            // nova onda
            counter = 1;
            delay = secs.Rand();
            timer.Start();
        }
    }
}

// -------------------------------------------------------------------------------

void WaveG::Draw()
{
}

// -------------------------------------------------------------------------------
