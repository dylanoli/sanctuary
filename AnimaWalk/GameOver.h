/***********************************************************************************/

#ifndef _SANCTUARY_GAME_OVER_H_
#define _SANCTUARY_GAME_OVER_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class GameOver : public Game {
private:
    Sprite* backg = nullptr;       // pano de fundo
    Sprite* logo = nullptr;       // pano de fundo
    Sprite* restartMessage = nullptr;
    Sprite* youCatchUpMessage = nullptr;
    Sprite* lastLevel = nullptr;
    bool ctrlKeyESC = false;        // controle do ESC

public:
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// ------------------------------------------------------------------------------

#endif