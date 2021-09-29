#include "Object.h"
#include "Vector2.h"
#include "Animation.h"
#include "TileSet.h"

#ifndef MONSTER_H
#define MONSTER_H

enum MonsterState {
	IDLE, CHASING
};

class Monster : public Object {
private:
	int health;						// vida do monstro
	float playerDistance;			// distância do player
	bool isChasing;					// variável para controlar a animação e comportamento do monstro
	Animation* anim;				// objeto que guarda a animação do monstro		
	Vector2* direction;				// objeto que guarda a direção que o monstro está indo		

public:
	static TileSet* tiles;			// objeto com os tiles das animações usadas nos monstros
	Monster();
	~Monster();
	void Update();
	void Draw();
	void OnCollision(Object*);

};

#endif