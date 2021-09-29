#include "Object.h"
#include "Animation.h"
#include "TileSet.h"

#ifndef PLAYER_H
#define	PLAYER_H

class Player : public Object {
private:
	int health;					// vida do player
	TileSet* tiles;				// tiles da anima��o do player
	Animation* anim;			// anima��o do player

public:
	Player();
	~Player();
	int Health();
	void Update();
	void Draw();
	void OnCollision(Object*);

};

// m�todo que retorna a vida do player
inline int Player::Health()
{ return health; }

#endif // ! PLAYER_H
