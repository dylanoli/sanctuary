/**********************************************************************************
// GameOver (Arquivo de Cabe�alho)
// 
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Fim do jogo
//              
**********************************************************************************/

#ifndef _GRAVITYGUY_GAMEOVER_H_
#define _GRAVITYGUY_GAMEOVER_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Font.h"

// ------------------------------------------------------------------------------

class GameOver : public Game
{
private:
    Sprite* logo = nullptr;
    TileSet* tileset = nullptr;    // tileset da anima��o
    Animation* anim = nullptr;     // anima��o do menu
    Font* fixedsys = nullptr;

public:
    void Init();                    // inicializa��o do n�vel
    void Update();                  // l�gica da tela de fim
    void Draw();                    // desenho da tela
    void Finalize();                // finaliza��o do n�vel
};

// ------------------------------------------------------------------------------

#endif