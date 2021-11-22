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
#include "Aleatorio.h"
#include "Random.h"
#include "Hud.h"
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Aleatorio::Aleatorio(float pX, float pY, Player* p): magnitude(1, 4), angle(0, 359), secs(0.1f, 0.5f)
{
    player = p;
    sprite = new Sprite(BasicAI::aleatorio);
    BBox(new Circle(40.0f));
    speed.RotateTo(0.0f);
    speed.ScaleTo(0.0f);
    MoveTo(pX, pY);
    type = ALEATORIO;

    // incrementa contador
    ++Hud::aleatorios;
}

// ---------------------------------------------------------------------------------

Aleatorio::~Aleatorio()
{
    delete sprite;

    // decrementa contador
    --Hud::aleatorios;
}

// -------------------------------------------------------------------------------

void Aleatorio::OnCollision(Object* obj)
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
        Aleatorio* aleatorioA = this;
        Aleatorio* aleatorioB = static_cast<Aleatorio*>(obj);

        Point pA{ aleatorioA->X(), aleatorioA->Y() };
        Point pB{ aleatorioB->X(), aleatorioB->Y() };

        float angleA = Line::Angle(pA, pB);
        float angleB = angleA + 180.0f;

        if (angleB > 360)
            angleB -= 360.0f;

        Vector impactA{ angleA, 0.75f * aleatorioA->speed.Magnitude() };
        Vector impactB{ angleB, 0.75f * aleatorioB->speed.Magnitude() };

        aleatorioA->speed.Add(impactB);
        aleatorioB->speed.Add(impactA);

        if (aleatorioB->speed.Magnitude() > 15.0f)
            aleatorioB->speed.ScaleTo(15.0f);

        if (aleatorioA->speed.Magnitude() > 15.0f)
            aleatorioA->speed.ScaleTo(15.0f);
    }
}

// -------------------------------------------------------------------------------

void Aleatorio::NewDirection()
{
    // nova direção aleatória
    speed.Scale(magnitude.Rand());
    speed.Rotate(angle.Rand());

    // tempo aleatório
    delay = secs.Rand();

    // inicia medição do tempo
    timer.Start();
}

// -------------------------------------------------------------------------------

void Aleatorio::Update()
{
    // a magnitude do vetor 'target' controla qu�o
    // r�pido o objeto converge para a dire��o do alvo
    Vector target{ Line::Angle(Point(x, y), Point(player->X(), player->Y())), 50.0f * gameTime };
    speed.Add(target);

    if (timer.Elapsed(delay))
        NewDirection();

    Rotate(40 * gameTime);

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