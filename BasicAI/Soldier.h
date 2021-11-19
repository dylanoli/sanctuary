/**********************************************************************************
// Soldier (Arquivo de Cabe�alho)
// 
// Cria��o:     05 Ago 2019
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz movimento retil�neo
//
**********************************************************************************/

#ifndef _BASICAI_SOLDIER_H_
#define _BASICAI_SOLDIER_H_

// ---------------------------------------------------------------------------------

#include "Object.h"
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

class Soldier : public Object
{
private:
    Sprite *sprite;  // sprite da nave
    Particles *tail; // calda da nave
    uint tailCount;  // quantidade de part�culas da calda
    Vector speed;    // velocidade e dire��o

public:
    Soldier(float pX, float pY, float ang); // construtor
    ~Soldier();                             // destrutor

    void OnCollision(Object *obj); // resolu��o da colis�o
    void Update();                 // atualiza��o
    void Draw();                   // desenho
};

// ---------------------------------------------------------------------------------

#endif