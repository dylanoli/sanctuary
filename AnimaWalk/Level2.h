/***********************************************************************************/

#ifndef _SANCTUARY_LEVEL2_H_
#define _SANCTUARY_LEVEL2_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Level2 : public Game {
private:
    Sprite* backg = nullptr;       // pano de fundo
    bool ctrlKeyESC = false;        // controle do ESC

public:
    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// ------------------------------------------------------------------------------

#endif