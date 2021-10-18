/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador 
//
**********************************************************************************/

#ifndef _SANCTUARY_PLAYER_H_
#define _SANCTUARY_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet   * tileset;                // folha de sprites do personagem
    Animation * anim;                   // anima��o do personagem
    bool isOnTheFloor;
    bool isAlive = true;
    boolean jumping;
    Timer jumpDuration;
    float velY;
    Timer scoreInterval;
    uint score;
    
public:
    Player();                           // construtor
    ~Player();                          // destrutor

    void Reset();                       // volta ao estado inicial
    float Bottom();                     // coordenadas da base
    float Top();                        // coordenadas do topo
    bool IsAlive();                        // coordenadas do topo

    void OnCollision(Object * obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
    uint Score();
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline
inline bool Player::IsAlive()
{ return isAlive; }

inline float Player::Bottom()
{ return y + tileset->Height()/2; }

inline float Player::Top()
{ return y - tileset->Height()/2; }

inline void Player::Draw()
{ anim->Draw(x, y, z); }

inline uint Player::Score() 
{ return score; }

// ---------------------------------------------------------------------------------

#endif