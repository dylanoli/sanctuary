#include "Bullet.h"

Bullet::Bullet(int posX, int posY, Direction direction, float velocity, int damage, Image* imageRigh, Image* imageLeft, Scene* scene)
{
	type = T_BULLET;
	BBox(new Rect(-12, -5, 12, 5));
	MoveTo(posX, posY);
	Bullet::direction = direction;
	Bullet::velocity = velocity;
	Bullet::damage = damage;
	Bullet::scene = scene;
	direction == RIGHT
		? Bullet::sprite = new Sprite(imageRigh)
		: Bullet::sprite = new Sprite(imageLeft);
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	direction == RIGHT
		? MoveTo(x + (velocity * gameTime), y)
		: MoveTo(x - (velocity * gameTime), y);	

	// se remove quando sai da tela
	if (x + sprite->Width() / 2.0f > window->Width())
		scene->Delete();

	if (x - sprite->Width() / 2.0f < 0)
		scene->Delete();

	if (y + sprite->Height() / 2.0f > window->Height())
		scene->Delete();

	if (y - sprite->Height() / 2.0f < 0)
		scene->Delete();
}

void Bullet::Draw()
{
	sprite->Draw(x,y);
}

void Bullet::OnCollision(Object* obj)
{
	if (obj->Type() == T_ENEMY)
		scene->Delete(this, MOVING);
}