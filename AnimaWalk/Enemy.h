#pragma once
#include "Object.h"
#include "TileSet.h"
#include "Animation.h"
#include "Gun.h"
#include "Player.h"

enum EnemyState { ATACK, ENEMY_WALK };
enum EnemyAnimState { ENEMY_WALK_LEFT, ENEMY_WALK_RIGHT };

class Enemy : public Object
{
private:
    TileSet* tileSet;
    Animation* anim;
    Player* player;
    Scene* scene;
    float speed;
    int life;
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
