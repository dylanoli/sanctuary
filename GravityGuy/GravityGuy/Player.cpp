#include "Actor.h"
#include "Player.h"
#include <iostream>

float refPlayerSpeed = 300.0f;
int refPlayerLife = 50;

Player::Player(Scene* scene) : Actor(scene, refPlayerSpeed, refPlayerLife)
{
    type = T_PLAYER;
    tileSet = new TileSet("Resources/astronner.png", 126, 126, 4, 13);
    BBox(new Rect(-20, -50, 20, 50));
    anim = new Animation(tileSet, 0.21f, true);
    
    uint SeqLeft[4] = { 9, 10, 11, 12 };
    uint SeqRight[4] = { 3, 4, 5, 6 };
    uint SeqStillRight[1] = { 1 };
    uint SeqStillLeft[1] = { 7 };

    anim->Add(WALK_LEFT, SeqLeft, 4);
    anim->Add(WALK_RIGHT, SeqRight, 4);
    anim->Add(STILL_RIGHT, SeqStillRight, 1);
    anim->Add(STILL_LEFT, SeqStillLeft, 1);

    state = STILL;

    Image* imgHeart = new Image("Resources/Heart.png");

    for (int i = 0; i < 10; i++)
    {
        heartSprite[i] = new Sprite(imgHeart);
    }

    MoveTo(window->CenterX() - 420, window->CenterY());
}

Player::~Player()
{
    for (int i = 0; i < 10; i++)
        delete heartSprite[i];
}

void Player::Update()
{
    // anda para cima
    if (window->KeyDown(VK_UP))
    {
        Translate(0, -speed * gameTime);
        state = WALK;
    }

    // anda para baixo
    if (window->KeyDown(VK_DOWN))
    {
        Translate(0, speed * gameTime);
        state = WALK;
    }

    // anda para esquerda
    if (window->KeyDown(VK_LEFT))
    {
        state = WALK;
        lookDirection = LEFT;
        Translate(-speed * gameTime, 0);
    }

    // anda para direita
    if (window->KeyDown(VK_RIGHT))
    {
        state = WALK;
        lookDirection = RIGHT;
        Translate(speed * gameTime, 0);
    }

    // se todas as teclas estão liberadas, mude para o estado parado
    if (window->KeyUp(VK_UP) && window->KeyUp(VK_DOWN) && window->KeyUp(VK_LEFT) && window->KeyUp(VK_RIGHT))
    {
        state = STILL;
    }

    if (window->KeyDown('G'))
        godModeOn = !godModeOn;

    HandleAnimState();

    // mantém personagem dentro da tela
    if (x + tileSet->TileWidth() / 2.0f > window->Width())
        MoveTo(window->Width() - tileSet->TileWidth() / 2.0f, y);

    if (x - tileSet->TileWidth() / 2.0f < 0)
        MoveTo(tileSet->TileWidth() / 2.0f, y);

    //bloqueio da arvore
    if ((y + tileSet->TileHeight() / 2.0f) > window->Height())
        MoveTo(x, window->Height() - tileSet->TileHeight() / 2.0f);

    std::cout << y;
    if ((y - tileSet->TileHeight() / 2.0f) < (250 - tileSet->TileHeight() / 2.0f))
        MoveTo(x, 250);

}

void Player::GetHit(int damage)
{
    if (!godModeOn)
        life -= damage;
}

void Player::HandleAnimState() {
    // atualiza animação
    if (state == STILL && lookDirection == RIGHT)
        animState = STILL_RIGHT;
    if (state == STILL && lookDirection == LEFT)
        animState = STILL_LEFT;

    if (state == WALK && lookDirection == RIGHT)
        animState = WALK_RIGHT;
    if (state == WALK && lookDirection == LEFT)
        animState = WALK_LEFT;

    anim->Select(animState);
    anim->NextFrame();
}

void Player::OnCollision(Object* obj)
{
}
