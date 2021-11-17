/**********************************************************************************
// Blue (Código Fonte)
// 
// Criação:     10 Out 2012
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz uma perseguição suavizada
//
**********************************************************************************/

#include "BasicAI.h"
#include "Blue.h"
#include "Random.h" 
#include "Hud.h"
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Blue::Blue(float pX, float pY, Player* p)
{
    player = p;
    sprite = new Sprite(BasicAI::blue);
    BBox(new Circle(20.0f));
    speed.RotateTo(0.0f);
    speed.ScaleTo(0.0f);
    MoveTo(pX, pY);
    type = BLUE;

    // incrementa contador
    ++Hud::blues;
}

// ---------------------------------------------------------------------------------

Blue::~Blue()
{
    delete sprite;

    // decrementa contador
    --Hud::blues;
}

// -------------------------------------------------------------------------------

void Blue::OnCollision(Object * obj)
{
    if (obj->Type() == MISSILE)
    {
        BasicAI::scene->Delete(obj, STATIC);
        BasicAI::scene->Delete(this, MOVING);
        BasicAI::scene->Add(new Explosion(x, y), STATIC);
        BasicAI::audio->Play(EXPLODE);
    }
    else if (obj->Type() == BLUE) {
        Blue* greenA = this;
        Blue* greenB = static_cast<Blue*>(obj);

        Point pA{ greenA->X(), greenA->Y() };
        Point pB{ greenB->X(), greenB->Y() };

        float angleA = Line::Angle(pA, pB);
        float angleB = angleA + 180.0f;

        if (angleB > 360)
            angleB -= 360.0f;

        Vector impactA{ angleA, 0.75f * greenA->speed.Magnitude() };
        Vector impactB{ angleB, 0.75f * greenB->speed.Magnitude() };

        greenA->speed.Add(impactB);
        greenB->speed.Add(impactA);

        // limita velocidade das rochas
        if (greenB->speed.Magnitude() > 15.0f)
            greenB->speed.ScaleTo(15.0f);

        if (greenA->speed.Magnitude() > 15.0f)
            greenA->speed.ScaleTo(15.0f);
    }
}

// -------------------------------------------------------------------------------

void Blue::Update()
{
    // a magnitude do vetor 'target' controla quão 
    // rápido o objeto converge para a direção do alvo
    Vector target { Line::Angle(Point(x, y), Point(player->X(), player->Y())), 50.0f * gameTime };
    speed.Add(target);

    RotateTo(-speed.Angle() + 90);

    // limita a magnitude da velocidade para impedir 
    // que ela cresça indefinidamente pelo soma vetorial
    if (speed.Magnitude() > 4.5)
        speed.ScaleTo(4.5f);

    // move o objeto pelo seu vetor velocidade
    Translate(speed.XComponent() * 50.0f * gameTime, -speed.YComponent() * 50.0f * gameTime);

    // mantém o objeto dentro do mundo do jogo
    if (x < 50)
        MoveTo(50, y);
    if (y < 50)
        MoveTo(x, 50);
    if (x > game->Width() - 50)
        MoveTo(game->Width() - 50, y);
    if (y > game->Height() - 50)
        MoveTo(x, game->Height() - 50);
}

// -------------------------------------------------------------------------------