#include "Bear.h"

float refBearSpeed = 120.0f;
int refBearLife = 100;
int refBearDamage = 15;
float refBearCooldown = 1.0f;

Bear::Bear(Player* player, Scene* scene, Spawn* spawn, float startPosX, float startPosY) : Enemy(player, scene, spawn, startPosX, startPosY, refBearSpeed, refBearLife, refBearDamage, refBearCooldown)
{
    BBox(new Rect(-70, -40, 60, 43));
    tileSet = new TileSet("Resources/Bear.png", 158, 135, 6, 36);
    anim = new Animation(tileSet, 0.10f, true);

    Image* imgHeart = new Image("Resources/Heart.png");

    for (int i = 0; i < 10; i++)
    {
        heartSprite[i] = new Sprite(imgHeart);
    }

    uint SeqLeft[6] = { 6, 7, 8, 9, 10, 11 };
    uint SeqRight[6] = { 17, 16, 15, 14, 13, 12 };
    uint SeqAtkRight[6] = { 29, 28, 27, 26, 25, 24 };
    uint SeqAtkLeft[6] = { 18, 19, 20, 21, 22, 23 };

    anim->Add(ENEMY_WALK_LEFT, SeqLeft, 6);
    anim->Add(ENEMY_WALK_RIGHT, SeqRight, 6);
    anim->Add(ENEMY_ATACK_RIGHT, SeqAtkRight, 6);
    anim->Add(ENEMY_ATACK_LEFT, SeqAtkLeft, 6);
}

Bear::~Bear()
{
    for (int i = 0; i < 10; i++)
        delete heartSprite[i];
}