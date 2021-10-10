#ifndef _SANCTUARY_PLAYER_H_
#define _SANCTUARY_PLAYER_H_

#include "Types.h" 
#include "Actor.h"     
#include "Animation.h"      
#include "Scene.h"  
#include "Constants.h"
#include "Sprite.h"

enum PlayerState { STILL, WALK };
enum PlayerAnimState { STILL_RIGHT, STILL_LEFT, WALK_LEFT, WALK_RIGHT };

class Player : public Actor
{
private:
    Sprite* heartSprite[10];
    void HandleAnimState();
    bool godModeOn = false;

public:
    PlayerAnimState animState = STILL_RIGHT;
    PlayerState state = STILL;
    Direction lookDirection = RIGHT;

    Player(Scene* scene);
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

    const float countHeartFloat = 10 * ((life * 1.0f) / maxLife);
    const int countHeartInt = (int)countHeartFloat;
    const int countHeart = countHeartFloat > countHeartInt ? countHeartInt + 1 : countHeartInt;

    for (size_t i = 0; i < countHeart; i++)
    {
        float posX = 15.0f + (28.0f * i);
        heartSprite[i]->Draw(posX, 15, Layer::UPPER);
    }
}

inline bool Player::IsDied() {
    return life <= 0;
}

#endif