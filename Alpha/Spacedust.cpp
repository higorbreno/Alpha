#include "SpaceDust.h"
#include "Random.h"
#include "Alpha.h"
#include "SpacedustCover.h"

TileSet* Spacedust::tiles = nullptr;
const float spawnDistance = 200;

Spacedust::Spacedust()
{
	type = ObjTypes::SPACEDUST;
	if (!tiles)
		tiles = new TileSet("Resources/SpaceDustSpriteSheet.png", 128, 128, 10, 10);

	anim = new Animation(tiles, 0.120f, true);

	BBox(new Circle(32.0f));

	// move a poeira para uma posição a uma certa distância do player
	Random randX(int(Alpha::player->X()) - window->Width() / 2, int(Alpha::player->X()) + window->Width() / 2);
	Random randY(int(Alpha::player->Y()) - window->Height() / 2, int(Alpha::player->Y()) + window->Height() / 2);

	float playerDistance;

	do {
		MoveTo(float(randX.RandomInt()), float(randY.RandomInt()));

		float dx = Alpha::player->X() - x;
		float dy = Alpha::player->Y() - y;

		playerDistance = sqrt((dx * dx) + (dy * dy));
	} while (playerDistance < spawnDistance);

	// gera uma direção aleatória para a poeira
	Random randAng(-180, 180);
	direction = new Vector2(75, float(randAng.RandomInt()), TypeVector::POLAR);
}

Spacedust::~Spacedust()
{
	delete anim;
	delete direction;
}

void Spacedust::Update()
{
	Translate(direction->X() * gameTime, direction->Y() * gameTime);
	anim->NextFrame();
}

void Spacedust::Draw()
{
	anim->Draw(x, y);
}

