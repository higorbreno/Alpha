#include "SpacedustCover.h"
#include "Alpha.h"

SpacedustCover::SpacedustCover()
{
	tiles = new TileSet("Resources/SpaceDustCoverSpriteSheet.png", 960, 640, 5, 5);
	anim = new Animation(tiles, 0.120f, true);
	timer = 0.0f;
	isVisible = false;
}

SpacedustCover::~SpacedustCover()
{
	delete anim;
	delete tiles;
}

// conta o tempo que a sujeira está visível e desabilita a visibilidade depois de um certo tempo
void SpacedustCover::Update()
{
	if(isVisible)
		timer += gameTime;

	if (timer >= 3.0f) {
		isVisible = false;
		timer = 0.0f;
	}

	anim->NextFrame();
}

void SpacedustCover::Draw()
{
	if(isVisible)
		anim->Draw(x + Alpha::scene->camera2d->X(), y + Alpha::scene->camera2d->Y(), Layer::FRONT);
}
