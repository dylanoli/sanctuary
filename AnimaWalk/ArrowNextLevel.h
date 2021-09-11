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
    bool canChangeLevel = false;
public:
    ArrowNextLevel();
    ~ArrowNextLevel();
    void Update();
    void Draw();
    void OnCollision(Object* obj);
    bool CanChangeLevel();
};

inline void ArrowNextLevel::Draw()
{
    anim->Draw(x, y, z);
}

inline bool ArrowNextLevel::CanChangeLevel()
{
    return canChangeLevel;
}