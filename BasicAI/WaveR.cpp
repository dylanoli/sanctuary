/**********************************************************************************
// WaveB (C�digo Fonte)
//
// Cria��o:     06 Ago 2019
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Cria uma onda de inimigos Stalker
//
**********************************************************************************/

#include "WaveR.h"
#include "BasicAI.h"
#include "Aleatorio.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

WaveR::WaveR() : posX(0, window->Width()), posY(0, window->Height()), secs(8.0f, 12.0f)
{
    // posi��o dos inimigos
    pX = posX.Rand();
    pY = posY.Rand();

    // atraso para a pr�xima onda
    delay = secs.Rand();
}

// ------------------------------------------------------------------------------

WaveR::~WaveR()
{
}

// -------------------------------------------------------------------------------

void WaveR::Update()
{
    // contador de inimigos
    static uint counter = 4;

    // se passou o tempo de atraso
    if (timer.Elapsed(delay) && Hud::aleatorios < 15)
    {
        if (counter > 0)
        {
            // toca som de nova onda
            BasicAI::audio->Play(ALEATORIO);

            // adiciona nova inimigo
            BasicAI::scene->Add(new Aleatorio(pX, pY, BasicAI::player), MOVING);

            delay = 0.850f;
            timer.Start();
            --counter;
        }
        else
        {
            // nova posi��o do inimigo
            pX = posX.Rand();
            pY = posY.Rand();

            // nova onda
            counter = 4;
            delay = secs.Rand();
            timer.Start();
        }
    }
}

// -------------------------------------------------------------------------------

void WaveR::Draw()
{
}

// -------------------------------------------------------------------------------
