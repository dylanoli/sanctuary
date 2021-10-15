/**********************************************************************************
// Platform (Arquivo de Cabe�alho)
//
// Cria��o:     21 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plataformas do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_OBSTACLE_H_
#define _GRAVITYGUY_OBSTACLE_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                                      // tipos espec�ficos da engine
#include "Object.h"                                     // interface de Object
#include "Sprite.h"                                     // desenho de sprites

// ---------------------------------------------------------------------------------

enum OBSTACLETYPE { ROCK };

// ---------------------------------------------------------------------------------

class Obstacle : public Object
{
private:
    Sprite* obstacle = nullptr;            // sprite da plataforma
    Color color;                            // cor da plataforma

public:
    Obstacle(float posX, float posY,
        uint platType,
        Color tint);                   // construtor    
    ~Obstacle();                            // destrutor

    void Update();                          // atualiza��o do objeto
    void Draw();                            // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Obstacle::Draw()
{
    obstacle->Draw(x, y, z, 1.0f, 0.0f, color);
}

// ---------------------------------------------------------------------------------

#endif