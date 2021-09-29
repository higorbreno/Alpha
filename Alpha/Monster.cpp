#include <cmath>
#include "Monster.h"
#include "Random.h"
#include "Alpha.h"

TileSet* Monster::tiles = nullptr;
const float spawnDistance = 200;
const float triggerDistance = 300;

Monster::Monster()
{
	type = ObjTypes::MONSTER;
	if (!tiles)
		tiles = new TileSet("Resources/MonsterSpriteSheet.png", 128, 128, 10, 20);

	anim = new Animation(tiles, 0.120f, true);

	uint seqIdle[10] = { 0,1,2,3,4,5,6,7,8,9 };
	uint seqChasing[10] = { 10,11,12,13,14,15,16,17,18,19 };

	anim->Add(MonsterState::CHASING, seqChasing, 10);
	anim->Add(MonsterState::IDLE, seqIdle, 10);

	health = 100;
	isChasing = false;

	BBox(new Circle(32.0f));

	// move o monstro para uma posição aleatória a uma certa distância do player
	Random randX(int(Alpha::player->X()) - window->Width() / 2, int(Alpha::player->X()) + window->Width() / 2);
	Random randY(int(Alpha::player->Y()) - window->Height() / 2, int(Alpha::player->Y()) + window->Height() / 2);

	do {
		MoveTo(float(randX.RandomInt()), float(randY.RandomInt()));

		float dx = Alpha::player->X() - x;
		float dy = Alpha::player->Y() - y;

		playerDistance = sqrt((dx * dx) + (dy * dy));
	} while (playerDistance < spawnDistance);

	// gera uma direção aleatória para o monstro andar até ser ativado seu modo de perseguição
	Random randAng(-180, 180);
	direction = new Vector2(75, float(randAng.RandomInt()), TypeVector::POLAR);
}

Monster::~Monster()
{
	delete anim;
	delete direction;
}

void Monster::Update()
{
	Translate(direction->X() * gameTime, direction->Y() * gameTime);

	float dx = Alpha::player->X() - x;
	float dy = Alpha::player->Y() - y;

	playerDistance = sqrt((dx * dx) + (dy * dy));

	// ativa modo de perseguição, monstro começará a seguir player
	if (isChasing || playerDistance < triggerDistance) {
		isChasing = true;
		direction->SetCartesian(dx, dy);
		float angle = direction->Angle();
		direction->SetPolar(200, angle);
	}

	// deleta monstro se vida for menor que 0
	if (health <= 0) {
		Alpha::score++;
		Alpha::scene->Delete();
	}

	// deleta monstro se tiver a uma distância muito grande do player e não tiver o perseguindo
	if ((playerDistance > 5000 && !isChasing)) {
		Alpha::scene->Delete();
	}

	if (isChasing)
		anim->Select(MonsterState::CHASING);
	else
		anim->Select(MonsterState::IDLE);
	anim->NextFrame();
}

void Monster::Draw()
{
	anim->Draw(x, y);
}

void Monster::OnCollision(Object* obj) {
	// perde vida e destrói a bala caso seja atingido
	if (obj->Type() == ObjTypes::BULLET) {
		health -= 40;
		Alpha::scene->Delete(obj, MOVING);
	}
}
