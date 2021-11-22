/**********************************************************************************
// Stalker (Arquivo de Cabe�alho)
//
// Cria��o:     10 Out 2012
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz uma persegui��o suavizada
//
**********************************************************************************/

#ifndef _BASICAI_ALEATORIO_H_
#define _BASICAI_ALEATORIO_H_

// ---------------------------------------------------------------------------------

#include "Object.h"
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"
#include "Timer.h"
#include "Random.h"

// ---------------------------------------------------------------------------------

class Aleatorio : public Object
{
private:
    Sprite* sprite; // sprite do objeto
    Player* player; // ponteiro para jogador
    Vector speed;   // velocidade e dire��o
    float factor;   // fator de escala
    Timer timer;
    RandF magnitude;                // valor de magnitude aleatória
    RandF angle;                    // valor de ângulo aleatório    
    RandF secs;                     // valor de segundos aleatório
    float delay;                    // tempo para mudança de direção

public:
    Aleatorio(float pX, float pY, Player* p); // construtor
    ~Aleatorio();                             // destrutor

    void NewDirection();
    void OnCollision(Object* obj); // resolu��o da colis�o
    void Update();                 // atualiza��o
    void Draw();                   // desenho
};

// ---------------------------------------------------------------------------------

inline void Aleatorio::Draw()
{
    sprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// ---------------------------------------------------------------------------------

#endif