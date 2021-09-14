#include "Lince.h"

float refSpeed = 140.0f;
int refLife = 10;
int refDamage = 4;
float refCooldown = 0.3f;

Lince::Lince(Player* player, Scene* scene, Spawn* spawn, float startPosX, float startPosY) : Enemy(player, scene, spawn, startPosX, startPosY, refSpeed, refLife, refDamage, refCooldown)
{
    BBox(new Rect(-50, -13, 50, 43));
    tileSet = new TileSet("Resources/Lince.png", 110, 90, 6, 30);
    anim = new Animation(tileSet, 0.10f, true);

    uint SeqLeft[5] = { 1, 2, 3, 4, 5 };
    uint SeqRight[5] = { 6, 7, 8, 9, 10 };
    uint SeqAtkRight[3] = { 20, 21, 22 };
    uint SeqAtkLeft[3] = { 16, 17 , 18 };

    anim->Add(ENEMY_WALK_LEFT, SeqLeft, 5);
    anim->Add(ENEMY_WALK_RIGHT, SeqRight, 5);
    anim->Add(ENEMY_ATACK_RIGHT, SeqAtkRight, 3);
    anim->Add(ENEMY_ATACK_LEFT, SeqAtkLeft, 3);
}

Lince::~Lince() 
{

}