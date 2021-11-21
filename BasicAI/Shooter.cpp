/**********************************************************************************
// Shooter (C�digo Fonte)
// 
// Cria��o:     15 Out 2012
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz uma fuga suavizada
//
**********************************************************************************/

#include "Shooter.h"
#include "BasicAI.h"
#include "Random.h"
#include "Explosion.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

Shooter::Shooter(float pX, float pY, Player *p)
{
    player = p;
    sprite = new Sprite(BasicAI::shooter);
    BBox(new Circle(40.0f));
    speed.RotateTo(90.0f);
    MoveTo(pX, pY);
    type = SHOOTER;

    // mant�m certa dist�ncia do jogador
    RandI dist{100, 400};
    distance = dist.Rand();

    // incrementa contador
    ++Hud::shooters;
}

// ---------------------------------------------------------------------------------

Shooter::~Shooter()
{
    delete sprite;

    // decrementa contador
    --Hud::shooters;
}

// -------------------------------------------------------------------------------

void Shooter::OnCollision(Object *obj)
{
    if (obj->Type() == MISSILE || obj->Type() == PLAYER)
    {
        if (obj->Type() == MISSILE)
        {
            Player::score += 10;
            BasicAI::scene->Delete(obj, STATIC);
        }
        BasicAI::scene->Delete(this, MOVING);
        BasicAI::scene->Add(new Explosion(x, y), STATIC);
        BasicAI::audio->Play(EXPLODE);
    }
    else if (obj->Type() == SHOOTER)
    {
        Shooter *shooterA = this;
        Shooter *shooterB = static_cast<Shooter *>(obj);

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

void Shooter::Update()
{
    // a magnitude do vetor target controla qu�o r�pido o objeto converge para a dire��o do alvo
    Vector target = Vector(Line::Angle(Point(x, y), Point(player->X(), player->Y())), 20.0f * gameTime);

    // fugir se o player chegar muito perto
    if (Point::Distance(Point(x, y), Point(player->X(), player->Y())) < distance)
    {
        target.Rotate(180.0f);
        target.ScaleTo(100.0f * gameTime);
    }

    speed.Add(target);

    // limita a magnitude da velocidade para impedir
    // seu crescimento indefinido na soma vetorial
    if (speed.Magnitude() > 8)
        speed.ScaleTo(8.0f);

    // move o objeto pelo seu vetor velocidade
    Translate(speed.XComponent() * 50.0f * gameTime, -speed.YComponent() * 50.0f * gameTime);
    RotateTo(-speed.Angle() + 90);

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