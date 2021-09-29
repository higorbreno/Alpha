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
	float playerDistance;			// dist�ncia do player
	bool isChasing;					// vari�vel para controlar a anima��o e comportamento do monstro
	Animation* anim;				// objeto que guarda a anima��o do monstro		
	Vector2* direction;				// objeto que guarda a dire��o que o monstro est� indo		

public:
	static TileSet* tiles;			// objeto com os tiles das anima��es usadas nos monstros
	Monster();
	~Monster();
	void Update();
	void Draw();
	void OnCollision(Object*);

};

#endif