/**********************************************************************************
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz uma persegui��o suavizada
//
**********************************************************************************/

#include "BasicAI.h"
#include "Stalker.h"
#include "Random.h"
#include "Hud.h"
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Stalker::Stalker(float pX, float pY, Player *p)
{
    player = p;
    sprite = new Sprite(BasicAI::stalker);
    BBox(new Circle(40.0f));
    speed.RotateTo(0.0f);
    speed.ScaleTo(0.0f);
    MoveTo(pX, pY);
    type = STALKER;

    // incrementa contador
    ++Hud::stalker;
}

// ---------------------------------------------------------------------------------

Stalker::~Stalker()
{
    delete sprite;

    // decrementa contador
    --Hud::stalker;
}

// -------------------------------------------------------------------------------

void Stalker::OnCollision(Object *obj)
{
    if (obj->Type() == MISSILE)
    {
        Player::score += 10;
        BasicAI::scene->Delete(obj, STATIC);
        BasicAI::scene->Delete(this, MOVING);
        BasicAI::scene->Add(new Explosion(x, y), STATIC);
        BasicAI::audio->Play(EXPLODE);
    }
    else if (obj->Type() == STALKER)
    {
        Stalker *shooterA = this;
        Stalker *shooterB = static_cast<Stalker *>(obj);

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

void Stalker::Update()
{
    // a magnitude do vetor 'target' controla qu�o
    // r�pido o objeto converge para a dire��o do alvo
    Vector target{Line::Angle(Point(x, y), Point(player->X(), player->Y())), 50.0f * gameTime};
    speed.Add(target);

    RotateTo(-speed.Angle() + 90);

    // limita a magnitude da velocidade para impedir
    // que ela cres�a indefinidamente pelo soma vetorial
    if (speed.Magnitude() > 4.5)
        speed.ScaleTo(4.5f);

    // move o objeto pelo seu vetor velocidade
    Translate(speed.XComponent() * 50.0f * gameTime, -speed.YComponent() * 50.0f * gameTime);

    // mant�m o objeto dentro do mundo do jogo
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