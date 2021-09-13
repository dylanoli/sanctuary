#include "Enemy.h"
#include "Actor.h"
#include "BlasterPistol.h"
#include "Bullet.h"

Enemy::Enemy(
    Player* player, 
    Scene* scene, 
    Spawn* spawn, 
    float startPosX, 
    float startPosY, 
    float speed, 
    int life, 
    int damage, 
    float cooldown
) : Actor(scene, speed, life)
{
    type = T_ENEMY;
    Enemy::player = player;
    Enemy::scene = scene;
    Enemy::spawn = spawn;

    state = ENEMY_WALK;    
    lookDirection = LEFT;
    Enemy::currentCooldown = cooldown;
    Enemy::cooldown = cooldown;
    Enemy::damage = damage;
    MoveTo(startPosX, startPosY);
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
    // controla a direcao do enemy
    const float posXPlayer = player->X();
    const float playerWidth = player->getTileSet()->TileWidth() / 2;
    
    if (x > posXPlayer + playerWidth && EndCooldown()) {
        lookDirection = RIGHT;
        state = ENEMY_WALK;
        Translate(-speed * gameTime, 0);
    }

    if (x < posXPlayer - playerWidth && EndCooldown()) {
        lookDirection = LEFT;
        state = ENEMY_WALK;
        Translate(speed * gameTime, 0);
    }
   
    const float posYPlayer = player->Y();
    const float playerHeight = player->getTileSet()->TileHeight() / 8.0f;
    if (y > posYPlayer + playerHeight && EndCooldown()) {
        Translate(0, -speed * gameTime);
    }

    if (y < posYPlayer - playerHeight && EndCooldown()) {
        Translate(0, speed * gameTime);
    }

    //controle a vida do enemy
    if (life <= 0) {
        spawn->IncrementEnemieDied();
        scene->Delete(this, MOVING);
    }


    HandleAnimState();
    HandleAtack();

    // mantém personagem dentro da tela
    if (x + tileSet->TileWidth() / 2.0f > window->Width())
        MoveTo(window->Width() - tileSet->TileWidth() / 2.0f, y);

    if (x - tileSet->TileWidth() / 2.0f < 0)
        MoveTo(tileSet->TileWidth() / 2.0f, y);

    if (y + tileSet->TileHeight() / 2.0f > window->Height())
        MoveTo(x, window->Height() - tileSet->TileHeight() / 2.0f);

    if (y - tileSet->TileHeight() / 2.0f < 0)
        MoveTo(x, tileSet->TileHeight() / 2.0f);
}

void Enemy::Atack()
{
    player->GetHit(damage);
    canAtack = false;
    currentCooldown = 0;
    state = ENEMY_ATACK;
}

void Enemy::HandleAtack()
{
    if (!canAtack)
        currentCooldown += gameTime;
    else
        Atack();
}

void Enemy::HandleAnimState() {
    // movimento
    if (state == ENEMY_WALK && lookDirection == RIGHT)
        animState = ENEMY_WALK_RIGHT;
    if (state == ENEMY_WALK && lookDirection == LEFT)
        animState = ENEMY_WALK_LEFT;

    // ataque
    if (state == ENEMY_ATACK && lookDirection == RIGHT)
        animState = ENEMY_ATACK_RIGHT;
    if (state == ENEMY_ATACK && lookDirection == LEFT)
        animState = ENEMY_ATACK_LEFT;

    anim->Select(animState);
    anim->NextFrame();
}

void Enemy::OnCollision(Object* obj)
{
    if (obj->Type() == T_PLAYER) {
        if (EndCooldown() && !canAtack)
        {
            canAtack = true;
        }
    }

    if (obj->Type() == T_BULLET)
        life -= ((Bullet*)obj)->GetDamage();
}
