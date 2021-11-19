/**********************************************************************************
// Hud (C�digo Fonte)
//
// Cria��o:     02 Ago 2019
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Heads Up Display
//
**********************************************************************************/

#include "Hud.h"
#include "BasicAI.h"
#include "Player.h"

// ------------------------------------------------------------------------------

// inicializa contadores
uint Hud::missiles = 0;
uint Hud::soldiers = 0;
uint Hud::repeaters = 0;
uint Hud::stalker = 0;
uint Hud::shooters = 0;
uint Hud::particles = 0;

// ------------------------------------------------------------------------------

Hud::Hud()
{
    // cria fonte para exibi��o de texto
    font = new Font("Resources/Tahoma14.png");
    font->Spacing("Resources/Tahoma14.dat");
    bold = new Font("Resources/Tahoma14b.png");
    bold->Spacing("Resources/Tahoma14b.dat");

    // carrega sprites
    infoBox = new Sprite("Resources/InfoBox.png");

    // inicializa contador de frames e tempo transcorrido
    frameCount = 0;
    totalTime = 0.0f;
    fps = 0;
}

// ------------------------------------------------------------------------------

Hud::~Hud()
{
    delete font;
    delete bold;
    delete infoBox;
}

// -------------------------------------------------------------------------------

void Hud::Update()
{
    // tempo acumulado dos frames
    totalTime += gameTime;

    // incrementa contador de frames
    frameCount++;

    // a cada 1000ms (1 segundo) atualiza indicador de FPS
    if (totalTime >= 1.0f)
    {
        fps = frameCount;
        frameCount = 0;
        totalTime -= 1.0f;
    }
}

// -------------------------------------------------------------------------------

void Hud::Draw()
{
    // desenha elementos da interface
    infoBox->Draw(game->viewport.left + 140, game->viewport.top + 100, Layer::FRONT);

    // define cor do texto
    Color textColor{0.7f, 0.7f, 0.7f, 1.0f};

    // desenha texto
    text.str("");
    text << "Geometry Wars";
    bold->Draw(40, 62, text.str(), textColor);

    text.str("");
    text << "FPS: " << fps;
    font->Draw(40, 92, text.str(), textColor);

    text.str("");
    text << "Vida: " << Player::life;
    font->Draw(40, 112, text.str(), textColor);

    text.str("");
    text << "Pontuacao: " << Player::score;
    font->Draw(40, 132, text.str(), textColor);
}

// -------------------------------------------------------------------------------
