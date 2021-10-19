/**********************************************************************************
// Platform (Arquivo de Cabeçalho)
//
// Criação:     21 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plataformas do jogo
//
**********************************************************************************/

#ifndef _SANCTUARY_OBSTACLE_H_
#define _SANCTUARY_OBSTACLE_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                                      // tipos específicos da engine
#include "Object.h"                                     // interface de Object
#include "Sprite.h"                                     // desenho de sprites
#include <random>
#include "Timer.h"
#include "Scene.h"   

using namespace std;
// ---------------------------------------------------------------------------------

enum OBSTACLETYPE { ROCK };

// ---------------------------------------------------------------------------------

class Obstacle : public Object
{
private:
    Sprite* obstacle = nullptr;            // sprite da plataforma
    Scene* scene = nullptr;

public:
    Obstacle(float posX, float posY, Scene* _scene);
    ~Obstacle();                            // destrutor

    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Obstacle::Draw()
{
    obstacle->Draw(x, y, z, 1.0f, 0.0f);
}

// ---------------------------------------------------------------------------------

#endif