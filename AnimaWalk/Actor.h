#ifndef _SANCTUARY_ACTOR_H_
#define _SANCTUARY_ACTOR_H_

#include "Object.h"
#include "TileSet.h"
#include "Animation.h"
#include "Scene.h"

class Actor : public Object
{
protected:
    TileSet* tileSet;
    Animation* anim;
    Scene* scene;
    float speed;
    int life;

public:
    Actor(Scene* scene, float speed, int life);
    ~Actor();

    void Update();
    void Draw();
    void OnCollision(Object* obj);
    void HandleAnimState();
    TileSet* getTileSet();
};

inline void Actor::Draw()
{
    anim->Draw(x, y, z);
}

inline Actor::Actor(Scene* scene, float speed, int life) {
    Actor::scene = scene;
    Actor::speed = speed;
    Actor::life = life;
}

inline Actor::~Actor() {
    delete anim;
    delete tileSet;
}

inline void Actor::Update() {

}

inline void Actor::OnCollision(Object* obj) {

}

inline void Actor::HandleAnimState() {

}

inline TileSet* Actor::getTileSet() {
    return tileSet;
}

#endif