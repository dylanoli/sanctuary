/**********************************************************************************
// Shooter (Arquivo de Cabe�alho)
// 
// Cria��o:     15 Out 2012
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz uma fuga suavizada
//
**********************************************************************************/

#ifndef _BASICAI_SHOOTER_H_
#define _BASICAI_SHOOTER_H_

// ---------------------------------------------------------------------------------

#include "Object.h"
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"
#include "Timer.h"                      // controle do tempo

// ---------------------------------------------------------------------------------

class Shooter : public Object
{
private:
    Sprite *sprite; // sprite do objeto
    Player *player; // ponteiro para jogador
    Vector speed;   // velocidade e dire��o
    int distance;   // dist�ncia do jogador

    Timer timer;                        // controla tempo dos disparos
    llong start;                        // marca��o de in�cio do disparo
public:
    Shooter(float pX, float pY, Player *p); // construtor
    ~Shooter();                             // destrutor

    void OnCollision(Object *obj); // resolu��o da colis�o
    void Update();                 // atualiza��o
    void Draw();                   // desenho
};

// ---------------------------------------------------------------------------------

inline void Shooter::Draw()
{
    sprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// ---------------------------------------------------------------------------------

#endif