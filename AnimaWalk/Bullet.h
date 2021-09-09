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
	int damage;
public:
	Bullet(int posX, int posY, Direction direction, float velocity, int damage, Image* imageRigh, Image* imageLeft, Scene* scene);
	~Bullet();
	void Update();
	void Draw();
	void OnCollision(Object* obj);

	int GetDamage();
};

inline int Bullet::GetDamage()
{ return damage; }