#include "Obstacle.h"

Obstacle::Obstacle(float posX, float posY, uint platType, Color tint) : color(tint)
{
    obstacle = new Sprite("Resources/Stone4.png"); type = platType;

    BBox(new Rect(-obstacle->Width() / 2.0f,
        -obstacle->Height() / 2.0f,
        obstacle->Width() / 2.0f,
        obstacle->Height() / 2.0f));

    MoveTo(posX, posY, Layer::MIDDLE);
}

// ---------------------------------------------------------------------------------

Obstacle::~Obstacle()
{
    delete obstacle;
}

// -------------------------------------------------------------------------------

void Obstacle::Update()
{
    Translate(-200 * gameTime, 0);
}

// -------------------------------------------------------------------------------