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
    int damage;
    float cooldown;
    bool canAtack = false;
    float currentCooldown = 0;
    void HandleAnimState();

public:
    EnemyAnimState animState;
    EnemyState state;
    Direction lookDirection;

    Enemy(Player* player, Scene* scene, float speed, int life, int damage, float cooldown);
    ~Enemy();

    void OnCollision(Object* obj);
    void Update();
    void Draw();

    void Atack();
    void HandleAtack();
    bool EndCooldown();
};

inline void Enemy::Draw()
{
    anim->Draw(x, y, z);
}

inline bool Enemy::EndCooldown()
{
    return currentCooldown >= cooldown;
}
