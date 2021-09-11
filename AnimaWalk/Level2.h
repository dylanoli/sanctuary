/***********************************************************************************/

#ifndef _SANCTUARY_LEVEL2_H_
#define _SANCTUARY_LEVEL2_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Player.h"
#include "ArrowNextLevel.h"

// ------------------------------------------------------------------------------

class Level2 : public Game {
private:
    Sprite* backg = nullptr;       // pano de fundo
    bool ctrlKeyESC = false;        // controle do ESC
    Scene* scene = nullptr;
    Player* player = nullptr;
    ArrowNextLevel* arrowNextLevel = nullptr;

public:
    void Init();                    
    void Update();                  
    void Draw();                    
    void Finalize();                
};

// ------------------------------------------------------------------------------

#endif