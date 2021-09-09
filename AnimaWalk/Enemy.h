#pragma once
#include "Actor.h"
#include "TileSet.h"
#include "Animation.h"
#include "Gun.h"
#include "Player.h"

enum EnemyState { ENEMY_ATACK, ENEMY_WALK };
enum EnemyAnimState { ENEMY_WALK_LEFT, ENEMY_WALK_RIGHT, ENEMY_ATACK_RIGHT, ENEMY_ATACK_LEFT};

class Enemy : public Actor
{
private:
    Player* player;    
    void HandleAnimState();

public:
    EnemyAnimState animState;
    EnemyState state;
    Direction lookDirection;

    Enemy(Player* player, Scene* scene);
    ~Enemy();

    void Update();
    void Draw();
    void OnCollision(Object* obj);
};

inline void Enemy::Draw()
{
    anim->Draw(x, y, z);
}
