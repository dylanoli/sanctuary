/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador 
//
**********************************************************************************/

#ifndef _SANCTUARY_PLAYER_H_
#define _SANCTUARY_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet   * tileset;                // folha de sprites do personagem
    Animation * anim;                   // animação do personagem
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

    void OnCollision(Object * obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
    uint Score();
};

// ---------------------------------------------------------------------------------
// Função Membro Inline
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