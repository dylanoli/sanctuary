/**********************************************************************************
// Repeater (C�digo Fonte)
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz um persegui��o direta
//
**********************************************************************************/

#include "BasicAI.h"
#include "Repeater.h"
#include "Random.h"
#include "Hud.h"
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Repeater::Repeater(float pX, float pY, Player *p)
{
    player = p;
    sprite = new Sprite(BasicAI::repeater);
    BBox(new Circle(40));

    speed.RotateTo(90);
    speed.ScaleTo(2.0f);

    MoveTo(pX, pY);
    type = REPEATER;

    // incrementa contador
    ++Hud::repeaters;
}

// ---------------------------------------------------------------------------------

Repeater::~Repeater()
{
    delete sprite;

    // decrementa contador
    --Hud::repeaters;
}

// -------------------------------------------------------------------------------

void Repeater::OnCollision(Object *obj)
{
    if (obj->Type() == MISSILE)
    {
        Player::score += 5;
        BasicAI::scene->Delete(obj, STATIC);
        BasicAI::scene->Delete(this, MOVING);
        BasicAI::scene->Add(new Explosion(x, y), STATIC);
        BasicAI::audio->Play(EXPLODE);
    }
    else if (obj->Type() == REPEATER)
    {
        Repeater *shooterA = this;
        Repeater *shooterB = static_cast<Repeater *>(obj);

        Point pA{shooterA->X(), shooterA->Y()};
        Point pB{shooterB->X(), shooterB->Y()};

        float angleA = Line::Angle(pA, pB);
        float angleB = angleA + 180.0f;

        if (angleB > 360)
            angleB -= 360.0f;

        Vector impactA{angleA, 0.75f * shooterA->speed.Magnitude()};
        Vector impactB{angleB, 0.75f * shooterB->speed.Magnitude()};

        shooterA->speed.Add(impactB);
        shooterB->speed.Add(impactA);

        // limita velocidade das rochas
        if (shooterB->speed.Magnitude() > 15.0f)
            shooterB->speed.ScaleTo(15.0f);

        if (shooterA->speed.Magnitude() > 15.0f)
            shooterA->speed.ScaleTo(15.0f);
    }
}

// -------------------------------------------------------------------------------

void Repeater::Update()
{
    // ajusta �ngulo do vetor
    speed.RotateTo(Line::Angle(Point(x, y), Point(player->X(), player->Y())));

    RotateTo(-speed.Angle() + 90);

    // movimenta objeto pelo seu vetor velocidade
    Translate(speed.XComponent() * 60.0f * gameTime, -speed.YComponent() * 60.0f * gameTime);
}

// -------------------------------------------------------------------------------