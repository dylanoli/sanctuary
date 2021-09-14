/***********************************************************************************/

#ifndef _SANCTUARY_LEVEL1_H_
#define _SANCTUARY_LEVEL1_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Player.h"
#include "ArrowNextLevel.h"
#include "Spawn.h"

// ------------------------------------------------------------------------------

class Level1 : public Game {
private:
    Sprite* backg = nullptr;       // pano de fundo
    Sprite* introMessage = nullptr;
    bool ctrlKeyESC = false;        // controle do ESC
    Scene* scene = nullptr;
    Player* player = nullptr;
    ArrowNextLevel* arrowNextLevel = nullptr;
    Spawn* spawn = nullptr;
    bool arrowExists = false;
    

public:
    void Init();                    
    void Update();                  
    void Draw();    
    void Finalize();
};

// ------------------------------------------------------------------------------

#endif