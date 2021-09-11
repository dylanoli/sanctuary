#ifndef _ANIMAWALK_LADY_H_
#define _ANIMAWALK_LADY_H_

#include "Types.h" 
#include "Actor.h"     
#include "Animation.h"      
#include "Gun.h"  
#include "Scene.h"  
#include "Constants.h"
#include "Sprite.h"

enum PlayerState { STILL, WALK };
enum PlayerAnimState { STILL_RIGHT, STILL_LEFT, WALK_LEFT, WALK_RIGHT };

class Player : public Actor
{
private:
    Gun* gun = nullptr;
    Sprite *heartSprite[10];
    void HandleAnimState();

public:
    PlayerAnimState animState = STILL_RIGHT;
    PlayerState state = STILL;
    Direction lookDirection = RIGHT;

    Player(Scene * scene);                             
    ~Player();                            

    void Update();                     
    void Draw();            
    void OnCollision(Object* obj);
    void GetHit(int damage);
    bool IsDied();
};

inline void Player::Draw()
{
    anim->Draw(x, y, z);

    for (size_t i = 0; i < life; i++)
    {
        float posX = 15.0f + (28.0f * i);
        heartSprite[i]->Draw(posX, 15, Layer::UPPER);
    }
}

inline bool Player::IsDied() {
    return life <= 0;
}

#endif