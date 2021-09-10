#pragma once
#include "Object.h"
#include "Constants.h"
#include "TileSet.h"
#include "Animation.h"

class ArrowNextLevel : public Object
{
private:
    TileSet* tileSet;
    Animation* anim;
    Game* nextLevel;
public:
    ArrowNextLevel();
    ~ArrowNextLevel();
    void Update();
    void Draw();
    void OnCollision(Object* obj);
};

inline void ArrowNextLevel::Draw()
{
    anim->Draw(x, y, z);
}