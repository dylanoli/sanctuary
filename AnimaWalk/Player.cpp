#include "Player.h"
#include "BlasterPistol.h"

Player::Player(Scene* scene)
{
    type = T_PLAYER;
    walking = new TileSet("Resources/Walking.png", 55, 95, 8, 40);
    anim    = new Animation(walking, 0.060f, true);
    gun = new BlasterPistol(scene);
    Player::scene = scene;
    Player::scene->Add(gun, STATIC);

    uint SeqLeft[8]  = { 0, 1, 2, 3, 4, 5, 6, 7 };
    uint SeqRight[8] = { 15, 14, 13, 12, 11, 10, 9, 8 };
    uint SeqStillRight[1] = { 10 };
    uint SeqStillLeft[1] = { 5 };

    anim->Add(WALK_LEFT,  SeqLeft,  8);
    anim->Add(WALK_RIGHT, SeqRight, 8);
    anim->Add(STILL_RIGHT, SeqStillRight, 1);
    anim->Add(STILL_LEFT, SeqStillLeft, 1);

    state = STILL;
    speed = 300.0f;
    MoveTo(window->CenterX(), window->CenterY());
}

Player::~Player()
{
    delete anim;
    delete walking;
    delete gun;
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
        gun->SetDirection(LEFT);
        Translate(-speed * gameTime, 0);
    }

    // anda para direita
    if (window->KeyDown(VK_RIGHT))
    {
        state = WALK;
        lookDirection = RIGHT;
        gun->SetDirection(RIGHT);
        Translate(speed * gameTime, 0);
    }

    // se todas as teclas est�o liberadas, mude para o estado parado
    if (window->KeyUp(VK_UP) && window->KeyUp(VK_DOWN) && window->KeyUp(VK_LEFT) && window->KeyUp(VK_RIGHT))
    {
        state = STILL;
    }    

    HandleAnimState();

    gun->MoveTo(x, y);

    // mant�m personagem dentro da tela
    if (x + walking->TileWidth() / 2.0f > window->Width())
        MoveTo(window->Width() - walking->TileWidth() / 2.0f, y);

    if (x - walking->TileWidth() / 2.0f < 0)
        MoveTo(walking->TileWidth() / 2.0f, y);

    if (y + walking->TileHeight() / 2.0f > window->Height())
        MoveTo(x, window->Height() - walking->TileHeight() / 2.0f);

    if (y - walking->TileHeight() / 2.0f < 0)
        MoveTo(x, walking->TileHeight() / 2.0f);
}

void Player::HandleAnimState() {
    // atualiza anima��o
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
