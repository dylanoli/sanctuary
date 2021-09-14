#include "ArrowNextLevel.h"
const int DEFAULT = 0;

ArrowNextLevel::ArrowNextLevel()
{
	//ArrowNextLevel::nextLevel = nextLevel;
    tileSet = new TileSet("Resources/ArrowRight.png", 90, 90, 2, 2);
    BBox(new Rect(-45, -45, 45, 45));
    anim = new Animation(tileSet, 0.30f, true);

    uint Seq[2] = { 0, 1 };
    anim->Add(DEFAULT, Seq, 2);
}

ArrowNextLevel::~ArrowNextLevel()
{
    delete tileSet;
    delete anim;
}
void ArrowNextLevel::Update()
{
    anim->Select(DEFAULT);
    anim->NextFrame();
}
void ArrowNextLevel::OnCollision(Object* obj)
{
    if (obj->Type() == T_PLAYER)
    {
        canChangeLevel = true;
    }
}