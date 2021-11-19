/**********************************************************************************
// Repeater (Arquivo de Cabe�alho)
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz um persegui��o direta
//
**********************************************************************************/

#ifndef _BASICAI_REPEATER_H_
#define _BASICAI_REPEATER_H_

// ---------------------------------------------------------------------------------

#include "Object.h"
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

class Repeater : public Object
{
private:
    Sprite *sprite; // sprite do objeto
    Player *player; // ponteiro para jogador
    Vector speed;   // velocidade e dire��o

public:
    Repeater(float pX, float pY, Player *p); // construtor
    ~Repeater();                             // destrutor

    void OnCollision(Object *obj); // resolu��o da colis�o
    void Update();                 // atualiza��o
    void Draw();                   // desenho
};

// ---------------------------------------------------------------------------------

inline void Repeater::Draw()
{
    sprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// ---------------------------------------------------------------------------------

#endif