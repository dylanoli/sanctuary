#include "Snake.h"


const float refSnakeSpeed = 310.0f;
const float refSnakeCooldown = 0.3f;
const int refSnakeLife = 6;
const int refSnakeDamage = 1;

Snake::Snake(Player* player, Scene* scene) : Enemy(player, scene, refSnakeSpeed, refSnakeLife, refSnakeDamage, refSnakeCooldown)
{
    BBox(new Rect(-40, -20, 40, 30));
    tileSet = new TileSet("Resources/Snake.png", 100, 60, 3, 6);
    anim = new Animation(tileSet, 0.10f, true);

    uint SeqRight[3] = { 0 , 1, 2 };
    uint SeqLeft[3] = { 3, 4, 5 };
    uint SeqAtkRight[2] = { 0, 2 };
    uint SeqAtkLeft[2] = { 3, 5 };

    anim->Add(ENEMY_WALK_LEFT, SeqLeft, 3);
    anim->Add(ENEMY_WALK_RIGHT, SeqRight, 3);
    anim->Add(ENEMY_ATACK_RIGHT, SeqAtkRight, 2);
    anim->Add(ENEMY_ATACK_LEFT, SeqAtkLeft, 2);
}

Snake::~Snake()
{

}