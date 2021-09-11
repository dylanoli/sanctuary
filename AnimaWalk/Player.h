#ifndef _ANIMAWALK_LADY_H_
#define _ANIMAWALK_LADY_H_

#include "Types.h" 
#include "Actor.h"     
#include "Animation.h"      
#include "Gun.h"  
#include "Scene.h"  
#include "Constants.h"

enum PlayerState { STILL, WALK };
enum PlayerAnimState { STILL_RIGHT, STILL_LEFT, WALK_LEFT, WALK_RIGHT };

class Player : public Actor
{
private:
    Gun* gun;
    void HandleAnimState();
    bool receivingDamage;

public:
    PlayerAnimState animState;
    PlayerState state;
    Direction lookDirection;

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
}

inline bool Player::IsDied() {
    return life <= 0;
}

#endif