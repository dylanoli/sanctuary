#ifndef _ANIMAWALK_LADY_H_
#define _ANIMAWALK_LADY_H_

#include "Types.h" 
#include "Object.h"     
#include "Animation.h"      

enum PlayerState { STILL, WALK };
enum PlayerLookDirection { RIGHT, LEFT };
enum PlayerAnimState { STILL_RIGHT, STILL_LEFT, WALK_LEFT, WALK_RIGHT };


class Player : public Object
{
private:
    TileSet* walking;              
    Animation* anim;                   
    float speed;
    void HandleAnimState();

public:
    PlayerAnimState animState;
    PlayerState state;
    PlayerLookDirection lookDirection;

    Player();                             
    ~Player();                            

    void Update();                     
    void Draw();                       
};

inline void Player::Draw()
{
    anim->Draw(x, y, z);
}

#endif