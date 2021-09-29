#include "Bullet.h"
#include "Alpha.h"

Image* Bullet::image = nullptr;

Bullet::Bullet(float x, float y, Vector2* direction)
{
	type = ObjTypes::BULLET;
	if (!image)
		image = new Image("Resources/Bullet.png");

	this->direction = direction;

	sprite = new Sprite(image);

	BBox(new Circle(8.0f));

	MoveTo(x, y);
}

Bullet::~Bullet()
{
	delete sprite;
	delete direction;
}

void Bullet::Update()
{
	Translate(direction->X() * gameTime, direction->Y() * gameTime);

	float dx = Alpha::player->X() - x;
	float dy = Alpha::player->Y() - y;

	float playerDistance = sqrt((dx * dx) + (dy * dy));

	// deleta a bala caso esteja muito longe do player
	if (playerDistance > 1000)
		Alpha::scene->Delete();
}

void Bullet::Draw()
{
	sprite->Draw(x, y);
}

