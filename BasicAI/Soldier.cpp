/**********************************************************************************
// Soldier (C�digo Fonte)
// 
// Cria��o:     05 Ago 2019
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz movimento retil�neo
//
**********************************************************************************/

#include "BasicAI.h"
#include "Soldier.h"
#include "Random.h"
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Soldier::Soldier(float pX, float pY, float ang)
{
    sprite = new Sprite(BasicAI::soldier);

    // ajusta o vetor velocidade
    speed.RotateTo(ang);
    speed.ScaleTo(400);
    RotateTo(-speed.Angle());
    BBox(new Circle(40.0f));
    MoveTo(pX, pY);
    type = SOLDIER;

    // configura��o do emissor de part�culas
    Generator emitter;
    emitter.imgFile = "Resources/Spark.png"; // arquivo de imagem
    emitter.angle = speed.Angle() + 180;     // �ngulo base do emissor
    emitter.spread = 5;                      // espalhamento em graus
    emitter.lifetime = 0.4f;                 // tempo de vida em segundos
    emitter.frequency = 0.010f;              // tempo entre gera��o de novas part�culas
    emitter.percentToDim = 0.8f;             // desaparece ap�s 60% da vida
    emitter.minSpeed = 100.0f;               // velocidade m�nima das part�culas
    emitter.maxSpeed = 200.0f;               // velocidade m�xima das part�culas
    emitter.color.r = 1.0f;                  // componente Red da part�cula
    emitter.color.g = 0.5;                   // componente Shooter da part�cula
    emitter.color.b = 0.0f;                  // componente stalker da part�cula
    emitter.color.a = 1.0f;                  // transpar�ncia da part�cula

    // cria sistema de part�culas
    tail = new Particles(emitter);
    tailCount = 0;

    // incrementa contagem
    ++Hud::soldiers;
}

// ---------------------------------------------------------------------------------

Soldier::~Soldier()
{
    delete sprite;
    delete tail;

    // decrementa contagem
    Hud::particles -= tailCount;
    --Hud::soldiers;
}

// -------------------------------------------------------------------------------

void Soldier::OnCollision(Object *obj)
{
    if (obj->Type() == MISSILE || obj->Type() == PLAYER)
    {
        if (obj->Type() == MISSILE)
        {
            Player::score += 5;
            BasicAI::scene->Delete(obj, STATIC);
        }
        BasicAI::scene->Delete(this, MOVING);
        BasicAI::scene->Add(new Explosion(x, y), STATIC);
        BasicAI::audio->Play(EXPLODE);
    }
}

// -------------------------------------------------------------------------------

void Soldier::Update()
{
    // movimenta objeto pelo seu vetor velocidade
    Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);

    // ajusta �ngulo do vetor na dire��o oposta
    if (x < 50 || y < 50 || x > game->Width() - 50 || y > game->Height() - 50)
    {
        Rotate(180);
        speed.Rotate(180);
        Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);
    }

    // atualiza calda da nave
    tail->Config().angle = speed.Angle();
    tail->Generate(x - 10 * cos(speed.Radians()), y + 10 * sin(speed.Radians()));
    tail->Update(gameTime);

    Hud::particles -= tailCount;
    tailCount = tail->Size();
    Hud::particles += tailCount;
}

// ---------------------------------------------------------------------------------

void Soldier::Draw()
{
    sprite->Draw(x, y, Layer::LOWER, scale, rotation);
    tail->Draw(Layer::LOWER, 1.0f);
}

// -------------------------------------------------------------------------------