#ifndef _ANIMAWALK_LADY_H_
#define _ANIMAWALK_LADY_H_

#include "Types.h" 
#include "Object.h"     
#include "Animation.h"      
#include "Gun.h"  
#include "Scene.h"  
#include "Constants.h"

enum PlayerState { STILL, WALK };
enum PlayerAnimState { STILL_RIGHT, STILL_LEFT, WALK_LEFT, WALK_RIGHT };


class Player : public Object
{
private:
    TileSet* walking;              
    Animation* anim;
    Scene* scene;
    Gun* gun;
    float speed;
    void HandleAnimState();

public:
    PlayerAnimState animState;
    PlayerState state;
    Direction lookDirection;

    Player(Scene * scene);                             
    ~Player();                            

    void Update();                     
    void Draw();                       
};

inline void Player::Draw()
{
    anim->Draw(x, y, z);
}

#endif