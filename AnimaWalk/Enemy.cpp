#include "Enemy.h"
#include "BlasterPistol.h"
#include "Bullet.h"

Enemy::Enemy(Player * player, Scene* scene)
{
    type = T_ENEMY;
    BBox(new Rect(-50, -13, 50, 43));
    Enemy::player = player;
    Enemy::scene = scene;
    tileSet = new TileSet("Resources/Lince.png", 110, 90, 6, 30);
    anim = new Animation(tileSet, 0.10f, true);

    uint SeqLeft[5] = { 1, 2, 3, 4, 5 };
    uint SeqRight[5] = {6, 7, 8, 9, 10 };

    anim->Add(ENEMY_WALK_LEFT, SeqLeft, 5);
    anim->Add(ENEMY_WALK_RIGHT, SeqRight, 5);

    state = ENEMY_WALK; 
    lookDirection = LEFT;
    speed = 200.0f;
    life = 10;
    MoveTo(window->CenterX()-100, window->CenterY());
}

Enemy::~Enemy()
{
    delete tileSet;
    delete anim;
}

void Enemy::Update()
{
    // controla a direcao do enemy
    const float posXPlayer = player->X();
    if ((posXPlayer - x) > 0)
        lookDirection = LEFT;
    else
        lookDirection = RIGHT;

    //controle a vida do enemy
    if(life <= 0)
        scene->Delete(this, MOVING);

    HandleAnimState();

    // mant�m personagem dentro da tela
    if (x + tileSet->TileWidth() / 2.0f > window->Width())
        MoveTo(window->Width() - tileSet->TileWidth() / 2.0f, y);

    if (x - tileSet->TileWidth() / 2.0f < 0)
        MoveTo(tileSet->TileWidth() / 2.0f, y);

    if (y + tileSet->TileHeight() / 2.0f > window->Height())
        MoveTo(x, window->Height() - tileSet->TileHeight() / 2.0f);

    if (y - tileSet->TileHeight() / 2.0f < 0)
        MoveTo(x, tileSet->TileHeight() / 2.0f);
}

void Enemy::HandleAnimState() {
    // atualiza anima��o
    if (state == ENEMY_WALK && lookDirection == RIGHT)
        animState = ENEMY_WALK_RIGHT;
    if (state == ENEMY_WALK && lookDirection == LEFT)
        animState = ENEMY_WALK_LEFT;

    anim->Select(animState);
    anim->NextFrame();
}

void Enemy::OnCollision(Object* obj)
{
    if (obj->Type() == T_BULLET)
        life -= ((Bullet*)obj)->GetDamage();
}
