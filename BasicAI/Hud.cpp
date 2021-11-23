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
uint Hud::aleatorios = 0;

// ------------------------------------------------------------------------------

Hud::Hud()
{
    // cria fonte para exibi��o de texto
    font = new Font("Resources/Charge.png");
    font->Spacing("Resources/Charge.dat");
    bold = new Font("Resources/Robot.png");
    bold->Spacing("Resources/Robot.dat");

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
    infoBox->Draw(game->viewport.right - 220 , game->viewport.top + 100, Layer::FRONT);

    // define cor do texto
    Color textColor{0.7f, 0.7f, 0.7f, 1.0f};

    // desenha texto
    text.str("");
    text << "Rocket Wars";
    bold->Draw(1600, 62, text.str(), textColor);

    text.str("");
    text << "Life:   " << Player::life;
    font->Draw(1600, 92, text.str(), textColor);

    text.str("");
    text << "Score:   " << Player::score;
    font->Draw(1600, 122, text.str(), textColor);
}

// -------------------------------------------------------------------------------

void Hud::ClearCounters() 
{
    missiles = 0;
    soldiers = 0;
    repeaters = 0;
    stalker = 0;
    shooters = 0;
    particles = 0;
    aleatorios = 0;
}
