#include "Obstacle.h"
#include "Sanctuary.h"

Obstacle::Obstacle(float posX, float posY, Scene *_scene)
{
	scene = _scene;
	const int MAX_VARY = 430;
	type = OBSTACULE;

	int varyX = 0;

	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<float> dist(1, 4);

	const int stoneId = dist(mt);

	string src;
	switch (stoneId)
	{
	case 1:
		src = "Resources/Stone1.png";
		break;
	case 2:
		src = "Resources/Stone2.png";
		break;
	case 3:
		src = "Resources/Stone3.png";
		break;
	case 4:
		src = "Resources/Stone4.png";
		break;
	default:
		break;
	}
	obstacle = new Sprite(src);

	BBox(new Circle(obstacle->Height() / 2.0f));

	MoveTo(posX, posY, Layer::MIDDLE);
}

// ---------------------------------------------------------------------------------

Obstacle::~Obstacle()
{
	delete obstacle;
}

// -------------------------------------------------------------------------------

void Obstacle::Update()
{
	if (x < -500)
		scene->Delete();

	float currentX = (200 + Sanctuary::player->Score()) * gameTime;
	Translate(-1 * currentX, 0);
}

// -------------------------------------------------------------------------------