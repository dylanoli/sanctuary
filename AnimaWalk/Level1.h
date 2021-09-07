/***********************************************************************************/

#ifndef _SANCTUARY_LEVEL1_H_
#define _SANCTUARY_LEVEL1_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Level1 : public Game {
private:
    Sprite* backg = nullptr;       // pano de fundo
    bool ctrlKeyESC = false;        // controle do ESC

public:
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// ------------------------------------------------------------------------------

#endif