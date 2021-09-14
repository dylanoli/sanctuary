/***********************************************************************************/

#ifndef _SANCTUARY_GAME_OVER_H_
#define _SANCTUARY_GAME_OVER_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

enum LastLevel { LEVEL1, LEVEL2, LEVEL3 };

class GameOver : public Game {
private:
    Sprite* backg = nullptr;       // pano de fundo
    Sprite* logo = nullptr;       // pano de fundo
    Sprite* restartMessage = nullptr;
    Sprite* youCatchUpMessage = nullptr;
    Sprite* lastLevel = nullptr;
    bool ctrlKeyESC = false;        // controle do ESC

public:
    GameOver(uint);
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// ------------------------------------------------------------------------------

#endif