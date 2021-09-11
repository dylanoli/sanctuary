/***********************************************************************************/

#ifndef _SANCTUARY_LEVEL3_H_
#define _SANCTUARY_LEVEL3_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Player.h"
#include "ArrowNextLevel.h"
#include "Spawn.h"

// ------------------------------------------------------------------------------

class Level3 : public Game {
private:
    Sprite* backg = nullptr;       // pano de fundo
    bool ctrlKeyESC = false;        // controle do ESC
    Scene* scene = nullptr;
    Player* player = nullptr;
    ArrowNextLevel* arrowNextLevel = nullptr;
    Spawn* spawn = nullptr;
    bool arrowExists = false;

public:
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// ------------------------------------------------------------------------------

#endif