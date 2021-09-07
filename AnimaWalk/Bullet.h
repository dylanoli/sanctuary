#pragma once
#include "Object.h";
#include "Constants.h";
#include "Sprite.h";
#include "Image.h";
#include "Scene.h";
class Bullet :public Object 
{
private:
	Direction direction;
	float velocity;
	Sprite* sprite;
	Scene* scene;
public:
	Bullet(int posX, int posY, Direction direction, float velocity, Image* imageRigh, Image* imageLeft, Scene* scene);
	~Bullet();
	void Object::Update();
	void Object::Draw();
};