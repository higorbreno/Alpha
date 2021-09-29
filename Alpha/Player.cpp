#include "Player.h"
#include "Scene.h"
#include "Alpha.h"

const float velocity = 200;

Player::Player()
{
	type = ObjTypes::PLAYER;
	tiles = new TileSet("Resources/PlayerSpriteSheet.png", 64, 64, 10, 10);
	anim = new Animation(tiles, 0.120f, true);
	health = 100;

	BBox(new Circle(32.0f));
}

Player::~Player()
{
	delete anim;
	delete tiles;
}

// cuida da movimentação do player
void Player::Update()
{
	if (window->KeyDown(VK_RIGHT) || window->KeyDown('D'))
		Translate(velocity * gameTime, 0);

	if (window->KeyDown(VK_LEFT) || window->KeyDown('A'))
		Translate(-velocity * gameTime, 0);

	if (window->KeyDown(VK_UP) || window->KeyDown('W'))
		Translate(0, -velocity * gameTime);

	if (window->KeyDown(VK_DOWN) || window->KeyDown('S'))
		Translate(0, velocity * gameTime);

	// move a câmera para seguir sempre o player
	Scene::camera2d->MoveTo(x - window->CenterX(), y - window->CenterY());

	anim->NextFrame();
}

void Player::Draw()
{
	anim->Draw(x, y, Layer::UPPER);
}

void Player::OnCollision(Object* obj) {
	// se colidir com monstro, diminui vida e destrói o monstro
	if (obj->Type() == ObjTypes::MONSTER) {
		health -= 20;
		Alpha::scene->Delete(obj, MOVING);
	}
	// se colidir com poeira, suja a tela e destrói a poeira
	else if (obj->Type() == ObjTypes::SPACEDUST) {
		Alpha::cover->SetVisibility(true);
		Alpha::scene->Delete(obj, MOVING);
	}
}
