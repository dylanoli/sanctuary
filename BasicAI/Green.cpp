/**********************************************************************************
// Green (Código Fonte)
// 
// Criação:     15 Out 2012
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz uma fuga suavizada
//
**********************************************************************************/

#include "Green.h"
#include "BasicAI.h"
#include "Random.h" 
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Green::Green(float pX, float pY, Player * p)
{
    player = p;
    sprite = new Sprite(BasicAI::green);
    BBox(new Circle(20.0f));
    speed.RotateTo(90.0f);
    MoveTo(pX, pY);
    type = GREEN;

    // mantém certa distância do jogador
    RandI dist{ 100, 400 };
    distance = dist.Rand();

    // incrementa contador
    ++Hud::greens;
}

// ---------------------------------------------------------------------------------

Green::~Green()
{
    delete sprite;

    // decrementa contador
    --Hud::greens;
}

// -------------------------------------------------------------------------------

void Green::OnCollision(Object * obj)
{
    if (obj->Type() == MISSILE)
    {
        BasicAI::scene->Delete(obj, STATIC);
        BasicAI::scene->Delete(this, MOVING);
        BasicAI::scene->Add(new Explosion(x, y), STATIC);
        BasicAI::audio->Play(EXPLODE);
    }
    else if (obj->Type() == GREEN) {
        Green* greenA = this;
        Green* greenB = static_cast<Green*>(obj);

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

void Green::Update()
{
    // a magnitude do vetor target controla quão rápido o objeto converge para a direção do alvo
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