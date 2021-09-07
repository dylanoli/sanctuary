/***********************************************************************************/

#ifndef _SANCTUARY_LEVEL1_H_
#define _SANCTUARY_LEVEL1_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Player.h"

// ------------------------------------------------------------------------------

class Level1 : public Game {
private:
    Sprite* backg = nullptr;       // pano de fundo
    bool ctrlKeyESC = false;        // controle do ESC
    Scene* scene = nullptr;
    Player* player = nullptr;

public:
    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// ------------------------------------------------------------------------------

#endif