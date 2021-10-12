/***********************************************************************************/

#ifndef _SANCTUARY_HOME_H_
#define _SANCTUARY_HOME_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

class Home : public Game {
    private:
        Sprite* backg = nullptr;       
        Sprite* logo = nullptr;
        Sprite* startMessage = nullptr;
        bool ctrlKeyESC = false;        

    public:
        void Init();                    // inicializa��o
        void Update();                  // atualiza��o
        void Draw();                    // desenho
        void Finalize();                // finaliza��o
};

// ------------------------------------------------------------------------------

#endif