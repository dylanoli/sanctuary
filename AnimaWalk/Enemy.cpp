#include "Enemy.h"
#include "Actor.h"
#include "BlasterPistol.h"
#include "Bullet.h"
#include <sstream>

using namespace std;

Enemy::Enemy(Player* player, Scene* scene) : Actor(scene)
{
    type = T_ENEMY;
    BBox(new Rect(-50, -13, 50, 43));
    Enemy::player = player;
    Enemy::scene = scene;
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

    state = ENEMY_WALK;    
    lookDirection = LEFT;
    speed = 200.0f;
    life = 10;
    damage = 1;
    MoveTo(window->Width(), window->CenterY());
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
    // controla a direcao do enemy
    const float posXPlayer = player->X();
    const float playerWidth = player->getTileSet()->TileWidth();
    
    if (x > posXPlayer + playerWidth) {
        lookDirection = RIGHT;
        state = ENEMY_WALK;
        Translate(-speed * gameTime, 0);
    }

    if (x < posXPlayer - playerWidth) {
        lookDirection = LEFT;
        state = ENEMY_WALK;
        Translate(speed * gameTime, 0);
    }
   

    //controle a vida do enemy
    if(life <= 0)
        scene->Delete(this, MOVING);

    HandleAnimState();

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

int Enemy::GetDamage()
{
    return damage;
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
        state = ENEMY_ATACK;
    }

    if (obj->Type() == T_BULLET)
        life -= ((Bullet*)obj)->GetDamage();
}
