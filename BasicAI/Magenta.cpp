/**********************************************************************************
// Magenta (Código Fonte)
// 
// Criação:     10 Out 2012
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz um perseguição direta
//
**********************************************************************************/

#include "BasicAI.h"
#include "Magenta.h"
#include "Random.h" 
#include "Hud.h"
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Magenta::Magenta(float pX, float pY, Player * p)
{
    player = p;
    sprite = new Sprite(BasicAI::magenta);
    BBox(new Circle(18.0f));
    
    speed.RotateTo(90);
    speed.ScaleTo(2.0f);
    
    MoveTo(pX, pY);
    type = MAGENTA;

    // incrementa contador
    ++Hud::magentas;
}

// ---------------------------------------------------------------------------------

Magenta::~Magenta()
{
    delete sprite;

    // decrementa contador
    --Hud::magentas;
}

// -------------------------------------------------------------------------------

void Magenta::OnCollision(Object * obj)
{
    if (obj->Type() == MISSILE)
    {
        BasicAI::scene->Delete(obj, STATIC);
        BasicAI::scene->Delete(this, MOVING);
        BasicAI::scene->Add(new Explosion(x, y), STATIC);
        BasicAI::audio->Play(EXPLODE);
    }
    else if (obj->Type() == MAGENTA) {
        Magenta* greenA = this;
        Magenta* greenB = static_cast<Magenta*>(obj);

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

void Magenta::Update()
{
    // ajusta ângulo do vetor 
    speed.RotateTo(Line::Angle(Point(x, y), Point(player->X(), player->Y())));
    
    RotateTo(-speed.Angle() + 90);

    // movimenta objeto pelo seu vetor velocidade
    Translate(speed.XComponent() * 60.0f * gameTime, -speed.YComponent() * 60.0f * gameTime);
}

// -------------------------------------------------------------------------------